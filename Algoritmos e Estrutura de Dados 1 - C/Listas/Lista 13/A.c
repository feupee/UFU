#define MAX 100
#include <stdio.h>
#include <stdlib.h>

typedef struct valor {
    int valor;
} Valor;

typedef struct pilha {
    int topo;
    Valor Dados[MAX];
} Pilha;

//Exercício A

Pilha *criar(){
   Pilha *p = (Pilha*)malloc(sizeof(Pilha));
   p->topo = 0;
   return p;
}

int pilhaVazia(Pilha *p){
    if (p == NULL) return 2;
    if (p->topo == 0) return 0;
    else return 1;
}
int pilhaCheia(Pilha *p){
    if (p == NULL) return 2;
    if (p->topo == MAX) return 0;
    else return 1;
}

void mostrar(Pilha *p){
    if(p != NULL){
        printf("\nLista:");
        int i;
        for(i=0;i<p->topo;i++){
            printf("[");
            printf("%d",p->Dados[i].valor);
            printf("]");
        }
        
    }
}

int push(Pilha *p, Valor it){
    if(p == NULL) return 2;
    if(pilhaCheia(p) == 0) return 1;
    p->Dados[p->topo] = it;
    p->topo++;
    return 0;
}

int pop(Pilha *p, Valor *it){
    if(p == NULL) return 2;
    if(pilhaVazia(p) == 0) return 1;
    *it = p->Dados[p->topo-1];
    p->topo--;
    return 0;
}

int main(){

    //push(11), push(34), pop, pop,push(23),push(45), 
    //pop, push(121), push(22), pop, pop.

    Pilha *p = criar(); // Crie uma nova pilha

    Valor valor;

    valor.valor = 11;
    push(p, valor);
    printf("\nPush: %d", valor.valor);

    valor.valor = 34;
    push(p, valor);
    printf("\nPush: %d", valor.valor);

    mostrar(p);

    pop(p, &valor);
    printf("\nPop: %d", valor.valor);
    mostrar(p);

    pop(p, &valor);
    printf("\nPop: %d", valor.valor);
    mostrar(p);

    valor.valor = 23;
    push(p, valor);
    printf("\nPush: %d", valor.valor);

    valor.valor = 45;
    push(p, valor);
    printf("\nPush: %d", valor.valor);

    mostrar(p);

    pop(p, &valor);
    printf("\nPop: %d", valor.valor);
    mostrar(p);

    valor.valor = 121;
    push(p, valor);
    printf("\nPush: %d", valor.valor);

    valor.valor = 22;
    push(p, valor);
    printf("\nPush: %d", valor.valor);

    mostrar(p);

    pop(p, &valor);
    printf("\nPop: %d", valor.valor);
    mostrar(p);

    pop(p, &valor);
    printf("\nPop: %d", valor.valor);
    mostrar(p);

    return 0;
}