from pathlib import Path

import pandas as pd


PASTA = Path("dados")
ENTRADA = PASTA / "games_limpo.csv"

df = pd.read_csv(ENTRADA, dtype={"AppID": "string"})

df["Release date"] = pd.to_datetime(
    df["Release date"],
    format="%Y-%m-%d",
    errors="raise",
)

if df["AppID"].isna().any():
    raise ValueError("Existem jogos sem AppID.")

if df["AppID"].duplicated().any():
    raise ValueError("Existem AppIDs repetidos.")

if not df["Total reviews"].ge(50).all():
    raise ValueError("Existem jogos com menos de 50 avaliações.")

if not df["Approval rate"].between(0, 100).all():
    raise ValueError("Existem aprovações fora da escala de 0 a 100.")


# Recupera as listas vazias confirmadas pela inspeção do original.
# Isso significa "nenhum idioma listado", não ausência comprovada
# de suporte ou de áudio.
for coluna in ["Supported languages", "Full audio languages"]:
    df[coluna] = df[coluna].fillna("[]")


# A divisão depende somente da data de lançamento.
treino = df.loc[
    df["Release date"] < "2023-01-01"
].copy()

validacao = df.loc[
    (df["Release date"] >= "2023-01-01")
    & (df["Release date"] < "2024-01-01")
].copy()

teste = df.loc[
    df["Release date"] >= "2024-01-01"
].copy()

conjuntos = {
    "treino": treino,
    "validacao": validacao,
    "teste": teste,
}

if sum(len(parte) for parte in conjuntos.values()) != len(df):
    raise ValueError("A divisão não contempla todos os registros.")

if any(parte.empty for parte in conjuntos.values()):
    raise ValueError("Um dos conjuntos ficou vazio.")

ids_treino = set(treino["AppID"])
ids_validacao = set(validacao["AppID"])
ids_teste = set(teste["AppID"])

if (
    ids_treino & ids_validacao
    or ids_treino & ids_teste
    or ids_validacao & ids_teste
):
    raise ValueError("Existem jogos compartilhados entre os conjuntos.")


print(f"Total verificado no arquivo: {len(df):,}")
print("\nDIVISÃO TEMPORAL")

for nome, parte in conjuntos.items():
    parte = parte.sort_values(
        ["Release date", "AppID"]
    ).reset_index(drop=True)

    destino = PASTA / f"{nome}.csv"

    parte.to_csv(
        destino,
        index=False,
        encoding="utf-8-sig",
        date_format="%Y-%m-%d",
    )

    inicio = parte["Release date"].min().date()
    fim = parte["Release date"].max().date()

    print(
        f"{nome:10} | {len(parte):>6,} jogos "
        f"| {len(parte) / len(df):>6.1%} "
        f"| {inicio} até {fim}"
    )

print("\nArquivos criados:")
for nome in conjuntos:
    print((PASTA / f"{nome}.csv").resolve())

print("\nNenhuma métrica de desempenho foi calculada no teste.")