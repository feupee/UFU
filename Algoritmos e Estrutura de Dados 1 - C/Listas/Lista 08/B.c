#include <stdio.h>
#include <stdlib.h>
#include "ListaEncad.c"

int main() {
    Lista* lista1 = criar();
    Lista* lista2 = criar();

    // Inserindo elementos nas duas listas
    Aluno aluno1 = {1, "Felipe", 9.5};
    Aluno aluno2 = {2, "Jose", 8.0};
    Aluno aluno3 = {3, "Marcelo", 7.5};
    Aluno aluno4 = {4, "Caio", 8.5};

    inserirInicio(lista1, aluno1);
    inserirFim(lista1, aluno2);
    inserirInicio(lista2, aluno3);
    inserirFim(lista2, aluno4);

    // Testando a função ContemItem
    Aluno itemProcurado = {2, "Jose", 8.0};
    int resultado = ContemItem(lista1, itemProcurado);

    if (resultado == 0) {
        printf("O item esta presente na lista.\n");
    } else if (resultado == 1) {
        printf("O item nao esta presente na lista.\n");
    } else {
        printf("Lista invalida.\n");
    }

    // Testando a função Concatena
    printf("Lista 1:\n");
    mostrar(lista1);
    printf("Lista 2:\n");
    mostrar(lista2);

    Lista* listaConcatenada = Concatena(lista1, lista2);

    printf("Lista concatenada:\n");
    mostrar(listaConcatenada);

    return 0;
}