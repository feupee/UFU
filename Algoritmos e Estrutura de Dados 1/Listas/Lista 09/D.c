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

void inserirInicio(Lista *l, int valor) {
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = l->inicio;
    l->inicio = novoNo;
}

Lista *intersecaoListas(Lista *l1, Lista *l2) {
    Lista *intersecao = criar();

    No *atualL1 = l1->inicio;
    while (atualL1 != NULL) {
        No *atualL2 = l2->inicio;
        while (atualL2 != NULL) {
            if (atualL1->valor == atualL2->valor) {
                // O elemento está presente em ambas as listas, adicione-o à interseção
                inserirInicio(intersecao, atualL1->valor);
                break; // Pode parar de procurar na lista L2 após encontrar uma correspondência.
            }
            atualL2 = atualL2->prox;
        }
        atualL1 = atualL1->prox;
    }

    return intersecao;
}

void mostrar(Lista *l) {
    No *atual = l->inicio;
    printf("[");
    while (atual != NULL) {
        printf("%d", atual->valor);
        atual = atual->prox;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    Lista *L1 = criar();
    Lista *L2 = criar();

    // Inserir elementos em L1 e L2 (exemplo)
    inserirInicio(L1, 1);
    inserirInicio(L1, 2);
    inserirInicio(L1, 3);
    inserirInicio(L1, 4);

    inserirInicio(L2, 3);
    inserirInicio(L2, 4);
    inserirInicio(L2, 5);

    printf("Lista 1: ");
    mostrar(L1);

    printf("Lista 2: ");
    mostrar(L2);

    Lista *intersecao = intersecaoListas(L1, L2);

    printf("Intersecao: ");
    mostrar(intersecao);

    return 0;
}