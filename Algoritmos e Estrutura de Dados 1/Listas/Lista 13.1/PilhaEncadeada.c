#include <stdio.h>
#include "Pilha.h"

typedef struct no {
    char *valor;
    struct no *proximo;
}No;


typedef struct pilha {
    No *topo;
}Pilha;

Pilha *criarP() {
   Pilha *p = (Pilha *)malloc(sizeof(Pilha));
   p->topo = NULL;
   return p;
}

void limparP(Pilha *p) {
   if (p == NULL) return;
   while (pilhaVazia(p) != 0) pop(p,NULL);
   free(p);
   p = NULL;
}

int push(Pilha *p, int it) {
    if (p == NULL) return 2;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    no->proximo = p->topo;
    p->topo = no;
    return 0;
}

int pop(Pilha *p, int *it) {
    if (p == NULL) return 2;
    if (pilhaVazia(p) == 0) return 1;
    No *temp = p->topo;
    if (it != NULL) *it = temp->valor;
    p->topo = temp->proximo;
    free(temp);
    return 0;
}

int consultarP(Pilha *p, int *it) {
    if (p == NULL) return 2;
    if (pilhaVazia(p) == 0) return 1;
    No *temp = p->topo;
    *it = temp->valor;
    return 0;
}

int tamanhoP(Pilha *p) {
    if (p == NULL) return -1;
    int ct = 0;
    No *no = p->topo;
    while (no != NULL) {
       ct++;
       no = no->proximo;
    }
    return ct;
}

int pilhaVazia(Pilha *p) {
    if (p == NULL) return 2;
    if (p->topo == NULL)
        return 0;
    else
        return 1;
}

int pilhaCheia(Pilha *p) {
    return 1;
}

void mostrarP(Pilha *p) {
    if (p != NULL) {
       printf("[");
       No *no = p->topo;
       while (no != NULL) {
           printf(" %d ",no->valor);
           no = no->proximo;
       }
       printf("]\n");
    }
}



