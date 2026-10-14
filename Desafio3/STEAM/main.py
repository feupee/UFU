import csv
import pandas as pd

caminho = "dados/games.csv"

# Lê e corrige apenas o cabeçalho em memória.
with open(caminho, encoding="utf-8-sig", newline="") as arquivo:
    cabecalho = next(csv.reader(arquivo))

posicao = cabecalho.index("DiscountDLC count")
cabecalho[posicao:posicao + 1] = ["Discount", "DLC count"]

# Ignora o cabeçalho original e utiliza os 40 nomes corrigidos.
df = pd.read_csv(
    caminho,
    header=0,
    names=cabecalho,
    index_col=False,
    encoding="utf-8-sig",
    low_memory=False,
)

print(f"Total de registros: {len(df):,}")
print(f"Total de colunas: {len(df.columns)}")

print("\nPrimeiro registro:")
print(df.iloc[0][[
    "AppID", "Name", "Release date",
    "Estimated owners", "Price", "Discount", "DLC count"
]].to_string())