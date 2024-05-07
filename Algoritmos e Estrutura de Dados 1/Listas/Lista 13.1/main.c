#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Pilha.h"

//Inverter Fila
void inverte_fila(Fila *f) {
    if (f != NULL) {
        Pilha *p = criarP();
        int termo;
        while (filaVazia(f) != 0) {
            consultarF(f,&termo);
            remover(f);
            push(p,termo);
        }
        while (pilhaVazia(p) != 0) {
            pop(p,&termo);
            inserir(f,termo);
        }
        mostrarF(f);
    }
}

//Fura Fila
int furaFila(Fila *f, int termo) {
    if (f == NULL) return 2;
    int t = tamanhoF(f);
    inserir(f,termo);
    int x;
    while (t > 0) {
        consultarF(f,&x);
        remover(f);
        inserir(f,x);
        t--;
    }
    return 0;
}

char *extraiTermo(char *s, char r[], int *i) {
    char c = s[(*i)];
    while ((c != ' ')&&(c != '\0')) {
        strncat(r,&c,1);
        (*i)++;
        c = s[(*i)];
    }
    (*i)++;
    return r;
}

//Resolve posfixa.
int resolvePosfixa(char *exp) {
    Pilha *p = criarP();
    int i = 0;
    int op1, op2;
    int r;
    while (exp[i] != '\0') {
        char termo[5] = "";
        extraiTermo(exp,termo,&i);
        if ((strcmp(termo,"/") != 0)&&(strcmp(termo,"-") != 0)&&(strcmp(termo,"+") != 0)&&(strcmp(termo,"*") != 0))
            push(p,atoi(termo));
        else {
            pop(p,&op1);
            pop(p,&op2);
            if (strcmp(termo,"/") == 0) r = op2 / op1;
            else if (strcmp(termo,"-") == 0) r = op2 - op1;
            else if (strcmp(termo,"+") == 0) r = op2 + op1;
            else if (strcmp(termo,"*") == 0) r = op2 * op1;
            push(p,r);
        }
    }
    pop(p,&r);
    return r;
}

int main() {
    //FILA USANDO PILHAS
    Fila *f = criarF();
    inserir(f,10);
    inserir(f,20);
    inserir(f,30);
    inserir(f,40);
    inserir(f,50);
    inserir(f,60);
    inserir(f,70);
    inserir(f,80);
    mostrarF(f);
    printf("Removendo...\n");
    remover(f);
    mostrarF(f);

    //INVERTENDO FILA
    inverte_fila(f);

    //FURANDO FILA
    furaFila(f,200);
    mostrarF(f);

    //RESOLVE POSFIXA
    char pa[30] = "4 3 * 8 4 / 6 - +";
    puts(pa);
    printf("\n");
    int r = resolvePosfixa(pa);
    printf("Resultado: %d.\n",r);

    return 0;
}
