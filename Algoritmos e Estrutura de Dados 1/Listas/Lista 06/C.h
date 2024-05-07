typedef struct {
    int linhas;
    int colunas;
    float **elementos;
} Matriz;

Matriz criarMatriz(int linhas, int colunas);
void destruirMatriz(Matriz *matriz);
void atribuirElemento(Matriz *matriz, int linha, int coluna, float valor);
float acessarElemento(const Matriz *matriz, int linha, int coluna);
int numeroLinhas(const Matriz *matriz);
int numeroColunas(const Matriz *matriz);
void preencherAleatoriamente(Matriz *matriz, float minimo, float maximo);
Matriz somarMatrizes(const Matriz *matriz1, const Matriz *matriz2);
void exibirMatriz(const Matriz *matriz);
