#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura do nó da lista
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função para criar um novo nó
No* criaNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro na alocação de memória\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

No* inserirNo(No* lista, int valor) {
    if (lista == NULL) {
        return criaNo(valor);
    } else {
        lista->prox = inserirNo(lista->prox, valor);
        return lista;
    }
}

int somarElementos(No *lista, int soma){
    if (lista == NULL) {
        printf("%d",soma);
        return 0;
    }else{
    soma += lista->valor;
    return somarElementos(lista->prox, soma);
    }
}

int listaVazia(No *lista){
    if(lista == NULL)return 2;
    else return 1;
}

void imprimirLista(No* lista) {
    No* current = lista;
    while (current != NULL) {
        printf("%d", current->valor);
        current = current->prox;
    }
    printf("\n");
}

int imprimiReversa(No *lista) {
    if (lista != NULL) {
        if (listaVazia(lista) != 0) {
            No *no = lista;
            imprimiReversa(no->prox);
            printf("<- %d ", no->valor);
            return 1;
        } else {
            printf("NULL ");
            return 0;
        }
    } else {
        printf("NULL ");
        return 0;
    }
}

struct No* removerOcorrencia(struct No* lista, int valor) {
    if(lista != NULL && lista->valor == valor) {
        struct No* temp = lista;
        lista = lista->prox;
        free(temp);
    }

    if (lista == NULL) {
        return lista;
    }

    No* current = lista;
    while (current->prox != NULL) {
        if (current->prox->valor == valor) {
            struct No* temp = current->prox;
            current->prox = current->prox->prox;
            free(temp);
        } else {
            current = current->prox;
        }
    }

    return lista;
}
// Função para adicionar um nó no final da lista
int retornaUltimo(No *l, int *it) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *n = l;
    if (n->prox == NULL) {
        *it = n->valor;
        return 0;
    } else return retornaUltimo(n->prox, it);
}

// Função para imprimir a lista recursiva
void imprimeLista(No* lista) {
    if (lista == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", lista->valor);
    imprimeLista(lista->prox);
}

void freeList(No* lista) {
    while (lista != NULL) {
        No* temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

int listToBinary(No* lista) {
    int decimal = 0;
    int power = 0;
    No* current = lista;

    while (current != NULL) {
        decimal += current->valor << power;
        power++;
        current = current->prox;
    }

    return decimal;
}

No* addIntToBinary(No* binary_list, int num_to_add) {
    if (num_to_add == 0) {
        return binary_list;
    }

    int carry = num_to_add % 2;
    num_to_add /= 2;

    if (binary_list == NULL) {
        binary_list = inserirNo(binary_list, carry);
    } else {
        int sum = binary_list->valor + carry;
        carry = sum / 2;
        binary_list->valor = sum % 2;
    }

    binary_list = addIntToBinary(binary_list, num_to_add);

    return binary_list;
}

No* binaryToList(const char* binary_str) {
    No* binary_list = NULL;
    int length = strlen(binary_str);

    for (int i = 0; i < length; i++) {
        if (binary_str[i] == '0' || binary_str[i] == '1') {
            int bit = binary_str[i] - '0';
            binary_list = inserirNo(binary_list, bit);
        } else {
            printf("Entrada inválida. Use apenas 0s e 1s.\n");
            freeList(binary_list);
            return NULL;
        }
    }

    return binary_list;
}