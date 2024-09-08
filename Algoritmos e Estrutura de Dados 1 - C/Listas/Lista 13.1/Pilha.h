#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha Pilha;
Pilha *criarP();
void limparP(Pilha *p);
int push(Pilha *p, int it);
int pop(Pilha *p, int *it);
int consultarP(Pilha *p, int *it);
int tamanhoP(Pilha *p);
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);

void mostrarP(Pilha *p);

#endif // PILHA_H_INCLUDED
