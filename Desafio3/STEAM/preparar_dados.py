import csv
from pathlib import Path

import pandas as pd


# CONFIGURAÇÃO
ENTRADA = Path("dados/games.csv")
SAIDA = Path("dados/games_limpo.csv")
MIN_AVALIACOES = 50

COLUNAS = [
    "AppID",
    "Name",
    "Release date",
    "Required age",
    "Supported languages",
    "Full audio languages",
    "Windows",
    "Mac",
    "Linux",
    "Developers",
    "Publishers",
    "Categories",
    "Genres",
    "Positive",
    "Negative",
]


# 1. CORRIGIR O CABEÇALHO DURANTE A LEITURA
with ENTRADA.open(encoding="utf-8-sig", newline="") as arquivo:
    cabecalho = next(csv.reader(arquivo))

if "DiscountDLC count" in cabecalho:
    posicao = cabecalho.index("DiscountDLC count")
    cabecalho[posicao:posicao + 1] = ["Discount", "DLC count"]

faltantes = set(COLUNAS) - set(cabecalho)

if faltantes:
    raise ValueError(f"Colunas obrigatórias ausentes: {sorted(faltantes)}")

# Verifica a estrutura antes de selecionar as colunas.
with ENTRADA.open(encoding="utf-8-sig", newline="") as arquivo:
    leitor = csv.reader(arquivo)
    next(leitor)

    for numero, linha in enumerate(leitor, start=2):
        if len(linha) != len(cabecalho):
            raise ValueError(
                f"Registro {numero}: {len(linha)} campos; "
                f"esperados {len(cabecalho)}."
            )

# Lê como texto para controlar explicitamente as conversões.
df = pd.read_csv(
    ENTRADA,
    header=0,
    names=cabecalho,
    usecols=COLUNAS,
    dtype="string",
    encoding="utf-8-sig",
)

df = df[COLUNAS].copy()
total_original = len(df)

print(f"Registros originais: {total_original:,}")


# Função para filtrar e registrar quantos jogos foram removidos.
def filtrar(dados, condicao, motivo):
    resultado = dados.loc[condicao.fillna(False)].copy()
    print(
        f"{motivo}: removidos {len(dados) - len(resultado):,}; "
        f"restantes {len(resultado):,}"
    )
    return resultado


# 2. NORMALIZAR CAMPOS VAZIOS
for coluna in COLUNAS:
    df[coluna] = df[coluna].str.strip()

    vazio = df[coluna].str.lower().isin(
        ["", "[]", "{}", "nan", "none", "null", "unknown"]
    )
    df.loc[vazio, coluna] = pd.NA


# 3. VALIDAR IDENTIFICAÇÃO
df["AppID"] = pd.to_numeric(df["AppID"], errors="coerce")

id_valido = (
    df["AppID"].notna()
    & df["AppID"].gt(0)
    & df["AppID"].mod(1).eq(0)
)

df = filtrar(
    df,
    id_valido & df["Name"].notna(),
    "Identificação ausente ou inválida",
)

df["AppID"] = df["AppID"].astype("int64")

# Remove cópias idênticas nas colunas selecionadas.
antes = len(df)
df = df.drop_duplicates().copy()
print(f"Duplicatas idênticas removidas: {antes - len(df):,}")

# Se o mesmo ID tiver dados diferentes, exige revisão.
conflitos = df["AppID"].duplicated(keep=False)

if conflitos.any():
    caminho_conflitos = ENTRADA.parent / "games_ids_conflitantes.csv"
    df.loc[conflitos].to_csv(
        caminho_conflitos, index=False, encoding="utf-8-sig"
    )
    raise ValueError(
        "Existem registros diferentes para o mesmo AppID. "
        f"Revise: {caminho_conflitos}"
    )


# 4. REMOVER PLAYTESTS IDENTIFICÁVEIS PELO NOME
# É uma heurística: o nome não substitui uma classificação oficial.
playtest = df["Name"].str.contains(
    r"\bplaytest\b", case=False, regex=True, na=False
)

df = filtrar(df, ~playtest, "Playtests identificados pelo nome")


# 5. VALIDAR CONTAGENS DE AVALIAÇÕES
for coluna in ["Positive", "Negative"]:
    df[coluna] = pd.to_numeric(df[coluna], errors="coerce")

contagens_validas = pd.Series(True, index=df.index)

for coluna in ["Positive", "Negative"]:
    contagens_validas &= (
        df[coluna].notna()
        & df[coluna].ge(0)
        & df[coluna].mod(1).eq(0)
    )

df = filtrar(
    df,
    contagens_validas,
    "Contagens de avaliações ausentes ou inválidas",
)

df[["Positive", "Negative"]] = (
    df[["Positive", "Negative"]].astype("int64")
)


# 6. CONVERTER E VALIDAR DATAS
datas = pd.to_datetime(
    df["Release date"],
    format="%b %d, %Y",
    errors="coerce",
)

df = filtrar(df, datas.notna(), "Datas ausentes ou não reconhecidas")
df["Release date"] = datas.loc[df.index]

# Jogos sem data válida são removidos para permitir divisão temporal.


# 7. TRATAR ENTRADAS CANDIDATAS
df["Required age"] = pd.to_numeric(
    df["Required age"], errors="coerce"
)

idade_valida = (
    df["Required age"].ge(0)
    & df["Required age"].le(100)
    & df["Required age"].mod(1).eq(0)
)

# Valores inválidos viram ausentes; não inventamos uma idade.
df["Required age"] = (
    df["Required age"].where(idade_valida).astype("Int64")
)

mapa_booleano = {
    "true": True,
    "false": False,
    "1": True,
    "0": False,
}

for coluna in ["Windows", "Mac", "Linux"]:
    df[coluna] = (
        df[coluna]
        .str.lower()
        .map(mapa_booleano)
        .astype("boolean")
    )

# Exige ao menos gênero OU categoria.
# Não descarta um jogo só porque desenvolvedora ou idioma está ausente.
tem_metadados = df[["Genres", "Categories"]].notna().any(axis=1)

df = filtrar(
    df,
    tem_metadados,
    "Jogos sem gênero e sem categoria",
)


# 8. COMPARAR LIMITES E APLICAR O MÍNIMO ESCOLHIDO
df["Total reviews"] = df["Positive"] + df["Negative"]

print("\nJogos elegíveis por quantidade mínima de avaliações:")
for limite in [1, 10, 50, 100, 200, 500]:
    quantidade = df["Total reviews"].ge(limite).sum()
    print(f"  Pelo menos {limite:>3}: {quantidade:,} jogos")

df = filtrar(
    df,
    df["Total reviews"].ge(MIN_AVALIACOES),
    f"Menos de {MIN_AVALIACOES} avaliações",
)

if df.empty:
    raise ValueError("Nenhum jogo permaneceu após os filtros.")


# 9. CALCULAR O ALVO
# Percentual de aprovação na escala de 0 a 100.
df["Approval rate"] = (
    100 * df["Positive"] / df["Total reviews"]
)


# 10. SALVAR SEM MODIFICAR O ORIGINAL
df = df.sort_values(
    ["Release date", "AppID"]
).reset_index(drop=True)

SAIDA.parent.mkdir(parents=True, exist_ok=True)

df.to_csv(
    SAIDA,
    index=False,
    encoding="utf-8-sig",
    date_format="%Y-%m-%d",
)

print("\nRESUMO FINAL")
print(f"Registros originais: {total_original:,}")
print(f"Jogos mantidos: {len(df):,}")
print(f"Quantidade de colunas: {len(df.columns)}")
print(f"Arquivo criado: {SAIDA.resolve()}")

print("\nDistribuição da aprovação:")
print(df["Approval rate"].describe().round(2).to_string())

print("\nValores ausentes por coluna:")
print(df.isna().sum().to_string())

print("\nExemplos:")
print(
    df[
        ["Name", "Total reviews", "Approval rate"]
    ].head(10).to_string(index=False)
)