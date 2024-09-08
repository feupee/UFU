#include <stdio.h>
#include <stdlib.h>
#include "B.h"

// Função para criar um conjunto vazio
Conjunto criarConjunto() {
    Conjunto conjunto;
    conjunto.elementos = NULL;
    conjunto.tamanho = 0;
    return conjunto;
}

// Função para verificar se um elemento pertence ao conjunto
int pertenceConjunto(const Conjunto *conjunto, int elemento) {
    for (int i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] == elemento) {
            return 1; // O elemento pertence ao conjunto
        }
    }
    return 0; // O elemento não pertence ao conjunto
}

// Função para inserir um elemento no conjunto
void inserirElemento(Conjunto *conjunto, int elemento) {
    if (!pertenceConjunto(conjunto, elemento)) {
        conjunto->tamanho++;
        conjunto->elementos = (int *)realloc(conjunto->elementos, conjunto->tamanho * sizeof(int));
        conjunto->elementos[conjunto->tamanho - 1] = elemento;
    }
}

// Função para remover um elemento do conjunto
void removerElemento(Conjunto *conjunto, int elemento) {
    int encontrado = 0;
    for (int i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] == elemento) {
            encontrado = 1;
            for (int j = i; j < conjunto->tamanho - 1; j++) {
                conjunto->elementos[j] = conjunto->elementos[j + 1];
            }
            conjunto->tamanho--;
            conjunto->elementos = (int *)realloc(conjunto->elementos, conjunto->tamanho * sizeof(int));
            break;
        }
    }
}

// Função para realizar a união de dois conjuntos
Conjunto uniaoConjuntos(const Conjunto *conjunto1, const Conjunto *conjunto2) {
    Conjunto resultado = criarConjunto();

    for (int i = 0; i < conjunto1->tamanho; i++) {
        inserirElemento(&resultado, conjunto1->elementos[i]);
    }

    for (int i = 0; i < conjunto2->tamanho; i++) {
        inserirElemento(&resultado, conjunto2->elementos[i]);
    }

    return resultado;
}

// Função para realizar a interseção de dois conjuntos
Conjunto intersecaoConjuntos(const Conjunto *conjunto1, const Conjunto *conjunto2) {
    Conjunto resultado = criarConjunto();

    for (int i = 0; i < conjunto1->tamanho; i++) {
        if (pertenceConjunto(conjunto2, conjunto1->elementos[i])) {
            inserirElemento(&resultado, conjunto1->elementos[i]);
        }
    }

    return resultado;
}

// Função para realizar a diferença entre dois conjuntos (A - B)
Conjunto diferencaConjuntos(const Conjunto *conjunto1, const Conjunto *conjunto2) {
    Conjunto resultado = criarConjunto();

    for (int i = 0; i < conjunto1->tamanho; i++) {
        if (!pertenceConjunto(conjunto2, conjunto1->elementos[i])) {
            inserirElemento(&resultado, conjunto1->elementos[i]);
        }
    }

    return resultado;
}

// Função para liberar a memória alocada para um conjunto
void liberarConjunto(Conjunto *conjunto) {
    free(conjunto->elementos);
    conjunto->elementos = NULL;
    conjunto->tamanho = 0;
}

// Função para exibir os elementos de um conjunto
void exibirConjunto(const Conjunto *conjunto) {
    printf("{ ");
    for (int i = 0; i < conjunto->tamanho; i++) {
        printf("%d ", conjunto->elementos[i]);
    }
    printf("}\n");
}

int main() {
    Conjunto conjunto1 = criarConjunto();
    Conjunto conjunto2 = criarConjunto();

    inserirElemento(&conjunto1, 1);
    inserirElemento(&conjunto1, 2);
    inserirElemento(&conjunto1, 3);

    inserirElemento(&conjunto2, 3);
    inserirElemento(&conjunto2, 4);
    inserirElemento(&conjunto2, 5);

    printf("Conjunto 1: ");
    exibirConjunto(&conjunto1);

    printf("Conjunto 2: ");
    exibirConjunto(&conjunto2);

    Conjunto uniao = uniaoConjuntos(&conjunto1, &conjunto2);
    printf("União: ");
    exibirConjunto(&uniao);

    Conjunto intersecao = intersecaoConjuntos(&conjunto1, &conjunto2);
    printf("Interseção: ");
    exibirConjunto(&intersecao);

    Conjunto diferenca = diferencaConjuntos(&conjunto1, &conjunto2);
    printf("Diferença (Conjunto1 - Conjunto2): ");
    exibirConjunto(&diferenca);

    liberarConjunto(&conjunto1);
    liberarConjunto(&conjunto2);
    liberarConjunto(&uniao);
    liberarConjunto(&intersecao);
    liberarConjunto(&diferenca);

    return 0;
}