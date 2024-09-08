#include <stdlib.h>
#include "Fila.h"
#include "Pilha.h"

typedef struct fila {
    Pilha *p1;
    Pilha *p2;
}Fila;

Fila *criarF() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->p1 = criarP();
    f->p2 = criarP();
    return f;
}

void limparF(Fila *f) {
    limparP(f->p1);
    limparP(f->p2);
}

int inserir(Fila *f, int it) {
    if (f == NULL) return 2;
    push(f->p1,it);
}

int remover(Fila *f) {
    if (f == NULL) return 2;
    int valor;
    while (pilhaVazia(f->p1) != 0) {
        pop(f->p1,&valor);
        push(f->p2,valor);
    }
    pop(f->p2,&valor);
    while (pilhaVazia(f->p2) != 0) {
        pop(f->p2,&valor);
        push(f->p1,valor);
    }
}
int consultarF(Fila *f, int *it) {
    if (f == NULL) return 2;
    int valor;
    while (pilhaVazia(f->p1) != 0) {
        pop(f->p1,&valor);
        push(f->p2,valor);
    }
    consultarP(f->p2,it);
    while (pilhaVazia(f->p2) != 0) {
        pop(f->p2,&valor);
        push(f->p1,valor);
    }
}

int tamanhoF(Fila *f) {
    if (f == NULL) return -1;
    return tamanhoP(f->p1);
}

int filaVazia(Fila *f) {
    if (f == NULL) return 2;
    return pilhaVazia(f->p1);
}

int filaCheia(Fila *f) {
    if (f == NULL) return 2;
    return pilhaCheia(f->p1);
}

void mostrarF(Fila *f) {
    if (f == NULL) return 2;
    int valor;
    while (pilhaVazia(f->p1) != 0) {
        pop(f->p1,&valor);
        push(f->p2,valor);
    }
    mostrarP(f->p2);
    while (pilhaVazia(f->p2) != 0) {
        pop(f->p2,&valor);
        push(f->p1,valor);
    }
}
