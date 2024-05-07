#include <stdio.h>

void multiplyVet(int size, int Vet[], int scalar) {
    for (int i = 0; i < size; i++) {
        Vet[i] *= scalar;
    }
}

int main() {
    int size = 5;
    int Vet[5];
    int scalar;

    // Preenchendo o Vet com valores
    for (int i = 0; i < size; i++) {
        printf("Digite o valor do Vet %d: ", i);
        scanf("%d", &Vet[i]);
    }

    // Lendo o escalar
    printf("Digite o valor escalar: ");
    scanf("%d", &scalar);

    // Multiplicando o Vet pelo escalar
    multiplyVet(size, Vet, scalar);

    // Imprimindo o Vet original
    printf("Vet original: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", Vet[i]);
    }

    // Imprimindo o Vet após a multiplicação
    printf("\nVet após multiplicação: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", Vet[i]);
    }

    return 0;
}