#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int *v, int size) {
    for (int i = 0; i < size; i++) {
        v[i] = -1;
    }
}

void printaVetor(int *v, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }
}

int main() {
    int sorteados[50], apostados[50], acertos[50], count, num, numAcertos = 0;
    float taxaAcerto;
    srand(time(NULL));

    // Sortear números
    preencheVetor(sorteados, 50);
    for (int i = 0; i < 50; i++) {
        num = rand() % 100;
        count = 1;
        for (int j = 0; j < i; j++) {
            if (num == sorteados[j]) {
                count = 0;
                i--;
            }
        }
        if (count == 1) sorteados[i] = num;
    }

    // Apostar números
    for (int i = 0; i < 50; i++) {
        do {
            printf("Insira o numero %d: ", i + 1);
            scanf("%d", &apostados[i]);
            if (apostados[i] < 0 || apostados[i] > 100) printf("Numero invalido\n");
        } while (apostados[i] < 0 || apostados[i] > 100);
    }

    // Comparar números e contar acertos
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            if (apostados[i] == sorteados[j]) {
                acertos[numAcertos] = apostados[i];
                numAcertos++;
                break; // Não é necessário continuar procurando
            }
        }
    }

    // Calcular taxa de acerto
    taxaAcerto = (float)numAcertos / 50 * 100;

    // Exibir resultados
    printf("Numeros sorteados: ");
    printaVetor(sorteados, 50);
    printf("\n");

    printf("Numeros apostados: ");
    printaVetor(apostados, 50);
    printf("\n");

    printf("Numeros corretos: ");
    printaVetor(acertos, numAcertos);
    printf("\n");

    printf("Taxa de acerto: %.2f%%\n", taxaAcerto);

    return 0;
}