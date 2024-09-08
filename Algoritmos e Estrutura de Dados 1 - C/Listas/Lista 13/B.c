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

int tamanho(Pilha *p) {
if (p == NULL) return-1;
return p->topo;
}

void limpar(Pilha *p) {
free(p);
p = NULL;
}

int Iguais(Pilha *p1, Pilha *p2){
    if (p1 == NULL && p2 == NULL) {
        return 1; // Ambas as pilhas são nulas, portanto, são consideradas iguais
    }

    if ((p1 == NULL && p2 != NULL) || (p1 != NULL && p2 == NULL)) {
        return 0; // Uma das pilhas é nula e a outra não, portanto, são diferentes
    }

    if (tamanho(p1) != tamanho(p2)) {
        return 0; // Tamanhos diferentes, portanto, são diferentes
    }

    Valor valor1, valor2;
    Pilha *temp1 = criar();
    Pilha *temp2 = criar();

    int iguais = 1; // Inicialmente, assumimos que as pilhas são iguais

    while (pilhaVazia(p1)) {
        pop(p1, &valor1);
        pop(p2, &valor2);

        if (valor1.valor != valor2.valor) {
            // Se encontrar valores diferentes, as pilhas não são iguais
            iguais = 0;
        }

        push(temp1, valor1);
        push(temp2, valor2);
    }

    // Restaurar as pilhas originais
    while (pilhaVazia(temp1)) {
        pop(temp1, &valor1);
        pop(temp2, &valor2);
        push(p1, valor1);
        push(p2, valor2);
    }

    limpar(temp1);
    limpar(temp2);

    return iguais;
}

int main() { 
    Pilha *p1 = criar();
    Pilha *p2 = criar();
    int Resultado;
    int valores[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int valoresdiferentes[] = {7, 6, 5, 4, 3, 2, 1, 0};

    for(int i = 0; i < 8; i++) {
        Valor valor;
        valor.valor = valores[i];
        push(p1, valor);
        push(p2, valor);
    }

    Resultado = Iguais(p1, p2);

    if(Resultado == 1) {
        printf("As pilhas sao iguais\n");
    } else {
        printf("As pilhas nao sao iguais\n");
    }

    for(int i = 0; i < 8; i++){
        Valor valor;
        valor.valor = valoresdiferentes[i];
        push(p1, valor);
    }

    Resultado = Iguais(p1, p2);

    if(Resultado == 1) {
        printf("As pilhas sao iguais\n");
    } else {
        printf("As pilhas nao sao iguais\n");
    }

    // Lembre-se de liberar a memória das pilhas
    limpar(p1);
    limpar(p2);

    return 0;
}