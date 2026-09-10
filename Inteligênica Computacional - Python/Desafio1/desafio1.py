"""
desafio1_aluno.py — Desafio 1: Mapa de características para o Perceptron
GBC073 — Inteligência Computacional (FACOM/UFU)

O QUE VOCÊ FAZ: preencher a classe `Submissao` (e só ela).
O QUE O HARNESS FAZ: gera dados, divide 60/40, aplica a sua phi, treina um
Perceptron fixo e mede a acurácia. Rode:  python desafio1_aluno.py

Regras:
  * fit(X) recebe só as entradas de treino, sem rótulos. É opcional.
  * phi(X) transforma (n, d) em (n, d') com d < d' <= 64, de forma determinística.
  * Sem NaN/Inf; e rápido (10 mil pontos em menos de 2 s).
Escore: 0 = igual à identidade (baseline), 100 = igual à referência do professor,
até 125 se superar a referência. Na correção, tarefas OCULTAS da mesma família
substituem estas — não ajuste para um conjunto de dados específico.
"""
import math
import time
import torch

DIM_MAX = 64
SEMENTES = (0, 1, 2)

# XOR
# 0 e 1 -> 1
# 1 e 0 -> 1
# 0 e 0 -> 0
# 1 e 1 -> 0
# 0.7 -0.2 = -0.14 claase 1
# 0.7 0.2 = 0.14 classe 0


# ============================================================================= 
# >>> SUA SUBMISSÃO — edite apenas esta classe <<<
# =============================================================================
class Submissao:
    DIM_MAX = DIM_MAX

    def fit(self, X: torch.Tensor) -> None:
        """
        Preparo os parâmetros usados posteriormente em phi(X).

        O fit recebe apenas os dados de treino, sem os rótulos.
        Primeiro calculo média e desvio padrão para padronizar cada coluna.
        Depois estimo uma escala dos dados e preparo as projeções aleatórias
        usadas pelas Random Fourier Features.
        """

        # Calculo média e desvio padrão de cada coluna.
        # Esses valores serão reutilizados em phi para padronizar treino e teste
        # sempre da mesma maneira.
        self.mu = X.mean(dim=0)
        self.sd = X.std(dim=0) + 1e-8

        Xs = (X - self.mu) / self.sd

        # Estimo uma distância típica entre os pontos.
        # Uso no máximo 300 amostras para manter o cálculo rápido.
        amostra = Xs[:300]
        d2 = torch.cdist(amostra, amostra) ** 2
        distancias_validas = d2[d2 > 0]

        if distancias_validas.numel() > 0:
            sigma = math.sqrt(
                distancias_validas.median().item() / 2
            )
        else:
            sigma = 1.0

        sigma = max(sigma, 1e-6)

        # Preparo até 48 Random Fourier Features.
        self.num_rff = 48

        # Uso uma semente fixa para que a transformação seja determinística.
        g = torch.Generator().manual_seed(0)

        # Cada coluna de W representa uma projeção diferente dos dados.
        W = (
            torch.randn(
                X.shape[1],
                self.num_rff,
                generator=g
            )
            / sigma
        )

        # Uso diferentes escalas para capturar padrões em vários níveis:
        # 0.5 e 1.0 -> variações mais suaves
        # 2.0 e 4.0 -> variações mais rápidas e detalhes menores
        escalas = torch.tensor(
            [
                [0.5, 1.0, 2.0, 4.0][i % 4]
                for i in range(self.num_rff)
            ],
            dtype=W.dtype
        )

        self.W = W * escalas

        # Crio deslocamentos de fase para aumentar a variedade
        # das Fourier Features.
        self.b = (
            torch.rand(
                self.num_rff,
                generator=g
            )
            * 2
            * math.pi
        )

    def phi(self, X: torch.Tensor) -> torch.Tensor:
        """
        Crio uma nova representação dos dados para facilitar a separação
        linear realizada pelo Perceptron.

        A representação combina:
        - valores originais padronizados;
        - quadrados x_i²;
        - produtos x_i*x_j;
        - Random Fourier Features cos(w^T x + b).
        """

        # Padronizo os dados usando os mesmos valores calculados no fit.
        Xs = (X - self.mu) / self.sd

        d = Xs.shape[1]

        # Começo mantendo as características originais padronizadas.
        partes = [Xs]

        # Controlo quantas novas colunas ainda posso adicionar
        # sem ultrapassar o limite de 64.
        restantes = self.DIM_MAX - d

        # =========================================================
        # Quadrados: x1², x2², ...
        # =========================================================

        if restantes > 0:
            quadrados = Xs ** 2
            quadrados = quadrados[:, :restantes]

            partes.append(quadrados)
            restantes -= quadrados.shape[1]

        # Os quadrados ajudam a representar relações de distância.
        #
        # Exemplo em 2D:
        #
        #     r² = x1² + x2²
        #
        # Por isso são úteis para padrões como círculos e esferas.

        # =========================================================
        # Interações: x1*x2, x1*x3, ...
        # =========================================================

        if restantes > 0 and d >= 2:
            pares = torch.triu_indices(
                d,
                d,
                offset=1,
                device=X.device
            )

            # Multiplico cada par de características diferentes.
            interacoes = (
                Xs[:, pares[0]]
                *
                Xs[:, pares[1]]
            )

            # Uso no máximo 8 interações para deixar espaço
            # para as Fourier Features.
            num_interacoes = min(
                8,
                restantes,
                interacoes.shape[1]
            )

            interacoes = interacoes[:, :num_interacoes]

            partes.append(interacoes)
            restantes -= num_interacoes

        # Essas colunas representam relações entre duas entradas.
        #
        # Para duas características x e y, por exemplo,
        # a nova coluna é literalmente:
        #
        #     x*y
        #
        # No XOR, o sinal de x*y ajuda diretamente a distinguir
        # quando as duas entradas possuem sinais iguais ou diferentes.

        # =========================================================
        # Random Fourier Features
        # =========================================================

        if restantes > 0:
            num_rff = min(
                restantes,
                self.num_rff
            )

            # Calculo várias combinações lineares das entradas.
            #
            # Cada uma representa algo equivalente a:
            #
            #     w1*x1 + w2*x2 + ... + wd*xd
            projecao = (
                Xs[:, 0:1]
                *
                self.W[0:1, :num_rff]
            )

            for j in range(1, d):
                projecao = (
                    projecao
                    +
                    Xs[:, j:j+1]
                    *
                    self.W[j:j+1, :num_rff]
                )

            # Transformo cada projeção em uma nova coluna:
            #
            #     cos(w^T x + b)
            #
            # Diferentes W, fases e escalas fazem cada coluna
            # observar os dados de uma maneira diferente.
            fourier = torch.cos(
                projecao
                +
                self.b[:num_rff]
            )

            fourier = (
                2.0
                *
                math.sqrt(2 / num_rff)
                *
                fourier
            )

            partes.append(fourier)

        # Junto todas as características e entrego a nova
        # representação ao Perceptron.
        return torch.cat(partes, dim=1)
    
# =============================================================================
# Harness (não edite daqui para baixo)
# =============================================================================
def _luas(n, g):
    t = torch.rand(n // 2, generator=g) * math.pi
    X = torch.cat([torch.stack([torch.cos(t), torch.sin(t)], 1),
                   torch.stack([1 - torch.cos(t), 0.5 - torch.sin(t)], 1)])
    y = torch.cat([torch.zeros(n // 2), torch.ones(n // 2)])
    return X + 0.15 * torch.randn(n, 2, generator=g), y

def _circulos(n, g):
    t = torch.rand(n, generator=g) * 2 * math.pi
    r = torch.where(torch.arange(n) < n // 2, 1.0, 0.45)
    X = torch.stack([r * torch.cos(t), r * torch.sin(t)], 1)
    return X + 0.08 * torch.randn(n, 2, generator=g), (torch.arange(n) >= n // 2).float()

def _xor(n, g):
    X = torch.rand(n, 2, generator=g) * 2 - 1
    y = (X[:, 0] * X[:, 1] < 0).float()
    return X + 0.15 * torch.randn(n, 2, generator=g), y

def _espiral(n, g):
    t = torch.sqrt(torch.rand(n // 2, generator=g)) * 3 * math.pi
    a = torch.stack([t * torch.cos(t), t * torch.sin(t)], 1) / 10
    y = torch.cat([torch.zeros(n // 2), torch.ones(n // 2)])
    return torch.cat([a, -a]) + 0.05 * torch.randn(n, 2, generator=g), y

def _esfera(n, g, d=10):
    X = torch.randn(n, d, generator=g)
    r2 = (X ** 2).sum(1)
    return X, (r2 > r2.median()).float()

TAREFAS = {"xor": lambda g: _xor(600, g), "duas_luas": lambda g: _luas(600, g),
           "circulos": lambda g: _circulos(600, g), "espiral": lambda g: _espiral(800, g),
           "esfera_10d": lambda g: _esfera(800, g)}


@torch.no_grad()
def perceptron_pocket(Z, y, epocas=50, eta=1.0, semente=0):
    """Regra de Rosenblatt (w <- w + eta*y*z nos erros) + pocket: guarda o melhor w."""
    Zb = torch.cat([Z, torch.ones(len(Z), 1)], 1)     # viés embutido
    yb = 2 * y - 1
    w = torch.zeros(Zb.shape[1]); melhor_w, melhor_acc = w.clone(), -1.0
    g = torch.Generator().manual_seed(semente)
    for _ in range(epocas):
        for i in torch.randperm(len(Zb), generator=g).tolist():
            if yb[i] * (Zb[i] @ w) <= 0:
                w += eta * yb[i] * Zb[i]
        acc = ((Zb @ w) * yb > 0).float().mean().item()
        if acc > melhor_acc:
            melhor_acc, melhor_w = acc, w.clone()
    return melhor_w


def acuracia_balanceada(y, yhat):
    return torch.stack([(yhat[y == c] == c).float().mean() for c in y.unique()]).mean().item()


@torch.no_grad()
def rodar(sub, gerador, semente, checar=True):
    g = torch.Generator().manual_seed(semente)
    X, y = gerador(g)
    idx = torch.randperm(len(X), generator=g); ntr = int(0.6 * len(X))
    Xtr, ytr, Xte, yte = X[idx[:ntr]], y[idx[:ntr]], X[idx[ntr:]], y[idx[ntr:]]

    torch.manual_seed(semente)
    sub.fit(Xtr)                                       # nunca recebe ytr
    t0 = time.perf_counter(); Ztr = sub.phi(Xtr); dt = time.perf_counter() - t0
    Zte = sub.phi(Xte)
    if checar:                                         # regras do desafio
        d, dl = Xtr.shape[1], Ztr.shape[1]
        assert Ztr.ndim == 2 and Zte.shape[1] == dl, "phi deve devolver (n, d')"
        assert d < dl <= DIM_MAX, f"exige d < d' <= {DIM_MAX}; recebi d={d}, d'={dl}"
        assert torch.isfinite(Ztr).all() and torch.isfinite(Zte).all(), "NaN/Inf na saída de phi"
        assert torch.allclose(sub.phi(Xtr[:20]), Ztr[:20]), "phi não é determinística"
        assert dt * (10_000 / len(Xtr)) < 2.0, "phi lenta demais (limite: 10^4 pontos em 2 s)"

    w = perceptron_pocket(Ztr, ytr, semente=semente)
    yhat = (torch.cat([Zte, torch.ones(len(Zte), 1)], 1) @ w > 0).float()
    return acuracia_balanceada(yte, yhat)


class _Identidade:                       # baseline (viola d < d', mas é só o ponto zero da escala)
    def fit(self, X): pass
    def phi(self, X): return X

class _RFF:                              # referência: random Fourier features, d' = 64
    def fit(self, X):
        g = torch.Generator().manual_seed(0)
        self.mu, self.sd = X.mean(0), X.std(0) + 1e-8
        Xs = (X - self.mu) / self.sd
        d2 = torch.cdist(Xs[:300], Xs[:300]) ** 2
        sigma = math.sqrt(d2[d2 > 0].median().item() / 2)
        self.W = torch.randn(X.shape[1], DIM_MAX, generator=g) / sigma
        self.b = torch.rand(DIM_MAX, generator=g) * 2 * math.pi
    def phi(self, X):
        return math.sqrt(2 / DIM_MAX) * torch.cos(((X - self.mu) / self.sd) @ self.W + self.b)


def _mediana(cls, gerador, checar=True):
    vals = [rodar(cls(), gerador, sem, checar) for sem in SEMENTES]
    return float(torch.tensor(vals).median())


def avaliar():
    print(f"{'tarefa':<12}{'baseline':>10}{'referência':>12}{'você':>8}{'s_t':>7}")
    s = []
    for nome, gen in TAREFAS.items():
        b = _mediana(_Identidade, gen, checar=False)
        r = max(_mediana(_RFF, gen, checar=False), b + 1e-3)
        try:
            m = _mediana(Submissao, gen); erro = ""
        except AssertionError as e:
            m, erro = b, f"   <- {e}"
        st = min(max((m - b) / (r - b), 0.0), 1.25); s.append(st)
        print(f"{nome:<12}{b:>10.3f}{r:>12.3f}{m:>8.3f}{st:>7.2f}{erro}")
    S = 100 * (0.7 * sum(s) / len(s) + 0.3 * min(s))
    print(f"\nESCORE S = {S:.1f}   (0 = baseline, 100 = referência, até 125 com bônus)")
    return S


if __name__ == "__main__":
    avaliar()
