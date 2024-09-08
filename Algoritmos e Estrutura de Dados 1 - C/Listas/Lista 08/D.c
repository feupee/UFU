#include <stdio.h>
#include "ListaEncad.c"

int main() {

    Lista* minhaLista = criar();

    // Inserir elementos na lista
    Aluno aluno1 = {1, "Felipe", 9.5};
    Aluno aluno2 = {2, "Salibão", 8.0};
    Aluno aluno3 = {3, "MG", 7.5};
    Aluno aluno4 = {4, "Grande Caike Lendário", 8.5};

    inserirInicio(minhaLista, aluno1);
    inserirFim(minhaLista, aluno2);
    inserirFim(minhaLista, aluno3);
    inserirFim(minhaLista, aluno4);

    printf("Lista original:\n");
    mostrar(minhaLista);

    int n = 2; // Altere o valor de n conforme necessário

    removerNPrimeirosNos(minhaLista, n);

    printf("Lista apos remover os %d primeiros nos:\n", n);
    mostrar(minhaLista);

    return 0;
}