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

    //Inserir Posicao

    Aluno alunoInserir = {104, "David", 8.5};
    int posicaoInserir = 1; 
    int resultadoInserir = inserirPosicao(lista, alunoInserir, posicaoInserir);

    if (resultadoInserir == 0) {
        printf("Insercao na posicao %d realizada com sucesso.\n", posicaoInserir);
    } else if (resultadoInserir == 1) {
        printf("A lista esta cheia. Insercao nao realizada.\n");
    } else if (resultadoInserir == 3) {
        printf("Posicao invalida. Insercao nao realizada.\n");
    }

    printf("Adicao Lista: \n");
    mostrar(lista);
    printf("\n");

    //Remover Posicao

    int posicaoRemover = 2; 
    int resultadoRemover = removerPosicao(lista, posicaoRemover);

    if (resultadoInserir == 0) {
        printf("Remocao na posicao %d realizada com sucesso.\n", posicaoRemover);
    } else if (resultadoRemover == 2) {
        printf("A lista esta vazia. Insercao nao realizada.\n");
    } else if (resultadoRemover == 3) {
        printf("Posicao invalida. Remocao nao realizada.\n");
    }

    printf("Remocao Lista: \n");
    mostrar(lista);
    printf("\n");

    //Remover Aluno

    Aluno alunoRemover = {104, "David", 8.5};

    int resultadorRemoverItem = removerItem(lista, alunoRemover);
    
    if (resultadorRemoverItem == 0) {
        printf("Remocao do aluno %s realizada com sucesso.\n", alunoRemover.nome);
    } else if (resultadorRemoverItem == 2) {
        printf("A lista esta vazia. Insercao nao realizada.\n");
    } else if (resultadorRemoverItem == 3) {
        printf("Aluno nao encontrado. Remocao nao realizada.\n");
    }

    printf("Remover Aluno: \n");
    mostrar(lista);
    printf("\n");

    //Buscar Posicao

    Aluno alunoEncontrado;
    int posicaoDesejada = 0; // Defina a posição desejada como 0 para buscar o primeiro aluno
    int resultadoBusca = buscarPosicao(lista, posicaoDesejada, &alunoEncontrado);

    if (resultadoBusca == 0) {
    // A busca foi bem-sucedida, e "alunoEncontrado" contém o valor encontrado (primeiro aluno).
    printf("Aluno encontrado: Matricula=%d, Nome=%s, Nota=%.2f\n", alunoEncontrado.mat, alunoEncontrado.nome, alunoEncontrado.n1);
    } else if (resultadoBusca == 2) {
        printf("A lista esta vazia. Insercao nao realizada.\n");
    } else if (resultadoBusca == 3) {
        printf("Aluno nao encontrado. Busca interrompida.\n");
    }

    printf("Busca: \n");
    mostrar(lista);
    printf("\n");

    return 0;
}