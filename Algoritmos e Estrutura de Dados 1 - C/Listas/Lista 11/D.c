#include "ListaRecursiva.c"

int main(){

    // Criando a lista Recursiva
    No *lista = criaNo(1);
    // Adicionando elementos à lista
    inserirNo(lista, 4);
    inserirNo(lista, 3);
    inserirNo(lista, 4);
    // Imprimindo a lista
    printf("Lista: ");
    imprimeLista(lista);
    printf("Lista apos exclusao dos elementos: ");
    removerOcorrencia(lista, 4);
    imprimeLista(lista);
    return 0;
}