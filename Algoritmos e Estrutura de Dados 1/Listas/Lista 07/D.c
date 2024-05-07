#include <stdio.h>
#include "ListaSeq.c"

int main() {
    Lista2 *lista = cria2(); // Cria uma lista com tamanho inicial 10

    if (lista == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    Aluno aluno1 = {101, "Alice", 9.5};
    Aluno aluno2 = {102, "Bob", 8.0};
    Aluno aluno3 = {103, "Carol", 7.5};

    Aluno aluno4 = {104, "Joao", 9.5};
    Aluno aluno5 = {105, "Andre", 8.0};
    Aluno aluno6 = {106, "Fernando", 7.5};

    Aluno aluno7 = {107, "Bruno", 9.5};
    Aluno aluno8 = {108, "Jose", 8.0};
    Aluno aluno9 = {109, "Ana", 7.5};

    Aluno aluno10 = {110, "Felipe", 9.5};
    Aluno aluno11 = {111, "Caio", 8.0};
    Aluno aluno12 = {112, "Henrique", 7.5};

    inserirFim2(lista, aluno1);
    inserirFim2(lista, aluno2);
    inserirFim2(lista, aluno3);
    inserirFim2(lista, aluno4);
    inserirFim2(lista, aluno5);
    inserirFim2(lista, aluno6);
    inserirFim2(lista, aluno7);
    inserirFim2(lista, aluno8);
    inserirFim2(lista, aluno9);
    inserirFim2(lista, aluno10);

    // Imprime a lista
    printf("Lista inicial: ");
    mostrar2(lista);
    printf("\n");

    inserirFim2(lista, aluno11);
    inserirFim2(lista, aluno12);

    // Imprime a lista alterada
    printf("Lista modificada: ");
    mostrar2(lista);
    printf("\n");


    return 0;
}