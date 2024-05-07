#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int excluir(Fila *f);

int main()
{
    Fila *f = criar();

    inserir(f, 10);
    inserir(f, -2);
    inserir(f, 0);
    inserir(f, 2);
    inserir(f, -66);
    mostrar(f);
    excluir(f);
    printf("\n\nFila sem numeros negativos: \n");
    mostrar(f);
    return 0;
}

int excluir(Fila *f){
    if(f == NULL) return 1;
    if(filaVazia(f) == 0) return 2;

    int valor;
    int qnt = tamanho(f);
    while(qnt > 0){
        remover2(f, &valor);
        if(valor > 0 || valor == 0) inserir(f, valor);
        qnt--;
    }
    return 0;
}
