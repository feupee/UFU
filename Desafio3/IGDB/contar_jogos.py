import time

import requests

from main import CLIENT_ID, obter_token_acesso


def contar(session, filtro):
    resposta = session.post(
        "https://api.igdb.com/v4/games/count",
        data=f"where {filtro};",
        timeout=30,
    )

    if resposta.status_code != 200:
        raise RuntimeError(
            f"Erro na contagem: HTTP {resposta.status_code}\n"
            f"{resposta.text}"
        )

    dados = resposta.json()

    if "count" not in dados:
        raise RuntimeError(f"Resposta inesperada: {dados}")

    return int(dados["count"])


def main():
    print("Autenticando...")
    token = obter_token_acesso()

    # Filtros de disponibilidade, sem selecionar jogos pela nota.
    metadados = (
        "first_release_date != null "
        "& genres != null "
        "& platforms != null"
    )

    # Exclui edições que possuem um jogo principal associado.
    # Não garante remover todas as variantes, remakes ou remasters.
    sem_edicao_associada = "version_parent = null"

    with requests.Session() as session:
        session.headers.update({
            "Client-ID": CLIENT_ID,
            "Authorization": f"Bearer {token}",
            "Accept": "application/json",
        })

        print("\nCONTAGEM DE REGISTROS DO IGDB")
        print(
            f"{'Mínimo de votos':>16} | "
            f"{'Com nota':>10} | "
            f"{'+ Metadados':>12} | "
            f"{'+ Sem edição associada':>23}"
        )
        print("-" * 72)

        for minimo in [1, 10, 20, 50, 100]:
            base = (
                f"rating != null & rating_count >= {minimo}"
            )

            filtros = [
                base,
                f"{base} & {metadados}",
                f"{base} & {metadados} & {sem_edicao_associada}",
            ]

            quantidades = []

            for filtro in filtros:
                # Espaça as consultas para respeitar o limite da API.
                time.sleep(0.35)
                quantidades.append(contar(session, filtro))

            print(
                f"{minimo:>16} | "
                f"{quantidades[0]:>10,} | "
                f"{quantidades[1]:>12,} | "
                f"{quantidades[2]:>23,}"
            )

    print("\nMetadados exigidos: data de lançamento, gêneros e plataformas.")
    print("A contagem ainda não é a seleção final dos jogos.")
    print("Nenhum arquivo da Steam foi alterado.")


if __name__ == "__main__":
    try:
        main()
    except requests.RequestException:
        print(
            "\nFalha de comunicação com a API. "
            "Verifique a conexão e tente novamente."
        )
        raise SystemExit(1)
    except (RuntimeError, ValueError) as erro:
        print(f"\n{erro}")
        raise SystemExit(1)