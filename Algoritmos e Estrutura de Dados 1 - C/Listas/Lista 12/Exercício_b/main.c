#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

Fila *intercala(Fila *f1, Fila *f2);

int main()
{
    Fila *f1 = criar();
    Fila *f2 = criar();

    inserir(f1, 30);
    inserir(f2, 10);
    inserir(f1, 20);
    inserir(f2, 40);
    inserir(f1, 50);
    mostrar(f1);
    printf("\n\n\n");
    mostrar(f2);
    printf("\n\n\n");
    Fila *f3 = intercala(f1, f2);
    mostrar(f3);
}

Fila *intercala(Fila *f1, Fila *f2){
    if(f1 == NULL) return f2;
    if(f2 == NULL) return f1;
    Fila *f3 = criar();
    int valor;
    while(filaVazia(f1) != 0){

        if(remover2(f1, &valor) == 0) inserir(f3, valor);
        if(remover2(f2, &valor) == 0) inserir(f3, valor);
    }
    while(filaVazia(f2) != 0){
        if(remover2(f2, &valor) == 0) inserir(f3, valor);
    }
    return f3;
}


