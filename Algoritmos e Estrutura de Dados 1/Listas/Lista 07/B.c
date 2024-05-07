#include <stdio.h>
#include "ListaSeq.c"

int main() {
    Lista *lista = criar();

    Aluno aluno1 = {101, "Alice", 9.5};
    Aluno aluno2 = {102, "Bob", 8.0};
    Aluno aluno3 = {103, "Carol", 7.5};
    inserirFim(lista, aluno1);
    inserirFim(lista, aluno2);
    inserirFim(lista, aluno3);

    //Contem Item

    printf("\n");

    Aluno alunoBusca = {102, "Bob", 8.0};

    if (ContemItem(lista, alunoBusca) == 0) {
        printf("O item esta presente na lista.\n");
    } else {
        printf("O item não está na lista.\n");
    }

    printf("\n");

    //Lista Reversa

    Lista *listaReversa = Reversa(lista);
    printf("Lista Normal: ");
    mostrar(lista);
    printf("\n");
    printf("Lista Reversa: ");
    mostrar(listaReversa);

    printf("\n");

    //contaItens

    Aluno itemContagem = {103, "Carol", 7.5};
    int contador = contaItem(lista, itemContagem);
    printf("O item aparece %d vezes na lista.\n", contador);

    printf("\n");

    return 0;
}