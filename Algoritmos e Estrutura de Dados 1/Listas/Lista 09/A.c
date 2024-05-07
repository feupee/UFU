#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int matricula;
    char nome[50];
} Aluno;

typedef struct no {
    Aluno valor;
    struct no *prox;
} No;

typedef struct lista {
    No *final;
} ListaCircular;

void inicializarLista(ListaCircular *l) {
    l->final = NULL;
}

int listaVazia(ListaCircular *l) {
    return l->final == NULL;
}

void inserirInicio(ListaCircular *l, Aluno it) {
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;

    if (listaVazia(l)) {
        l->final = no;
        no->prox = no; // O novo nó aponta para si mesmo
    } else {
        no->prox = l->final->prox; // O próximo do novo nó aponta para o início da lista
        l->final->prox = no; // Atualizamos o próximo do último nó para o novo nó
    }
}

void imprimirLista(ListaCircular *l) {
    if (listaVazia(l)) {
        printf("A lista esta vazia.\n");
        return;
    }

    No *atual = l->final->prox; // Começa do início da lista
    do {
        printf("Matricula: %d, Nome: %s\n", atual->valor.matricula, atual->valor.nome);
        atual = atual->prox;
    } while (atual != l->final->prox); // Termina quando voltar ao início
}

int main() {
    ListaCircular lista;
    inicializarLista(&lista);

    Aluno aluno1 = {1, "Caio"};
    Aluno aluno2 = {2, "Felipe"};
    Aluno aluno3 = {3, "Matheus"};

    inserirInicio(&lista, aluno1);
    inserirInicio(&lista, aluno2);
    inserirInicio(&lista, aluno3);

    imprimirLista(&lista);

    return 0;
}


