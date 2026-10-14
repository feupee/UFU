import os
from pathlib import Path

import requests
from dotenv import load_dotenv


# Estrutura esperada:
# Desafio3/.env
# Desafio3/IGDB/main.py
RAIZ = Path(__file__).resolve().parent.parent
CAMINHO_ENV = RAIZ / ".env"

load_dotenv(CAMINHO_ENV)

CLIENT_ID = os.getenv("IGDB_CLIENT_ID", "").strip()
CLIENT_SECRET = os.getenv("IGDB_CLIENT_SECRET", "").strip()


def obter_token_acesso():
    """Obtém um token temporário usando as credenciais da Twitch."""
    if not CLIENT_ID or not CLIENT_SECRET:
        raise ValueError(
            "Credenciais não encontradas.\n"
            f"Confira o arquivo: {CAMINHO_ENV}\n"
            "Ele deve conter IGDB_CLIENT_ID e IGDB_CLIENT_SECRET."
        )

    resposta = requests.post(
        "https://id.twitch.tv/oauth2/token",
        data={
            "client_id": CLIENT_ID,
            "client_secret": CLIENT_SECRET,
            "grant_type": "client_credentials",
        },
        timeout=30,
    )

    if resposta.status_code != 200:
        raise RuntimeError(
            f"Erro ao autenticar: HTTP {resposta.status_code}\n"
            f"{resposta.text}"
        )

    token = resposta.json().get("access_token")

    if not token:
        raise RuntimeError(
            "A autenticação não retornou um token de acesso."
        )

    return token


def buscar_jogos_exemplo(token):
    """Consulta cinco jogos com nota e pelo menos 50 avaliações."""
    headers = {
        "Client-ID": CLIENT_ID,
        "Authorization": f"Bearer {token}",
        "Accept": "application/json",
    }

    consulta = """
        fields name, rating, rating_count;
        where rating != null & rating_count >= 50;
        sort rating desc;
        limit 5;
    """

    resposta = requests.post(
        "https://api.igdb.com/v4/games",
        headers=headers,
        data=consulta,
        timeout=30,
    )

    if resposta.status_code != 200:
        raise RuntimeError(
            f"Erro na consulta: HTTP {resposta.status_code}\n"
            f"{resposta.text}"
        )

    return resposta.json()


def main():
    print(f"Arquivo de configuração: {CAMINHO_ENV}")
    print("Autenticando na API do IGDB...")

    token = obter_token_acesso()
    print("Token obtido com sucesso!\n")

    print("Buscando jogos de exemplo...")
    jogos = buscar_jogos_exemplo(token)

    if not jogos:
        print("Nenhum jogo encontrado com esse filtro.")
        return

    print("\n--- Maiores notas entre jogos com pelo menos 50 avaliações ---")

    for jogo in jogos:
        nome = jogo.get("name", "Desconhecido")
        nota = jogo["rating"]
        quantidade = jogo["rating_count"]

        print(
            f"• {nome} | Nota: {nota:.2f} "
            f"| Avaliações de usuários: {quantidade}"
        )

    print("\nConsulta concluída. Nenhum arquivo de dados foi alterado.")


if __name__ == "__main__":
    try:
        main()
    except requests.exceptions.Timeout:
        print("\nErro: o servidor demorou demais para responder.")
        raise SystemExit(1)
    except requests.exceptions.ConnectionError:
        print("\nErro de conexão. Confira sua internet e tente novamente.")
        raise SystemExit(1)
    except (ValueError, RuntimeError) as erro:
        print(f"\n{erro}")
        raise SystemExit(1)