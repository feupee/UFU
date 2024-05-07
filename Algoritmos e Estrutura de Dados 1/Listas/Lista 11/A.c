#include "ListaRecursiva.c"

int main(){

    // Criando a lista Recursiva
    No *lista = criaNo(1);
    // Adicionando elementos à lista
    inserirNo(lista, 2);
    inserirNo(lista, 3);
    inserirNo(lista, 4);
    // Imprimindo a lista
    printf("Lista: ");
    imprimeLista(lista);
    
    return 0;
}