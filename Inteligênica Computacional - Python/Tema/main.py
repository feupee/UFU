import os
import requests
from dotenv import load_dotenv

# ============================================================
# CONFIGURAÇÃO
# ============================================================

# Garante que o .env seja procurado na mesma pasta deste arquivo
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
ENV_PATH = os.path.join(BASE_DIR, ".env")

load_dotenv(ENV_PATH)

CLIENT_ID = os.getenv("IGDB_CLIENT_ID")
CLIENT_SECRET = os.getenv("IGDB_CLIENT_SECRET")


# ============================================================
# AUTENTICAÇÃO
# ============================================================

def obter_token_acesso():
    """
    Obtém um token temporário da Twitch para acessar a API da IGDB.
    """

    url = "https://id.twitch.tv/oauth2/token"

    params = {
        "client_id": CLIENT_ID,
        "client_secret": CLIENT_SECRET,
        "grant_type": "client_credentials",
    }

    response = requests.post(url, params=params)

    if response.status_code == 200:
        return response.json()["access_token"]

    raise Exception(
        f"Erro ao autenticar: {response.status_code} - {response.text}"
    )


# ============================================================
# CONTAGEM DE JOGOS
# ============================================================

def contar_jogos(access_token,filtro=None):
    """
    Consulta o endpoint /games/count da IGDB.

    filtro:
        Expressão Apicalypse usada no 'where'.

    Exemplo:
        rating != null & rating_count >= 10
    """

    url = "https://api.igdb.com/v4/games/count"

    headers = {
        "Client-ID": CLIENT_ID,
        "Authorization": f"Bearer {access_token}",
    }

    if filtro:
        query = f"where {filtro};"
    else:
        query = ""

    response = requests.post(
        url,
        headers=headers,
        data=query
    )

    if response.status_code == 200:
        dados = response.json()
        return dados["count"]

    raise Exception(
        f"Erro na consulta '{filtro}': "
        f"{response.status_code} - {response.text}"
    )


# ============================================================
# ANÁLISE DA BASE
# ============================================================

def analisar_tamanho_base(access_token):
    """
    Executa várias consultas para descobrir quantos jogos
    permaneceriam na base para diferentes valores mínimos de
    rating_count.
    """

    consultas = [
        ("Todos os jogos", None),

        (
            "Jogos com rating",
            "rating != null"
        ),

        (
            "rating_count >= 1",
            "rating != null & rating_count >= 1"
        ),

        (
            "rating_count >= 5",
            "rating != null & rating_count >= 5"
        ),

        (
            "rating_count >= 10",
            "rating != null & rating_count >= 10"
        ),

        (
            "rating_count >= 20",
            "rating != null & rating_count >= 20"
        ),

        (
            "rating_count >= 50",
            "rating != null & rating_count >= 50"
        ),

        (
            "rating_count >= 100",
            "rating != null & rating_count >= 100"
        ),

        (
            "rating_count >= 250",
            "rating != null & rating_count >= 250"
        ),

        (
            "rating_count >= 500",
            "rating != null & rating_count >= 500"
        ),

        (
            "rating_count >= 1000",
            "rating != null & rating_count >= 1000"
        ),

        (
            "rating_count >= 5000",
            "rating != null & rating_count >= 5000"
        ),
    ]

    resultados = []

    print("\n" + "=" * 70)
    print("ANÁLISE DO TAMANHO DA BASE DA IGDB")
    print("=" * 70)

    for descricao, filtro in consultas:

        try:
            quantidade = contar_jogos(
                access_token,
                filtro
            )

            resultados.append(
                (descricao, quantidade)
            )

            print(
                f"{descricao:<30} → {quantidade:>10,}"
            )

        except Exception as erro:

            resultados.append(
                (descricao, None)
            )

            print(
                f"{descricao:<30} → ERRO"
            )

            print(f"    {erro}")

    return resultados


# ============================================================
# ANÁLISE PERCENTUAL
# ============================================================

def mostrar_percentuais(resultados):
    """
    Mostra qual percentual dos jogos com rating permanece
    depois de cada filtro de rating_count.
    """

    total_com_rating = None

    for descricao, quantidade in resultados:
        if descricao == "Jogos com rating":
            total_com_rating = quantidade
            break

    if not total_com_rating:
        print(
            "\nNão foi possível calcular os percentuais."
        )
        return

    print("\n" + "=" * 70)
    print("PERCENTUAL DE JOGOS MANTIDOS")
    print("=" * 70)

    for descricao, quantidade in resultados:

        if quantidade is None:
            continue

        if descricao in [
            "Todos os jogos",
            "Jogos com rating"
        ]:
            continue

        percentual = (
            quantidade / total_com_rating
        ) * 100

        print(
            f"{descricao:<30} → "
            f"{quantidade:>10,} jogos "
            f"({percentual:6.2f}%)"
        )


# ============================================================
# MAIN
# ============================================================

if __name__ == "__main__":

    # --------------------------------------------------------
    # Verifica as credenciais
    # --------------------------------------------------------

    if not CLIENT_ID or not CLIENT_SECRET:
        raise Exception(
            "As variáveis IGDB_CLIENT_ID e "
            "IGDB_CLIENT_SECRET não foram encontradas.\n\n"
            f"Arquivo esperado:\n{ENV_PATH}"
        )

    print("Arquivo .env encontrado:")
    print(ENV_PATH)

    print("\nAutenticando na IGDB...")

    token = obter_token_acesso()

    print("Autenticação realizada com sucesso.")

    # --------------------------------------------------------
    # Conta os jogos
    # --------------------------------------------------------

    resultados = analisar_tamanho_base(token)

    # --------------------------------------------------------
    # Calcula percentual restante
    # --------------------------------------------------------

    mostrar_percentuais(resultados)

    print("\n" + "=" * 70)
    print("ANÁLISE CONCLUÍDA")
    print("=" * 70)