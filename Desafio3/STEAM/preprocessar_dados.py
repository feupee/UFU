import ast
import json
from collections import Counter
from pathlib import Path
import re

import numpy as np
import pandas as pd


PASTA = Path("dados")
SAIDA = PASTA / "processados"
SAIDA.mkdir(parents=True, exist_ok=True)

# Empresas presentes em menos de 10 jogos de treino serão
# representadas como "outros". Não usamos suas avaliações
# para criar essa representação.
MIN_JOGOS_EMPRESA = 10

CAMPOS = {
    "Genres": "virgulas",
    "Categories": "virgulas",
    "Supported languages": "lista",
    "Full audio languages": "lista",
    "Developers": "texto",
    "Publishers": "texto",
}

BOOLEANOS = ["Windows", "Mac", "Linux"]


def interpretar(valor, formato):
    """Converte uma célula em uma lista de itens únicos."""
    if pd.isna(valor):
        return []

    texto = str(valor).strip()

    if texto.lower() in {"", "nan", "none", "null", "unknown"}:
        return []

    if formato == "lista":
        try:
            itens = ast.literal_eval(texto)

        except (ValueError, SyntaxError):
            # Corrige somente o item malformado conhecido:
            # K'iche' -> "K'iche"
            #
            # Exige que o item esteja entre delimitadores
            # de uma lista, evitando modificar outros textos.
            corrigido, quantidade = re.subn(
                r"([\[,]\s*)K'iche'(?=\s*[,\]])",
                lambda resultado: resultado.group(1) + "\"K'iche\"",
                texto,
            )

            if quantidade == 0:
                raise ValueError(
                    f"Lista de idiomas inválida, sem correção conhecida: "
                    f"{texto!r}"
                )

            try:
                itens = ast.literal_eval(corrigido)
            except (ValueError, SyntaxError) as erro:
                raise ValueError(
                    f"A lista continua inválida após corrigir K'iche: "
                    f"{texto!r}"
                ) from erro

            print(
                "Aviso: corrigida a representação de K'iche "
                "em uma lista de idiomas."
            )

        if not isinstance(itens, list):
            raise ValueError(f"Era esperada uma lista: {texto!r}")

        if not all(isinstance(item, str) for item in itens):
            raise ValueError(
                f"Lista contém itens não textuais: {texto!r}"
            )

    elif formato == "virgulas":
        itens = texto.split(",")

    else:
        itens = [texto]

    return sorted({
        item.strip()
        for item in itens
        if item.strip()
    })


def ler_dados(nome):
    dados = pd.read_csv(
        PASTA / f"{nome}.csv",
        dtype={"AppID": "string"},
    )

    for campo, formato in CAMPOS.items():
        dados[campo] = dados[campo].apply(
            lambda valor: interpretar(valor, formato)
        )

    return dados


treino = ler_dados("treino")
validacao = ler_dados("validacao")


# 1. APRENDER O VOCABULÁRIO SOMENTE NO TREINO
vocabularios = {}

for campo in CAMPOS:
    contagens = Counter(
        item
        for itens in treino[campo]
        for item in itens
    )

    minimo = (
        MIN_JOGOS_EMPRESA
        if campo in {"Developers", "Publishers"}
        else 1
    )

    vocabularios[campo] = sorted(
        item
        for item, quantidade in contagens.items()
        if quantidade >= minimo
    )


# Cada campo terá ainda dois indicadores:
# - sem itens listados;
# - presença de item fora do vocabulário.
caracteristicas = []

for campo, vocabulario in vocabularios.items():
    caracteristicas.extend(
        f"{campo}::valor::{item}"
        for item in vocabulario
    )
    caracteristicas.extend([
        f"{campo}::sem_itens",
        f"{campo}::fora_vocabulario",
    ])

caracteristicas.extend(BOOLEANOS)


def transformar(dados):
    blocos = []

    for campo, vocabulario in vocabularios.items():
        indice = {
            item: posicao
            for posicao, item in enumerate(vocabulario)
        }

        tamanho = len(vocabulario)

        bloco = np.zeros(
            (len(dados), tamanho + 2),
            dtype=np.float32,
        )

        for linha, itens in enumerate(dados[campo]):
            if not itens:
                bloco[linha, tamanho] = 1.0

            for item in itens:
                posicao = indice.get(item)

                if posicao is None:
                    bloco[linha, tamanho + 1] = 1.0
                else:
                    bloco[linha, posicao] = 1.0

        blocos.append(bloco)

    mapa_booleano = {
        "true": 1.0,
        "false": 0.0,
        "1": 1.0,
        "0": 0.0,
    }

    for campo in BOOLEANOS:
        valores = (
            dados[campo]
            .astype("string")
            .str.strip()
            .str.lower()
            .map(mapa_booleano)
        )

        if valores.isna().any():
            raise ValueError(
                f"Valor booleano ausente ou inválido em {campo}."
            )

        blocos.append(
            valores.to_numpy(dtype=np.float32).reshape(-1, 1)
        )

    X = np.concatenate(blocos, axis=1)

    y = (
        pd.to_numeric(dados["Approval rate"], errors="raise")
        .to_numpy(dtype=np.float32)
        / 100.0
    ).reshape(-1, 1)

    if not np.isfinite(X).all() or not np.isfinite(y).all():
        raise ValueError("Existem valores não finitos nos dados.")

    if not ((y >= 0) & (y <= 1)).all():
        raise ValueError("Aprovação fora do intervalo esperado.")

    return X, y


# 2. APLICAR A MESMA REPRESENTAÇÃO NOS DOIS CONJUNTOS
for nome, dados in [
    ("treino", treino),
    ("validacao", validacao),
]:
    X, y = transformar(dados)

    np.savez_compressed(
        SAIDA / f"{nome}.npz",
        X=X,
        y=y,
        app_ids=dados["AppID"].to_numpy(dtype=str),
    )

    memoria_mb = (X.nbytes + y.nbytes) / 1024**2

    print(f"\n{nome.upper()}")
    print(f"X: {X.shape} — jogos × características")
    print(f"y: {y.shape} — aprovação entre 0 e 1")
    print(f"Memória das matrizes: {memoria_mb:.2f} MB")


# 3. SALVAR A REPRESENTAÇÃO PARA REUTILIZAR NO TESTE
# E EM FUTURAS PREVISÕES
configuracao = {
    "versao": 1,
    "campos": CAMPOS,
    "booleanos": BOOLEANOS,
    "min_jogos_empresa": MIN_JOGOS_EMPRESA,
    "vocabularios": vocabularios,
    "caracteristicas": caracteristicas,
    "divisor_do_alvo": 100.0,
}

with (SAIDA / "preprocessamento.json").open(
    "w", encoding="utf-8"
) as arquivo:
    json.dump(
        configuracao,
        arquivo,
        ensure_ascii=False,
        indent=2,
    )


# 4. REFERÊNCIA SIMPLES NA VALIDAÇÃO
# Para MAE, usamos a mediana do TREINO.
mediana_treino = treino["Approval rate"].median()

mae_referencia = (
    validacao["Approval rate"] - mediana_treino
).abs().mean()

print("\nREFERÊNCIA CONSTANTE")
print(f"Previsão fixa: {mediana_treino:.2f}% de aprovação")
print(
    f"MAE na validação: {mae_referencia:.2f} "
    "pontos percentuais"
)

print("\nVOCABULÁRIO")
for campo, vocabulario in vocabularios.items():
    print(f"{campo}: {len(vocabulario)} valores")

print(f"\nTotal de características: {len(caracteristicas)}")
print(f"Arquivos salvos em: {SAIDA.resolve()}")
print("O conjunto de teste não foi aberto.")