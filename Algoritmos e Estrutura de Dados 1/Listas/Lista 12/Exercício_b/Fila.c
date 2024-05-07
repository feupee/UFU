#include <stdio.h>
#include "Fila.h"

typedef struct fila{
    int inicio, fim, qtd;
    int valores[MAX];
}Fila;

Fila *criar(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;

    return f;
}

int inserir(Fila *f, int it){
    if(f== NULL)return 1;
    if(filaCheia(f) == 0)return 2;
    f->valores[f->fim] = it;
    f->fim = (f->fim+1)%MAX;
    f->qtd++;

    return 0;
}

int remover(Fila *f){
    if(f == NULL) return 1;
    if(filaVazia(f) == 0) return 2;

    f->qtd--;
    f->inicio = (f->inicio+1)%MAX;
    return 0;
}

int tamanho(Fila *f){
    if(f==NULL) return -1;
    return f->qtd;

}
int consultar(Fila *f, int *it){
    if(f == NULL) return 1;
    if(filaVazia(f) == 0) return 2;
    *it = f->valores[f->inicio];
    return 0;
}
int filaVazia(Fila *f){
    if(f == NULL) return 1;
    if(f->qtd == 0) return 0;
    return 1;
}

int filaCheia(Fila *f){
    if(f == NULL) return 2;
    if(f->qtd == MAX) return 0;
    return 1;
}
int mostrar(Fila *f){
    if(f != NULL){
        printf("[");
        int i = f->inicio;
        int q = f->qtd;
        while(q > 0){
            printf(" {%d}" , f->valores[i]);
            i = (i+1)%MAX;
            q--;
        }
        printf(" ]\n");
    }
}

int remover2(Fila *f, int *it){
    if(f == NULL) return 1;
    if(filaVazia(f) == 0) return 2;
    *it = f->valores[f->inicio];
    f->qtd--;
    f->inicio = (f->inicio+1)%MAX;
    return 0;
}
