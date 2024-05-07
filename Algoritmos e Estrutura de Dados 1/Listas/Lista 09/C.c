#include "ListaCircular.c"
#include <stdio.h>

int main() {
    Lista *minhaLista = criar();

    Aluno aluno1 = {1, "Caio", 90.0};
    Aluno aluno2 = {2, "Felipe", 85.5};
    Aluno aluno3 = {3, "Matheus", 78.2};
    Aluno aluno4 = {4, "Vanessa", 92.5};

    inserirInicio(minhaLista, aluno4);
    inserirInicio(minhaLista, aluno3);
    inserirInicio(minhaLista, aluno2);
    inserirInicio(minhaLista, aluno1);

    printf("Lista original:\n");
    mostrar(minhaLista);

    int matriculaParaRemover = 2; 

    int resultado = removerItem(minhaLista, matriculaParaRemover);

    if (resultado == 0) {
        printf("Aluno com matricula %d removido com sucesso.\n", matriculaParaRemover);
    } else if (resultado == 4) {
        printf("Aluno com matricula %d nao encontrado na lista.\n", matriculaParaRemover);
    } else {
        printf("Erro desconhecido ao remover o aluno.\n");
    }

    printf("Lista apos a remoção:\n");
    mostrar(minhaLista);

    return 0;
}

