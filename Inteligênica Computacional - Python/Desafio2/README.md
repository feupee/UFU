# Desafio 2 — Ativação e Inicialização em Redes Profundas

## 1. Objetivo

O objetivo do desafio foi desenvolver uma estratégia de **função de ativação** e **inicialização de pesos e biases** capaz de funcionar bem em redes MLP com diferentes profundidades, sem alterar a arquitetura, o otimizador, a taxa de aprendizado ou o número de épocas.

A avaliação considera três profundidades:

- `L = 4`
- `L = 16`
- `L = 48`

e três conjuntos de dados:

- MNIST
- Fashion-MNIST
- CIFAR-10

Ao todo, são nove tarefas públicas.

O treinamento é fixo, utilizando:

- SGD
- learning rate `0.05`
- momentum `0.9`
- batch size `128`
- 3 épocas
- sementes `0`, `1` e `2`

A solução, portanto, ficou concentrada nas funções:

```python
def ativacao(x):
    ...

def inicializar(W,b,fan_in,fan_out,camada,n_camadas):
    ...
```

---

## 2. Desenvolvimento da solução

Os primeiros experimentos compararam diferentes funções de ativação, entre elas ReLU, LeakyReLU, HardTanh e variações da `tanh`.

A função de ativação determina como a saída de cada neurônio é transformada antes de seguir para a próxima camada. Em redes profundas, essa escolha influencia diretamente a propagação das ativações e dos gradientes.

Algumas dessas alternativas apresentaram bom comportamento em redes rasas, mas perderam estabilidade principalmente em redes com 48 camadas. Isso acontece porque pequenas alterações na escala das ativações e dos pesos se acumulam ao atravessar muitas camadas. Se a escala diminui repetidamente, ativações e gradientes podem se tornar muito pequenos, dificultando o aprendizado. Se cresce demais, os valores propagados podem se tornar excessivos.

Esse problema também depende da função de ativação. A `tanh`, por exemplo, pode entrar em uma região de saturação quando recebe valores de grande magnitude. Nessa região, sua derivada se aproxima de zero e o gradiente propagado para as camadas anteriores diminui.

Por isso, não bastava escolher uma ativação que funcionasse bem em redes rasas. Era necessário encontrar uma combinação entre ativação e inicialização que mantivesse uma escala adequada de ativações e gradientes ao longo da rede.

A função que apresentou o comportamento global mais consistente foi:

```python
torch.tanh(x)
```

A `tanh` limita a saída ao intervalo entre `-1` e `1` e é centrada em zero. Apesar do risco de saturação, esse efeito pôde ser controlado por meio de uma inicialização adequada.

---

## 3. Inicialização ortogonal e regime profundo

Para as redes mais profundas, a técnica que apresentou maior estabilidade foi a **inicialização ortogonal**.

De forma resumida, essa inicialização cria matrizes de pesos que tendem a preservar melhor a direção e a escala do sinal durante as multiplicações sucessivas entre camadas. Isso ajuda a reduzir o risco de desaparecimento ou explosão do sinal.

Também foi utilizado um parâmetro chamado `gain`, responsável por controlar a escala inicial dos pesos.

Os melhores valores encontrados para o regime profundo foram aproximadamente:

```text
gain = 1.0247
bias std = 0.00448
```

A inicialização das camadas ocultas ficou próxima de:

```python
torch.nn.init.orthogonal_(W,gain=1.0247)
b.normal_(0.0,0.00448)
```

Essa configuração apresentou bom comportamento principalmente em redes L16 e L48.

---

## 4. Tratamento específico do CIFAR-10

Depois que as redes profundas passaram a funcionar de forma mais estável, o principal gargalo passou a ser o CIFAR-10 em L4.

A diferença estrutural entre os conjuntos de dados foi importante:

```text
MNIST/Fashion-MNIST:
28 × 28 = 784 entradas

CIFAR-10:
32 × 32 × 3 = 3072 entradas
```

Como a função de inicialização recebe `fan_in`, foi possível identificar entradas de maior dimensionalidade sem utilizar diretamente o nome do dataset.

Na primeira camada do CIFAR-10 L4, a melhor estratégia foi uma **inicialização normal escalada pelo número de entradas**:

```python
W.normal_(0.0,gain / math.sqrt(fan_in))
```

Essa técnica reduz a magnitude dos pesos à medida que aumenta o número de entradas da camada, evitando que a soma de muitas entradas produza valores excessivamente altos logo no início da rede.

Após os testes, o melhor ganho encontrado foi:

```text
gain = 0.795
```

Para MNIST e Fashion-MNIST em L4, a inicialização ortogonal continuou sendo a melhor opção:

```text
primeira camada: gain = 0.95
camadas ocultas: gain = 0.99
camada de saída: gain = 0.50
```

---

## 5. Evolução dos resultados

A combinação de `tanh` com inicialização ortogonal crítica produziu uma primeira solução robusta, mas ainda com dificuldades no CIFAR.

Depois dos primeiros ajustes, o score chegou aproximadamente a:

```text
S = 87.9
```

A partir daí, a estratégia deixou de alterar toda a rede e passou a refinar apenas os principais gargalos.

### Refinamento do CIFAR-10 L4

Foram testados valores cada vez mais próximos para o ganho da primeira camada do CIFAR-10 L4, mantendo o restante da configuração fixo.

O melhor valor permaneceu em:

```text
0.795
```

Com isso, o CIFAR L4 chegou a:

```text
s_t = 0.75
```

e o score global subiu para aproximadamente:

```text
S = 97.3
```

### Refinamento do CIFAR-10 L48

O próximo gargalo foi o CIFAR L48.

Foi feita uma busca específica para:

- ganho da primeira camada;
- ganho das camadas ocultas;
- ganho da camada de saída.

A melhor configuração encontrada foi:

```text
primeira camada CIFAR L48: gain = 0.70
camadas ocultas L48:       gain = 1.015
camada de saída L48:       gain = 1.00
```

O resultado do CIFAR L48 passou de aproximadamente:

```text
s_t = 0.80
```

para:

```text
s_t = 1.09
```

sem prejudicar MNIST e Fashion-MNIST.

Com isso, o score global chegou a:

```text
S = 99.5
```

---

## 6. Tentativas finais de melhoria

Depois de alcançar `99.5`, o único gargalo relevante continuou sendo o CIFAR L4.

Foram realizados testes adicionais com:

- ganhos ultrafinos próximos de `0.795`;
- inicialização normal;
- inicialização uniforme;
- inicialização ortogonal;
- distribuição Rademacher;
- normalização das linhas da matriz de pesos;
- bias positivo e negativo na primeira camada;
- diferentes desvios-padrão para os biases das camadas ocultas;
- novos ajustes conjuntos dos ganhos de L4.

A distribuição **Rademacher** utiliza pesos com apenas duas magnitudes possíveis, positiva e negativa, enquanto a inicialização uniforme sorteia valores dentro de um intervalo fixo.

A **normalização por linha** foi utilizada para fazer cada neurônio começar com pesos de mesma norma, reduzindo diferenças de escala entre os neurônios.

Apesar disso, nenhum desses testes superou consistentemente a configuração já encontrada.

As buscas finais retornaram repetidamente aos mesmos valores, indicando que a solução havia atingido uma região bastante estável.

---

## 7. Configuração final

A solução final utiliza:

### Ativação

```python
torch.tanh(x)
```

### L4

MNIST e Fashion-MNIST:

```text
primeira camada: orthogonal, gain = 0.95
camadas ocultas: orthogonal, gain = 0.99
saída:            orthogonal, gain = 0.50
```

CIFAR-10:

```text
primeira camada:
normal, std = 0.795 / sqrt(fan_in)
```

### L16

```text
camadas ocultas:
orthogonal, gain ≈ 1.0247

bias:
normal, std ≈ 0.00448

saída:
orthogonal, gain = 1.00
```

### L48

```text
primeira camada CIFAR:
orthogonal, gain = 0.70

primeira camada MNIST/Fashion:
orthogonal, gain ≈ 1.0247

camadas ocultas:
orthogonal, gain = 1.015

saída:
orthogonal, gain = 1.00
```

---

## 8. Resultado final

O resultado final obtido foi:

```text
MNIST L4       s_t = 1.25
MNIST L16      s_t = 1.02
MNIST L48      s_t = 1.25

Fashion L4     s_t = 1.25
Fashion L16    s_t = 1.03
Fashion L48    s_t = 1.25

CIFAR-10 L4    s_t = 0.75
CIFAR-10 L16   s_t = 1.02
CIFAR-10 L48   s_t = 1.09
```

Resultado global:

```text
média = 1.10
mínimo = 0.75
ESCORE S = 99.5
```

---

## 9. Uso de GPU

Durante os primeiros testes, o tempo de execução tornou-se elevado porque cada avaliação completa exige treinamento em vários datasets, profundidades e sementes.

Para reduzir esse tempo, os experimentos finais foram executados utilizando GPU.

O próprio harness já detecta automaticamente se CUDA está disponível:

```python
DEVICE = torch.device("cuda" if torch.cuda.is_available() else "cpu")
```

Quando CUDA está disponível, os dados e a rede são automaticamente movidos para a GPU.

O ambiente utilizado nos experimentos finais foi:

```text
PyTorch 2.7.1+cu118
CUDA
```

Foi utilizado um ambiente virtual separado:

```powershell
python -m venv .venv-gpu
.\.venv-gpu\Scripts\Activate.ps1
```

Para verificar se a GPU está sendo reconhecida:

```powershell
python -c "import torch; print(torch.__version__); print(torch.cuda.is_available()); print(torch.cuda.get_device_name(0) if torch.cuda.is_available() else 'CPU')"
```

Durante a execução, também é possível acompanhar a utilização da GPU com:

```powershell
nvidia-smi -l 1
```

A utilização da GPU não altera a lógica da solução. Ela serve apenas para acelerar o treinamento e, consequentemente, tornar viável a execução das diversas buscas de parâmetros realizadas durante o desenvolvimento.

---

## 10. Dependências

As principais dependências são:

```text
torch
torchvision
```

O `torch` é utilizado para:

- operações com tensores;
- construção da rede;
- cálculo de gradientes;
- inicialização dos pesos;
- treinamento em CPU ou GPU.

O `torchvision` é utilizado pelo harness para carregar:

- MNIST;
- Fashion-MNIST;
- CIFAR-10.

O restante das bibliotecas utilizadas, como `math`, `json`, `argparse`, `os` e `time`, faz parte da biblioteca padrão do Python.

### Instalação para CPU

```powershell
pip install torch torchvision
```

### Instalação utilizada com CUDA 11.8

```powershell
python -m pip install --upgrade pip

pip install torch==2.7.1 torchvision --index-url https://download.pytorch.org/whl/cu118
```

---

## 11. Organização dos arquivos

Para executar a solução são necessários dois arquivos principais:

```text
Desafio2/
├── harness_desafio2.py
└── desafio2_nome.py
```

O `harness_desafio2.py` é o avaliador fornecido pelo professor.

O arquivo `desafio2_nome.py` contém a solução desenvolvida, incluindo as funções:

```python
def ativacao(x):
    ...

def inicializar(W,b,fan_in,fan_out,camada,n_camadas):
    ...
```

---

## 12. Como executar

Abra o terminal no diretório do projeto.

### Ativar o ambiente com GPU

```powershell
.\.venv-gpu\Scripts\Activate.ps1
```

### Executar a avaliação completa

```powershell
python .\harness_desafio2.py .\desafio2_nome.py
```

A execução completa utiliza:

- 100% dos dados;
- 3 épocas;
- 3 sementes;
- todas as 9 tarefas públicas.

### Executar no modo rápido

```powershell
python .\harness_desafio2.py .\desafio2_nome.py --rapido
```

O modo rápido utiliza uma fração menor dos dados e serve apenas para verificar se o código está funcionando.

Ele não deve ser utilizado como resultado final.

### Recalibrar baseline e referência

```powershell
python .\harness_desafio2.py --calibrar
```

O harness salva esses resultados em cache para evitar que baseline e referência sejam recalculados em todas as execuções.

### Executar tarefas ocultas

Caso o arquivo privado do professor esteja disponível:

```powershell
python .\harness_desafio2.py .\desafio2_nome.py --ocultas
```

---

## 13. Conclusão

O principal aprendizado do desafio foi que uma única escala de inicialização não apresentou o mesmo comportamento para redes com profundidades muito diferentes.

Nas redes profundas, foi necessário controlar cuidadosamente a propagação das ativações e dos gradientes para evitar desaparecimento ou crescimento excessivo do sinal. A combinação entre `tanh` e inicialização ortogonal mostrou o comportamento mais estável nesse cenário.

Nas redes rasas, principalmente no CIFAR-10, a maior dimensionalidade da entrada exigiu uma inicialização específica para a primeira camada.

A solução final surgiu, portanto, da combinação entre:

- uma função de ativação estável;
- inicialização ortogonal em redes profundas;
- escalas diferentes conforme a profundidade;
- tratamento específico para entradas de alta dimensionalidade;
- refinamento experimental dos parâmetros.

Após sucessivas buscas locais e comparações entre diferentes técnicas de inicialização, o melhor resultado reproduzível obtido foi:

```text
S = 99.5
```

As tentativas posteriores de refinamento retornaram repetidamente para a mesma configuração, motivo pelo qual esse resultado foi adotado como solução final.
