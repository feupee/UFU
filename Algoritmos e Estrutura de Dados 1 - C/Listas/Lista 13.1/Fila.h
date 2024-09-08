#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define MAX 100
typedef struct fila Fila;

Fila *criarF();
void limparF(Fila *f);
int inserir(Fila *f, int it);
int remover(Fila *f);
int consultarF(Fila *f, int *it);
int tamanhoF(Fila *f);
int filaVazia(Fila *f);
int filaCheia(Fila *f);
void mostrarF(Fila *f);

#endif // FILA_H_INCLUDED
