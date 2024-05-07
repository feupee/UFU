#include <stdlib.h>
#include "Lista.h"

// Definição da estrutura do nó da lista
typedef struct no {
    Aluno valor;        // Valor armazenado no nó (um aluno)
    struct no *prox;    // Ponteiro para o próximo nó
} No;

// Definição da estrutura da lista encadeada
typedef struct lista {
    No *inicio;         // Ponteiro para o início da lista
} Lista;

// Função para criar uma nova lista
Lista* criar() {
    Lista *l = (Lista*)malloc(sizeof(Lista));  // Aloca memória para a lista
    l->inicio = NULL;   // Inicializa o início da lista como NULL (lista vazia)
    return l;
}

// Função para verificar se a lista está vazia
int listaVazia(Lista* l) {
    if (l == NULL)
        return 2;   // Retorna 2 se a lista for inválida
    if (l->inicio == NULL)
        return 0;   // Retorna 0 se a lista estiver vazia
    return 1;       // Retorna 1 se a lista contiver elementos
}

// Função para inserir um elemento no início da lista
int inserirInicio(Lista* l, Aluno it) {
    if (l == NULL)
        return 2;   // Retorna 2 se a lista for inválida
    No *no = (No*)malloc(sizeof(No));    // Aloca memória para o novo nó
    no->valor = it; // Atribui o valor do aluno ao novo nó
    no->prox = l->inicio;   // O novo nó aponta para o antigo início da lista
    l->inicio = no; // Atualiza o início da lista para o novo nó
    return 0;
}

// Função para inserir um elemento no fim da lista
int inserirFim(Lista* l, Aluno it) {
    if (l == NULL)
        return 2;   // Retorna 2 se a lista for inválida
    if (listaVazia(l) == 0)
        return inserirInicio(l, it);   // Se a lista estiver vazia, insere no início
    No *noLista = l->inicio;
    while (noLista->prox != NULL)
        noLista = noLista->prox;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}


// Função para remover o primeiro elemento da lista
int removerInicio(Lista* l) {
    if (l == NULL)
        return 2;   // Retorna 2 se a lista for inválida
    if (listaVazia(l) == 0)
        return 1;   // Retorna 1 se a lista estiver vazia
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    free(noLista);  // Libera a memória do nó removido
    return 0;
}

// Função para remover o último elemento da lista
int removerFim(Lista* l) {
    if (l == NULL)
        return 2;   // Retorna 2 se a lista for inválida
    if (listaVazia(l) == 0)
        return 1;   // Retorna 1 se a lista estiver vazia
    No *noAuxiliar = NULL;
    No *noLista = l->inicio;
    while (noLista->prox != NULL) {
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }
    if (noAuxiliar == NULL)
        l->inicio = NULL;
    else
        noAuxiliar->prox = NULL;
    free(noLista);  // Libera a memória do nó removido
    return 0;
}

// Função para buscar um elemento na lista com base na chave (matrícula)
int buscarItemChave(Lista* l, int chave, Aluno* retorno) {
    if (l == NULL)
        return 2;   // Retorna 2 se a lista for inválida
    No *noLista = l->inicio;
    while (noLista != NULL) {
        if (noLista->valor.mat == chave) {
            *retorno = noLista->valor;
            return 0;   // Retorna 0 se o item for encontrado
        }
        noLista = noLista->prox;
    }
    return 1;   // Retorna 1 se o item não for encontrado
}

// Função para limpar a lista, removendo todos os elementos
void limpar(Lista* l) {
    while (listaVazia(l) != 0)
        removerInicio(l);
}

// Função para mostrar os elementos da lista
void mostrar(Lista* l) {
    if (l != NULL) {
        printf("[");
        No *noLista = l->inicio;
        while (noLista != NULL) {
            printf(" {%d, ", noLista->valor.mat);
            printf("%s, ", noLista->valor.nome);
            printf("%.2f} ", noLista->valor.n1);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

//Exercício A

int inserirPosicao(Lista *l, struct aluno it, int pos) {
    if (l == NULL)
        return 2;
    if (pos < 0)
        return 3;

    if ((listaVazia(l) == 0) || (pos == 0))
        return inserirInicio(l, it);

    No *noLista = l->inicio;
    int p = 1;
    while ((noLista->prox != NULL) && (p != pos)) {
        p++;
        noLista = noLista->prox;
    }

    if (p != pos)
        return 4; // Posição inválida

    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int removerPosicao(Lista *l, int pos) {
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    if (pos < 0)
        return 3;

    if (pos == 0)
        return removerInicio(l);

    No *noLista = l->inicio;
    No *noAnterior = NULL;
    int p = 0;

    while ((noLista != NULL) && (p != pos)) {
        p++;
        noAnterior = noLista;
        noLista = noLista->prox;
    }

    if (p != pos || noLista == NULL)
        return 4; // Posição inválida

    noAnterior->prox = noLista->prox;
    free(noLista);
    return 0;
}

int removerItem(Lista *l, struct aluno it) {
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;

    No *noLista = l->inicio;
    No *noAnterior = NULL;

    while (noLista != NULL) {
        if (noLista->valor.mat == it.mat) {
            if (noAnterior == NULL) {
                // Remove o primeiro elemento da lista
                l->inicio = noLista->prox;
            } else {
                noAnterior->prox = noLista->prox;
            }
            free(noLista);
            return 0;
        }
        noAnterior = noLista;
        noLista = noLista->prox;
    }

    return 5; // Item não encontrado
}

int buscarPosicao(Lista *l, int posicao, struct aluno *retorno) {
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    if (posicao < 0)
        return 3;

    No *noLista = l->inicio;
    int p = 0;

    while ((noLista != NULL) && (p != posicao)) {
        p++;
        noLista = noLista->prox;
    }

    if (p != posicao || noLista == NULL)
        return 4; // Posição inválida

    *retorno = noLista->valor;
    return 0;
}

//Exercício B

int ContemItem(Lista* l, Aluno it) {
    if (l == NULL)
        return 2; 
    No* noLista = l->inicio;
    while (noLista != NULL) {
        if (noLista->valor.mat == it.mat) {
            return 0; 
        }
        noLista = noLista->prox;
    }
    return 1; 
}

Lista* Concatena(Lista* l1, Lista* l2) {
    if (l1 == NULL || l2 == NULL)
        return NULL; 
    Lista* novaLista = criar(); 

    No* noLista1 = l1->inicio;
    while (noLista1 != NULL) {
        inserirFim(novaLista, noLista1->valor);
        noLista1 = noLista1->prox;
    }

    No* noLista2 = l2->inicio;
    while (noLista2 != NULL) {
        inserirFim(novaLista, noLista2->valor);
        noLista2 = noLista2->prox;
    }

    return novaLista;
}

//Exercício C

void alunoComMaiorNota(Lista *l) {
    if (l == NULL || listaVazia(l) == 0) {
        printf("A lista esta vazia ou é invalida.\n");
        return;
    }

    No *noLista = l->inicio;
    Aluno alunoMaiorNota = noLista->valor; // Suponha que o primeiro aluno tem a maior nota
    float maiorNota = noLista->valor.n1;

    while (noLista != NULL) {
        if (noLista->valor.n1 > maiorNota) {
            maiorNota = noLista->valor.n1;
            alunoMaiorNota = noLista->valor;
        }
        noLista = noLista->prox;
    }

    printf("Aluno com a maior nota:\n");
    printf("Matricula: %d\n", alunoMaiorNota.mat);
    printf("Nome: %s\n", alunoMaiorNota.nome);
    printf("Nota: %.2f\n", maiorNota);
}

//Exercício D

void removerNPrimeirosNos(Lista *l, int n) {
    if (l == NULL || n < 0)
        return; // Retorna se a lista for inválida ou n for negativo

    while (n > 0 && listaVazia(l) != 0) {
        removerInicio(l);
        n--;
    }
}