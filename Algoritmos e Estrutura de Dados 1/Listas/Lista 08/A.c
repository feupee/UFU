#include <stdio.h>
#include "ListaEncad.c" // Certifique-se de incluir o arquivo de cabeçalho corretamente

int main() {
    Lista *minhaLista = criar();

    // Inserindo elementos
    Aluno aluno1 = {1, "Felipe", 9.5};
    Aluno aluno2 = {2, "Jose", 8.0};
    Aluno aluno3 = {3, "Marcelo", 7.5};

    inserirInicio(minhaLista, aluno1);
    inserirFim(minhaLista, aluno2);
    inserirPosicao(minhaLista, aluno3, 1);

    printf("Lista apos insercao:\n");
    mostrar(minhaLista);

    // Removendo elementos
    removerPosicao(minhaLista, 1);
    printf("Lista apos remover posicao 1:\n");
    mostrar(minhaLista);

    Aluno aluno4 = {4, "David", 8.5};
    removerItem(minhaLista, aluno4);
    printf("Lista apos remover aluno com matricula 4:\n");
    mostrar(minhaLista);

    // Buscando elemento
    Aluno resultado;
    int posicao = 1;
    int resultadoBusca = buscarPosicao(minhaLista, posicao, &resultado);

    if (resultadoBusca == 0) {
        printf("Aluno na posicao %d:\n", posicao);
        printf("Matricula: %d\n", resultado.mat);
        printf("Nome: %s\n", resultado.nome);
        printf("Nota: %.2f\n", resultado.n1);
    } else {
        printf("Posicao invalida ou elemento nao encontrado.\n");
    }

    return 0;
}