#include <stdio.h>
#include <stdlib.h>
#include "ListaSeq.c"

int main() {
    // Criar uma lista com capacidade inicial de 10 elementos
    Lista *lista = criar(10);

    Aluno aluno1 = {101, "Alice", 9.5};
    Aluno aluno2 = {102, "Bob", 8.0};
    Aluno aluno3 = {103, "Carol", 7.5};

    // Inserir elementos na lista
    inserirFim(lista, aluno1);
    inserirFim(lista, aluno2);
    inserirFim(lista, aluno3);

    // Imprimir a lista
    printf("Lista:\n");
    mostrar(lista);

    // Inserir mais elementos para verificar o redimensionamento automático
    for (int i = 4; i <= 15; i++) {
        Aluno novoAluno = {i, "Novo Aluno", 7.0};
        inserirFim(lista, novoAluno);
    }

    // Imprimir a lista novamente
    printf("\nLista apos insercao de mais elementos:\n");
    mostrar(lista);

    // Liberar a memória alocada
    limpar(lista);
    free(lista);

    return 0;
}