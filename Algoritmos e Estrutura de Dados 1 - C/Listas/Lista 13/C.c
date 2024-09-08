#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct valor {
    char letra;
} Valor;

typedef struct pilha {
    int topo;
    Valor dados[MAX];
} Pilha;

Pilha *criar() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

int pilhaVazia(Pilha *p) {
    if (p == NULL) return 2;
    if (p->topo == 0) return 1;
    else return 0;
}

int pilhaCheia(Pilha *p) {
    if (p == NULL) return 2;
    if (p->topo == MAX) return 1;
    else return 0;
}

int push(Pilha *p, char letra) {
    if (p == NULL) return 2;
    if (pilhaCheia(p)) return 1;
    p->dados[p->topo].letra = letra;
    p->topo++;
    return 0;
}

int pop(Pilha *p, char *letra) {
    if (p == NULL) return 2;
    if (pilhaVazia(p)) return 1;
    p->topo--;
    *letra = p->dados[p->topo].letra;
    return 0;
}

void limpar(Pilha *p) {
    free(p);
}

int VerificaDelimitadores(char Str[]) {
    Pilha *p = criar();
    int i = 0;
    int k = strlen(Str);

    while (i < k) {
        if (Str[i] == '(') {
            push(p, Str[i]);
        } else if (Str[i] == ')') {
            char topo;
            if (pop(p, &topo) != 0 || topo != '(') {
                limpar(p);
                return 1; 
            }
        }
        i++;
    }

    int resultado = pilhaVazia(p) ? 0 : 1;
    limpar(p);
    return resultado;
}

int main() {
    char str[50];

    printf("Digite a string: ");
    fgets(str, 50, stdin);

    if (VerificaDelimitadores(str) == 0) {
        printf("E valida\n");
    } else {
        printf("Nao e valida\n");
    }

    return 0;
}