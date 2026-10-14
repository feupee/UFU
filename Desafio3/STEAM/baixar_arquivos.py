from pathlib import Path
from urllib.request import Request, urlopen

url = (
    "https://huggingface.co/datasets/"
    "FronkonGames/steam-games-dataset/resolve/main/games.csv"
)

destino = Path("dados/games.csv")
destino.parent.mkdir(parents=True, exist_ok=True)

# O nome definitivo só é usado quando o download termina.
temporario = destino.with_suffix(".csv.part")

requisicao = Request(url, headers={"User-Agent": "Python"})

try:
    with urlopen(requisicao, timeout=120) as resposta:
        total = int(resposta.headers.get("Content-Length", 0))
        baixado = 0

        with temporario.open("wb") as arquivo:
            while bloco := resposta.read(1024 * 1024):
                arquivo.write(bloco)
                baixado += len(bloco)

                progresso = f"\rBaixados: {baixado / 1024**2:.1f} MB"
                if total:
                    progresso += f" ({100 * baixado / total:.1f}%)"

                print(progresso, end="", flush=True)

        if total and baixado != total:
            raise IOError("O download terminou antes de receber todo o arquivo.")

    temporario.replace(destino)
    print(f"\nDownload concluído: {destino.resolve()}")

except Exception as erro:
    print(f"\nNão foi possível concluir o download: {erro}")
    print("Execute novamente para reiniciar o download.")
    raise