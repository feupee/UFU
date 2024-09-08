#include <stdio.h>
#include <stdlib.h>

int *createAndFillArray(int size, int value) {
    int *array = (int *)malloc(size * sizeof(int));  // Alocar memória para o vetor

    if (array == NULL) {
        printf("Erro na alocação de memória\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        array[i] = value;  // Preencher o vetor com o valor fornecido
    }

    return array;
}

int main() {
    int size, value;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    printf("Digite o valor a ser preenchido: ");
    scanf("%d", &value);

    int *resultArray = createAndFillArray(size, value);

    printf("Vetor alocado dinamicamente e preenchido:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", resultArray[i]);
    }

    // Libere a memória alocada quando não precisar mais do vetor
    free(resultArray);

    return 0;
}