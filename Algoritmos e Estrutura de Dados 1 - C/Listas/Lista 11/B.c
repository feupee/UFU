#include "ListaRecursiva.c"

int main(){

    int soma = 0;
    // Criando a lista Recursiva
    No *lista = criaNo(1);
    // Adicionando elementos à lista
    inserirNo(lista, 2);
    inserirNo(lista, 3);
    inserirNo(lista, 4);
    // Imprimindo a lista
    printf("Lista: ");
    imprimeLista(lista);
    printf("A soma eh: ");
    somarElementos(lista, soma);

    return 0;
}