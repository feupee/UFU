# Desafio 1 — Mapa de Características para o Perceptron

## Implementação documentada

```python
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
```

---

## Resumo da solução

O `fit` não classifica os dados. Eu o utilizo para preparar a transformação que será aplicada depois em `phi`.

Primeiro, calculo a média e o desvio padrão de cada coluna para padronizar os dados de treino e teste da mesma forma. Em seguida, estimo uma distância típica entre os pontos, representada por `sigma`. Essa escala serve para gerar as projeções usadas nas Random Fourier Features.

Também gero no `fit` a matriz `W` e os deslocamentos de fase `b`. Uso uma semente fixa para que esses valores sejam sempre os mesmos, garantindo que `phi(X)` seja determinística.

Na `phi`, começo pelos dados padronizados e acrescento novas colunas para aumentar a capacidade de representação do Perceptron.

### 1. Características originais padronizadas

As próprias entradas continuam presentes, mas depois da padronização:

`x_padronizado = (x - mu) / sd`

Isso deixa as diferentes colunas em escalas mais comparáveis.

### 2. Quadrados

Acrescento colunas do tipo:

- `x1²`
- `x2²`
- `x3²`
- ...

Essas colunas ajudam a representar relações de distância. Por exemplo, em 2D:

`r² = x1² + x2²`

Por isso elas são úteis em problemas como círculos e esferas.

### 3. Interações entre características

Também acrescento produtos entre pares de características:

- `x1*x2`
- `x1*x3`
- `x2*x3`
- ...

No caso de duas entradas `x` e `y`, a interação é literalmente:

`x*y`

No XOR, o sinal de `x*y` ajuda a diferenciar quando as duas entradas possuem sinais iguais ou diferentes.

### 4. Random Fourier Features

Por fim, acrescento novas colunas do tipo:

`cos(w^T x + b)`

Cada coluna usa uma projeção diferente dos dados. Os vetores `W` e as fases `b` são gerados no `fit` e permanecem fixos.

A ideia é criar várias formas diferentes de observar os mesmos dados. O Perceptron continua sendo linear, mas passa a trabalhar em um espaço de características muito mais rico.

Também uso as escalas:

- `0.5`
- `1.0`
- `2.0`
- `4.0`

As menores escalas geram variações mais suaves, enquanto as maiores permitem capturar detalhes menores e variações mais rápidas. Isso ajuda principalmente em padrões mais complexos, como duas luas e espiral.

---

## Visão geral da transformação

De forma conceitual, a função `phi` produz algo próximo de:

`phi(X) = [X_padronizado, X², x_i*x_j, cos(W^T X + b)]`

A `phi` não realiza a classificação. Ela apenas cria uma nova representação dos dados.

Depois dessa transformação, o Perceptron recebe as novas colunas e aprende sozinho os pesos necessários para combinar essas características e separar as classes.
