#include "ListaCircular.c"

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

    removerElementoCentral(minhaLista);

    printf("Lista após a remoção do elemento central:\n");
    mostrar(minhaLista);

    return 0;
}





