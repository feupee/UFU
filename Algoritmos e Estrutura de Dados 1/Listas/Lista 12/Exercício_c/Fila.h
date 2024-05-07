#define MAX 100

typedef struct fila Fila;

Fila *criar();
void limpar(Fila *f);
int inserir(Fila *f, int it);
int remover2(Fila *f, int *it);
int filaVazia(Fila *f);
int filaCheia(Fila *f);
int tamanho(Fila *f);
int mostrar(Fila *f);
int consultar(Fila *f, int *it);
int remover(Fila *f);

