#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct lista {
    No *inicio;
} Lista;

Lista *criar() {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

int contaOcorrencias(Lista *l, int elemento) {
    if (l == NULL || l->inicio == NULL) {
        return 0;
    }

    int contador = 0;
    No *atual = l->inicio;

    do {
        if (atual->valor == elemento) {
            contador++;
        }
        atual = atual->prox;
    } while (atual != l->inicio);

    return contador;
}

void inserirFimSemRepeticao(Lista *l, int elemento) {
    if (l == NULL) {
        return;
    }

    // Verifique se o elemento já existe na lista
    if (contaOcorrencias(l, elemento) == 0) {
        No *novoNo = (No *)malloc(sizeof(No));
        novoNo->valor = elemento;
        novoNo->prox = NULL;

        if (l->inicio == NULL) {
            // Lista vazia, o novo nó será o único nó na lista
            l->inicio = novoNo;
            novoNo->prox = novoNo; // Faz o nó apontar para si mesmo
        } else {
            // Encontre o último nó na lista
            No *ultimo = l->inicio;
            while (ultimo->prox != l->inicio) {
                ultimo = ultimo->prox;
            }
            // Insira o novo nó no final
            ultimo->prox = novoNo;
            novoNo->prox = l->inicio;
        }
    }
}

void mostrar(Lista *l) {
    if (l == NULL || l->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = l->inicio;
    printf("[");
    do {
        printf("%d", atual->valor);
        atual = atual->prox;
        if (atual != l->inicio) {
            printf(", ");
        }
    } while (atual != l->inicio);
    printf("]\n");
}

int main() {
    Lista *minhaLista = criar();

    // Inserir elementos na lista (exemplo)
    inserirFimSemRepeticao(minhaLista, 1);
    inserirFimSemRepeticao(minhaLista, 2);
    inserirFimSemRepeticao(minhaLista, 3);
    inserirFimSemRepeticao(minhaLista, 2); // Não será inserido novamente

    printf("Lista final: ");
    mostrar(minhaLista);

    return 0;
}
