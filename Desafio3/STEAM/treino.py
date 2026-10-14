import os

# Deve ser definido antes de inicializar o CUDA.
os.environ["CUBLAS_WORKSPACE_CONFIG"] = ":4096:8"

import argparse
import csv
import hashlib
import json
import random
import time
from pathlib import Path

import numpy as np
import torch
from torch import nn


def salvar_csv(caminho, linhas):
    with caminho.open("w", newline="", encoding="utf-8") as arquivo:
        escritor = csv.DictWriter(
            arquivo,
            fieldnames=list(linhas[0]),
        )
        escritor.writeheader()
        escritor.writerows(linhas)


def carregar(caminho):
    with np.load(caminho, allow_pickle=False) as dados:
        X = torch.from_numpy(dados["X"].astype(np.float32))
        y = torch.from_numpy(dados["y"].astype(np.float32))

    return X, y


def assinatura(caminho):
    """Calcula uma identificação do conteúdo do arquivo."""
    return hashlib.sha256(caminho.read_bytes()).hexdigest()


def norma(tensores):
    """Norma L2 conjunta dos tensores fornecidos."""
    tensores = list(tensores)

    if not tensores:
        return 0.0

    soma = sum(
        tensor.detach().double().square().sum()
        for tensor in tensores
    )

    return soma.sqrt().item()


def todos_finitos(tensores):
    verificacoes = [
        torch.isfinite(tensor).all()
        for tensor in tensores
    ]

    if not verificacoes:
        return True

    return torch.stack(verificacoes).all().item()


def main():
    parser = argparse.ArgumentParser(
        description="Baseline de regressão de avaliações de jogos em GPU."
    )
    parser.add_argument("--semente", type=int, default=42)
    parser.add_argument("--passos", type=int, default=2000)
    parser.add_argument("--lote", type=int, default=256)
    parser.add_argument("--lr", type=float, default=0.001)
    parser.add_argument("--threads", type=int, default=4)
    args = parser.parse_args()

    if (
        args.passos < 1
        or args.lote < 1
        or args.threads < 1
        or not np.isfinite(args.lr)
        or args.lr <= 0
    ):
        raise ValueError(
            "Passos, lote, threads e taxa precisam ser positivos."
        )

    if not torch.cuda.is_available():
        raise RuntimeError(
            "CUDA indisponível. Execute usando:\n"
            r".\.venv\Scripts\python.exe treino.py --semente 42"
        )

    # REPRODUTIBILIDADE
    torch.set_num_threads(args.threads)
    torch.use_deterministic_algorithms(True)

    random.seed(args.semente)
    np.random.seed(args.semente)
    torch.manual_seed(args.semente)
    torch.cuda.manual_seed_all(args.semente)

    torch.backends.cudnn.benchmark = False
    torch.backends.cudnn.deterministic = True
    torch.backends.cuda.matmul.allow_tf32 = False
    torch.backends.cudnn.allow_tf32 = False

    dispositivo = torch.device("cuda:0")
    nome_gpu = torch.cuda.get_device_name(0)

    print(f"GPU utilizada: {nome_gpu}")
    print(f"PyTorch: {torch.__version__}")

    # CAMINHOS RELATIVOS À PASTA DO SCRIPT
    raiz = Path(__file__).resolve().parent
    pasta = raiz / "dados" / "processados"
    caminho_treino = pasta / "treino.npz"
    caminho_val = pasta / "validacao.npz"

    # CARREGAMENTO E VALIDAÇÃO DOS DADOS
    X, y = carregar(caminho_treino)
    X_val, y_val = carregar(caminho_val)

    if (
        X.ndim != 2
        or X_val.ndim != 2
        or y.shape != (len(X), 1)
        or y_val.shape != (len(X_val), 1)
        or X.shape[1] != X_val.shape[1]
        or len(X) == 0
        or len(X_val) == 0
    ):
        raise ValueError("Dimensões dos dados inválidas.")

    if not todos_finitos([X, y, X_val, y_val]):
        raise ValueError("Existem valores não finitos nos dados.")

    if not (
        ((y >= 0) & (y <= 1)).all().item()
        and ((y_val >= 0) & (y_val <= 1)).all().item()
    ):
        raise ValueError("Os alvos precisam estar entre 0 e 1.")

    if args.lote > len(X):
        raise ValueError("O lote não pode ser maior que o treino.")

    # Os dados permanecem na GPU durante o treinamento.
    X = X.to(dispositivo)
    y = y.to(dispositivo)
    X_val = X_val.to(dispositivo)
    y_val = y_val.to(dispositivo)

    # MODELO
    modelo = nn.Sequential(
        nn.Linear(X.shape[1], 128),
        nn.ReLU(),
        nn.Linear(128, 64),
        nn.ReLU(),
        nn.Linear(64, 1),
    ).to(dispositivo)

    criterio = nn.MSELoss()

    otimizador = torch.optim.AdamW(
        modelo.parameters(),
        lr=args.lr,
        weight_decay=0.01,
        betas=(0.9, 0.999),
        eps=1e-8,
        foreach=False,
        fused=False,
    )

    # Cada grupo inclui pesos e vieses.
    grupos = {
        "global": list(modelo.parameters()),
        "primeira": list(modelo[0].parameters()),
        "meio": list(modelo[2].parameters()),
        "saida": list(modelo[4].parameters()),
    }

    configuracao = {
        **vars(args),
        "otimizador": "AdamW",
        "agenda": "constante",
        "weight_decay": 0.01,
        "betas": [0.9, 0.999],
        "eps": 1e-8,
        "foreach": False,
        "fused": False,
        "arquitetura": [X.shape[1], 128, 64, 1],
        "ativacao": "ReLU",
        "saida": "linear",
        "perda": "MSE",
        "escala_alvo": "0 a 1",
        "criterio_selecao": "MAE final na validacao",
        "log_a_cada": 20,
        "validacao_a_cada": 100,
        "clipping": None,
        "normas": "L2 incluindo pesos e vieses",
        "theta_registrado": "antes da atualizacao",
        "rho_denominador_minimo": 1e-12,
        "lotes": "embaralhados sem reposicao; descarta sobra incompleta",
        "dispositivo": str(dispositivo),
        "gpu": nome_gpu,
        "cuda": torch.version.cuda,
        "cublas_workspace_config": os.environ[
            "CUBLAS_WORKSPACE_CONFIG"
        ],
        "deterministico": True,
        "tf32": False,
        "torch": str(torch.__version__),
        "numpy": np.__version__,
        "sha256_treino": assinatura(caminho_treino),
        "sha256_validacao": assinatura(caminho_val),
        "sha256_script": assinatura(Path(__file__)),
    }

    # Preserva execuções anteriores.
    identificador = (
        f"baseline_s{args.semente}_{time.time_ns()}"
    )
    saida = raiz / "logs" / identificador
    saida.mkdir(parents=True)

    (saida / "config.json").write_text(
        json.dumps(
            configuracao,
            indent=2,
            ensure_ascii=False,
        ),
        encoding="utf-8",
    )

    registros = []
    validacoes = []
    divergiu = False
    motivo = ""
    passos_concluidos = 0

    # Sorteio dos lotes na CPU, independente da inicialização da rede.
    gerador = torch.Generator().manual_seed(args.semente)
    ordem = torch.randperm(len(X), generator=gerador)
    posicao = 0

    def avaliar(passo):
        modelo.eval()

        with torch.no_grad():
            previsao = modelo(X_val)
            mse = criterio(previsao, y_val).item()
            mae = (
                (previsao - y_val).abs().mean().item() * 100
            )

        validacoes.append({
            "passo": passo,
            "mse_val": mse,
            "mae_val_pp": mae,
        })

        modelo.train()
        return mse, mae

    print(f"Execução: {identificador}")
    print(f"Treino: {len(X):,} jogos")
    print(f"Validação: {len(X_val):,} jogos")
    print(f"Características: {X.shape[1]}")
    print(
        "Parâmetros: "
        f"{sum(p.numel() for p in modelo.parameters()):,}"
    )

    modelo.train()

    # Aguarda a conclusão das transferências antes de medir o tempo.
    torch.cuda.synchronize()
    inicio = time.perf_counter()

    for passo in range(1, args.passos + 1):
        # Mantém todos os lotes com o mesmo tamanho.
        if posicao + args.lote > len(X):
            ordem = torch.randperm(
                len(X),
                generator=gerador,
            )
            posicao = 0

        indices = ordem[
            posicao:posicao + args.lote
        ].to(dispositivo)

        posicao += args.lote

        otimizador.zero_grad(set_to_none=True)

        previsao = modelo(X[indices])
        perda = criterio(previsao, y[indices])

        if not torch.isfinite(perda).item():
            divergiu = True
            motivo = f"Perda não finita no passo {passo}"
            break

        perda.backward()

        if not todos_finitos(
            p.grad
            for p in modelo.parameters()
            if p.grad is not None
        ):
            divergiu = True
            motivo = f"Gradiente não finito no passo {passo}"
            break

        registrar = passo % 20 == 0 or passo == args.passos

        if registrar:
            # Sinais medidos antes da atualização.
            registro = {
                "passo": passo,
                "perda_treino": perda.item(),
                "lr": otimizador.param_groups[0]["lr"],
            }

            antes = {
                nome: [
                    p.detach().clone()
                    for p in parametros
                ]
                for nome, parametros in grupos.items()
            }

            for nome, parametros in grupos.items():
                registro[f"grad_{nome}"] = norma(
                    p.grad
                    for p in parametros
                    if p.grad is not None
                )

                registro[f"theta_{nome}"] = norma(parametros)

        # Não aplicamos clipping nesta baseline.
        otimizador.step()
        passos_concluidos = passo

        if not todos_finitos(modelo.parameters()):
            divergiu = True
            motivo = (
                f"Parâmetro não finito após o passo {passo}"
            )
            break

        if registrar:
            # Mede a mudança provocada por este único passo.
            for nome, parametros in grupos.items():
                diferencas = [
                    p.detach() - antigo
                    for p, antigo in zip(
                        parametros,
                        antes[nome],
                    )
                ]

                denominador = registro[f"theta_{nome}"]

                registro[f"rho_{nome}"] = (
                    norma(diferencas)
                    / max(denominador, 1e-12)
                )

            registros.append(registro)

        if passo % 100 == 0 or passo == args.passos:
            mse_val, mae_val = avaliar(passo)

            if (
                not np.isfinite(mse_val)
                or not np.isfinite(mae_val)
            ):
                divergiu = True
                motivo = (
                    f"Validação não finita no passo {passo}"
                )
                break

            print(
                f"Passo {passo:4d}/{args.passos} | "
                f"MSE lote: {perda.item():.5f} | "
                f"MAE validação: {mae_val:.2f} pp"
            )

    torch.cuda.synchronize()
    segundos = time.perf_counter() - inicio

    # SALVAR REGISTROS
    if registros:
        salvar_csv(saida / "sinais.csv", registros)

    if validacoes:
        salvar_csv(saida / "validacao.csv", validacoes)

    mae_final = (
        validacoes[-1]["mae_val_pp"]
        if not divergiu and validacoes
        else None
    )

    if not divergiu:
        # Salva os pesos em CPU para facilitar o carregamento futuro.
        pesos_cpu = {
            nome: tensor.detach().cpu()
            for nome, tensor in modelo.state_dict().items()
        }

        torch.save(
            {
                "state_dict": pesos_cpu,
                "config": configuracao,
            },
            saida / "modelo_final.pt",
        )

    resultado = {
        "execucao": identificador,
        "otimizador": "AdamW",
        "agenda": "constante",
        "lr": args.lr,
        "weight_decay": 0.01,
        "semente": args.semente,
        "lote": args.lote,
        "passos_planejados": args.passos,
        "passos_concluidos": passos_concluidos,
        "mae_val_final_pp": mae_final,
        "divergiu": divergiu,
        "motivo": motivo,
        "tempo_segundos": segundos,
        "pasta_logs": str(saida.relative_to(raiz)),
    }

    (saida / "resultado.json").write_text(
        json.dumps(
            resultado,
            indent=2,
            ensure_ascii=False,
        ),
        encoding="utf-8",
    )

    catalogo = raiz / "experimentos.csv"
    tem_cabecalho = (
        catalogo.exists()
        and catalogo.stat().st_size > 0
    )

    # Evita misturar formatos de catálogo diferentes.
    if tem_cabecalho:
        with catalogo.open(
            encoding="utf-8",
            newline="",
        ) as arquivo:
            cabecalho_existente = next(csv.reader(arquivo))

        if cabecalho_existente != list(resultado):
            raise ValueError(
                "O cabeçalho de experimentos.csv é diferente "
                "do esperado. Os logs desta execução foram salvos "
                f"em {saida}, mas o catálogo não foi alterado."
            )

    with catalogo.open(
        "a",
        newline="",
        encoding="utf-8",
    ) as arquivo:
        escritor = csv.DictWriter(
            arquivo,
            fieldnames=list(resultado),
        )

        if not tem_cabecalho:
            escritor.writeheader()

        escritor.writerow(resultado)

    print(f"\nTempo de treino e validação: {segundos:.1f} segundos")
    print(f"Logs: {saida.resolve()}")

    if divergiu:
        print(f"Execução interrompida e registrada: {motivo}")
    else:
        print(
            f"MAE final na validação: {mae_final:.2f} "
            "pontos percentuais"
        )

    print("O conjunto de teste não foi utilizado.")


if __name__ == "__main__":
    main()