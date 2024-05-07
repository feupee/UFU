#include "Pilha.h"
#include <stdlib.h>

Pilha *criar(){
   Pilha *p = (Pilha*)malloc(sizeof(Pilha));
   p->topo = 0;
   return p;
}   

void mostrar(Pilha *p){
    if(p != NULL){
        printf("[");
        int i;
        for(i=0;i<p->topo;i++){
            printf(" {%d, ",p->dados[i].mat);
            printf("%s, ",p->dados[i].nome);
            printf("%.2f}\n",p->dados[i].n1);
        }
        printf("]\n");
    }
}

int push(Pilha *p, Aluno it){
    if(p == NULL) return 2;
    if(pilhaCheia(p) == 0) return 1;
    p->dados[p->topo] = it;
    p->topo++;
    return 0;
}

int pop(Pilha *p, Aluno *it){
    if(p == NULL) return 2;
    if(pilhaVazia(p) == 0) return 1;
    *it = p->dados[p->topo-1];
    p->topo--;
    return 0;
}