import csv
from pathlib import Path

import pandas as pd


PASTA = Path("dados")

# Arquivo já limpo.
df = pd.read_csv(
    PASTA / "games_limpo.csv",
    dtype={"AppID": "string"},
)

print("=== PERÍODO DOS JOGOS ===")

datas = pd.to_datetime(
    df["Release date"],
    format="%Y-%m-%d",
    errors="coerce",
)

print(f"Data mais antiga: {datas.min()}")
print(f"Data mais recente: {datas.max()}")
print(f"Datas inválidas: {datas.isna().sum()}")

print("\nQuantidade de jogos por ano:")
print(datas.dt.year.value_counts().sort_index().to_string())


print("\n=== EXEMPLOS DOS METADADOS ===")

colunas = [
    "Supported languages",
    "Full audio languages",
    "Developers",
    "Publishers",
    "Categories",
    "Genres",
]

for coluna in colunas:
    print(f"\n{coluna}:")

    exemplos = df[coluna].dropna().drop_duplicates().head(5)

    for valor in exemplos:
        print(f"  {valor!r}")


print("\n=== IDADE INDICADA ===")
print(df["Required age"].value_counts(dropna=False).to_string())


# Consulta o original para distinguir campos vazios de listas vazias.
with (PASTA / "games.csv").open(
    encoding="utf-8-sig", newline=""
) as arquivo:
    cabecalho = next(csv.reader(arquivo))

if "DiscountDLC count" in cabecalho:
    posicao = cabecalho.index("DiscountDLC count")
    cabecalho[posicao:posicao + 1] = ["Discount", "DLC count"]

original = pd.read_csv(
    PASTA / "games.csv",
    header=0,
    names=cabecalho,
    usecols=[
        "AppID",
        "Supported languages",
        "Full audio languages",
    ],
    dtype="string",
    keep_default_na=False,  # Preserva "" e "[]" como textos diferentes.
)

original["AppID"] = original["AppID"].str.strip()

# Analisa apenas os jogos que permaneceram após a limpeza.
original = original[
    original["AppID"].isin(df["AppID"])
].copy()

print("\n=== IDIOMAS NO ARQUIVO ORIGINAL ===")
print(f"Registros encontrados: {len(original):,}")

for coluna in ["Supported languages", "Full audio languages"]:
    valores = original[coluna].str.strip()

    vazio = valores.eq("")
    lista_vazia = valores.str.fullmatch(r"\[\s*\]", na=False)
    marcador = valores.str.lower().isin(
        ["nan", "none", "null", "unknown", "{}"]
    )
    outros = ~(vazio | lista_vazia | marcador)

    print(f"\n{coluna}:")
    print(f"  Campo vazio: {vazio.sum():,}")
    print(f"  Lista vazia []: {lista_vazia.sum():,}")
    print(f"  Outros marcadores de ausência: {marcador.sum():,}")
    print(f"  Valores preenchidos: {outros.sum():,}")