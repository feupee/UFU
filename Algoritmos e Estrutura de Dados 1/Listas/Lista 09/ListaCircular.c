#include "Lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no {
Aluno valor;
struct no *prox;
}No;
typedef struct lista {
No *inicio;
}ListaCircular;

Lista *criar() {
Lista *l =(Lista*)malloc(sizeof(Lista));l->inicio = NULL;
return l;
}
void limpar(Lista *l) {while (listaVazia(l)!=0)removerInicio(l);free(l);
l = NULL;
}

int tamanho(Lista *l) {if (l == NULL) return-1;if (listaVazia(l) ==0)return 0;No *noLista = l->inicio;int cont = 0;
do {
cont++;
noLista = noLista->prox;} while (noLista !=l->inicio);return cont;
}

void mostrar(Lista *l) {
if (l != NULL) {
printf("[");
if (listaVazia(l) != 0){No *noLista = l->inicio;do {
printf(" {%d, ",noLista->valor.mat);printf("%s, ",noLista->valor.nome);printf("%.2f} ",noLista->valor.n1);noLista = noLista->prox;} while (noLista !=l->inicio);}
printf("]\n");
}
}

int listaVazia(Lista *l){if (l == NULL) return 2;if (l->inicio == NULL)return 0;
else
return 1;
}

int inserirInicio(Lista *l, Aluno it){if (l == NULL) return 2;
No *no = (No *)malloc(sizeof(No));no->valor = it;
if (listaVazia(l) == 0) {
l->inicio = no;
no->prox = no;
}else {
No *temp = l->inicio;
while (temp->prox != l->inicio)temp = temp->prox;
temp->prox = no;
no->prox = l->inicio;
l->inicio = no;
}
return 0;
}

int inserirFim(Lista *l, Aluno it){if (l == NULL) return 2;
No *no = (No *)malloc(sizeof(No));no->valor = it;
if (listaVazia(l) == 0) {
l->inicio = no;
no->prox = no;
}else {
No *temp = l->inicio;
while (temp->prox != l->inicio)temp = temp->prox;
temp->prox = no;
no->prox = l->inicio;
}
return 0;
}

int removerInicio(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    No *no = l->inicio;

    if (no->prox == l->inicio) {
        // Handle the case where there is only one element in the list
        free(no);
        l->inicio = NULL;
        return 0;
    }

    while (no->prox != l->inicio)
        no = no->prox;

    No *temp = l->inicio;
    no->prox = temp->prox;
    l->inicio = temp->prox;
    free(temp);
    return 0;
}

int removerFim(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    No *anterior = NULL, *no = l->inicio;

    if (no->prox == l->inicio) {
        free(no);
        l->inicio = NULL;
        return 0;
    }

    while (no->prox != l->inicio) {
        anterior = no;
        no = no->prox;
    }

    anterior->prox = no->prox;
    free(no);
    return 0;
}

int removerPosicao(Lista *l, int pos) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    int tamanhoLista = tamanho(l);

    if (pos < 0 || pos >= tamanhoLista) {
        return 3; 
    }

    No *anterior = NULL, *no = l->inicio;

    while ((no->prox != l->inicio) && (pos > 0)) {
        anterior = no;
        no = no->prox;
        pos--;
    }

    anterior->prox = no->prox;
    free(no);
    return 0;
}

int buscarItem(Lista *l, int chave, Aluno* it) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *no = l->inicio;
    while ((no->prox != l->inicio) && ((no->valor).mat != chave)) no = no->prox;
    if ((no->valor).mat != chave)
        return 1;
    else {
        *it = no->valor;
        return 0;
    }
}

//Exercício B

void removerElementoCentral(Lista *l) {
    if (l == NULL || listaVazia(l) != 1) {
        printf("Lista vazia ou com menos de 2 elementos. Nada a fazer.\n");
        return;
    }
    
    int tam = tamanho(l);
    int posicaoCentral = tam / 2;
    
    No *anterior = NULL;
    No *atual = l->inicio;
    int pos = 0;
    
    while (pos < posicaoCentral) {
        anterior = atual;
        atual = atual->prox;
        pos++;
    }
    
    if (anterior == NULL) {
        // Remover o primeiro elemento (posição central)
        l->inicio = atual->prox;
    } else {
        // Remover um elemento no meio da lista
        anterior->prox = atual->prox;
    }

}

//Exercício C

int removerItem(Lista *l, int matricula) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    No *anterior = NULL, *no = l->inicio;

    do {
        if ((no->valor).mat == matricula) {
            // Encontrou a matrícula, vamos removê-la
            if (anterior == NULL) {
                // Remover o primeiro elemento da lista
                l->inicio = no->prox;
            } else {
                // Remover um elemento no meio da lista
                anterior->prox = no->prox;
            }
            free(no);
            return 0; // Aluno removido com sucesso
        }

        anterior = no;
        no = no->prox;
    } while (no != l->inicio);

    return 4; // Matrícula não encontrada
}