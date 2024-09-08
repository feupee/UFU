#include <stdlib.h>
#include "Lista.h"

typedef struct lista {
    int total;
    Aluno valores[MAX];
} Lista;

Lista *criar() {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l != NULL)
        l->total = 0;
    return l;
}

void limpar(Lista *l) {
    if (l != NULL)
        l->total = 0;
}

int inserirInicio(Lista *l, Aluno it) {
    int i;
    if (l == NULL)
        return 2;
    if (listaCheia(l) == 0)
        return 1;
    for (i = l->total; i > 0; i--) {
        l->valores[i] = l->valores[i - 1];
    }
    l->valores[0] = it;
    l->total++;
    return 0;
}

int inserirFim(Lista *l, Aluno it) {
    if (l == NULL)
        return 2; 
    if (l->total == MAX)
        return 1; 

    if (l->total < MAX) {
        l->valores[l->total] = it;
        l->total++;
        return 0; 
    }

    return 1; 
}

int buscarItemChave(Lista *l, int chave, Aluno *retorno) {
    int i;
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    for (i = 0; i < l->total; i++) {
        if (l->valores[i].mat == chave) {
            *retorno = l->valores[i];
            return 0;
        }
    }
    return -1;
}

int listaVazia(Lista *l) {
    if (l == NULL)
        return 2;
    if (l->total == 0)
        return 0;
    else
        return 1;
}

int removerInicio(Lista *l) {
    int i;
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    for (i = 0; i < l->total - 1; i++) {
        l->valores[i] = l->valores[i + 1];
    }
    l->total--;
    return 0;
}

int removerFim(Lista *l) {
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    l->total--;
    return 0;
}

int listaCheia(Lista *l) {
    if (l == NULL)
        return 2;
    if (l->total == MAX)
        return 0;
    else
        return 1;
}

void mostrar(Lista *l) {
    int i;
    if (l != NULL) {
        printf("[");
        for (i = 0; i < l->total; i++) {
            printf(" {%d, ", l->valores[i].mat);
            printf("%s, ", l->valores[i].nome);
            printf("%.2f} ", l->valores[i].n1);
        }
        printf("]\n");
    }
}

// Exercício A

int inserirPosicao(Lista *l, Aluno it, int pos) {
    if (l == NULL)
        return 2; 
    if (pos < 0 || pos > l->total || l->total >= MAX) {
        return 3; 
    }

    for (int i = l->total; i > pos; i--) {
        l->valores[i] = l->valores[i - 1];
    }

    l->valores[pos] = it;
    l->total++;
    return 0;
}

int removerPosicao(Lista *l, int pos){
    if (l == NULL)
        return 2;
    if (pos < 0 || pos >= MAX) {
        return 3; 
    }
    l->total--;

    for (int i = pos; i < l->total; i++) {
        l->valores[i] = l->valores[i + 1];
    }
    return 0;
}

int removerItem(Lista *l, Aluno it) {
    if (l == NULL)
        return 2;

    int pos = -1;
    for (int i = 0; i < l->total; i++) {
        if (l->valores[i].mat == it.mat) {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        return 4; 

    return removerPosicao(l, pos);
}

int buscarPosicao(Lista *l, int posicao, Aluno *it) {
    if (l == NULL)
        return 2; 
    if (posicao < 0 || posicao >= l->total) {
        return 3; 
    }

    *it = l->valores[posicao];
    return 0; 
}

//Exercicio B

int ContemItem(Lista *l, Aluno it) {
    if (l == NULL)
        return 2; 

    for (int i = 0; i < l->total; i++) {
        if (l->valores[i].mat == it.mat) {
            return 0; 
        }
    }

    return 1; 
}

Lista *Reversa(Lista *l) {
    if (l == NULL)
        return NULL;

    Lista *listaReversa = criar(); 

    for (int i = l->total - 1; i >= 0; i--) {
        inserirFim(listaReversa, l->valores[i]); 
    }

    return listaReversa;
}


int contaItem(Lista *l, Aluno it) {
    if (l == NULL)
        return -1; 

    int contador = 0;

    for (int i = 0; i < l->total; i++) {
        if (l->valores[i].mat == it.mat) {
            contador++;
        }
    }

    return contador;
}

//Exercício D

#define TAMANHO_INICIAL 10

Lista2 *cria2() { // Corrigido para "cria2"
    Lista2 *l = (Lista2 *)malloc(sizeof(Lista2));
    if (l != NULL) {
        l->total = 0;
        l->capacidade = TAMANHO_INICIAL;
        l->valores = (Aluno *)malloc(TAMANHO_INICIAL * sizeof(Aluno));

        if (l->valores == NULL) {
            free(l);
            return NULL;
        }
    }
    return l;
}

// Função para redimensionar a lista, dobrando a capacidade
static int redimensionar(Lista2 *l) {
    int novaCapacidade = l->capacidade * 2;
    Aluno *novosValores = (Aluno *)realloc(l->valores, novaCapacidade * sizeof(Aluno));

    if (novosValores != NULL) {
        l->valores = novosValores;
        l->capacidade = novaCapacidade;
        return 1; // Redimensionamento bem-sucedido
    }

    return 0; // Falha no redimensionamento
}

int inserirFim2(Lista2 *l, Aluno it) {
    if (l == NULL)
        return 2;

    if (l->total == l->capacidade) {
        // A lista está cheia, redimensione antes de inserir
        if (!redimensionar(l))
            return 1; // Falha ao redimensionar
    }

    l->valores[l->total] = it;
    l->total++;
    return 0;
}

void mostrar2(Lista2 *l) {
    int i;
    if (l != NULL) {
        printf("[");
        for (i = 0; i < l->total; i++) {
            printf(" {%d, ", l->valores[i].mat);
            printf("%s, ", l->valores[i].nome);
            printf("%.2f} ", l->valores[i].n1);
        }
        printf("]\n");
    }
}