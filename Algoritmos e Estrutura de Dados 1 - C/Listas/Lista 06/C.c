#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "C.h"

// Função para criar uma matriz vazia com o número especificado de linhas e colunas
Matriz criarMatriz(int linhas, int colunas) {
    Matriz matriz;
    matriz.linhas = linhas;
    matriz.colunas = colunas;
    matriz.elementos = (float **)malloc(linhas * sizeof(float *));
    for (int i = 0; i < linhas; i++) {
        matriz.elementos[i] = (float *)malloc(colunas * sizeof(float));
    }
    return matriz;
}

// Função para destruir uma matriz, liberando a memória alocada
void destruirMatriz(Matriz *matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        free(matriz->elementos[i]);
    }
    free(matriz->elementos);
    matriz->linhas = 0;
    matriz->colunas = 0;
}

// Função para atribuir um valor a um elemento da matriz
void atribuirElemento(Matriz *matriz, int linha, int coluna, float valor) {
    if (linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas) {
        matriz->elementos[linha][coluna] = valor;
    }
}

// Função para acessar o valor de um elemento da matriz
float acessarElemento(const Matriz *matriz, int linha, int coluna) {
    if (linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas) {
        return matriz->elementos[linha][coluna];
    } else {
        return 0.0; // Valor padrão se os índices estiverem fora dos limites
    }
}

// Função para retornar o número de linhas da matriz
int numeroLinhas(const Matriz *matriz) {
    return matriz->linhas;
}

// Função para retornar o número de colunas da matriz
int numeroColunas(const Matriz *matriz) {
    return matriz->colunas;
}

// Função para preencher a matriz com números aleatórios dentro de um intervalo
void preencherAleatoriamente(Matriz *matriz, float minimo, float maximo) {
    srand(time(NULL));
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            float aleatorio = ((float)rand() / RAND_MAX) * (maximo - minimo) + minimo;
            matriz->elementos[i][j] = aleatorio;
        }
    }
}

// Função para somar duas matrizes e armazenar o resultado em uma terceira matriz
Matriz somarMatrizes(const Matriz *matriz1, const Matriz *matriz2) {
    if (matriz1->linhas != matriz2->linhas || matriz1->colunas != matriz2->colunas) {
        printf("As matrizes não podem ser somadas. Elas têm dimensões diferentes.\n");
        exit(1);
    }

    Matriz resultado = criarMatriz(matriz1->linhas, matriz1->colunas);

    for (int i = 0; i < matriz1->linhas; i++) {
        for (int j = 0; j < matriz1->colunas; j++) {
            resultado.elementos[i][j] = matriz1->elementos[i][j] + matriz2->elementos[i][j];
        }
    }

    return resultado;
}

// Função para exibir uma matriz
void exibirMatriz(const Matriz *matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            printf("%.2f\t", matriz->elementos[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Exemplo de uso do TAD para matrizes

    // Criar duas matrizes
    Matriz matriz1 = criarMatriz(3, 3);
    Matriz matriz2 = criarMatriz(3, 3);

    // Preencher as matrizes com números aleatórios entre 0 e 1
    preencherAleatoriamente(&matriz1, 0.0, 1.0);
    preencherAleatoriamente(&matriz2, 0.0, 1.0);

    printf("Matriz 1:\n");
    exibirMatriz(&matriz1);

    printf("\nMatriz 2:\n");
    exibirMatriz(&matriz2);

    // Somar as matrizes
    Matriz resultadoSoma = somarMatrizes(&matriz1, &matriz2);

    printf("\nResultado da soma:\n");
    exibirMatriz(&resultadoSoma);

    // Destruir as matrizes para liberar a memória alocada
    destruirMatriz(&matriz1);
    destruirMatriz(&matriz2);
    destruirMatriz(&resultadoSoma);

    return 0;
}