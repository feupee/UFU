#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa que recebe um vetor de 10 números, converta cada
um desses números para binário e grave a sequência de 0s e 1s em um
arquivo texto. Cada número deve ser gravado em uma linha.
*/

void decimalToBinary(int number, char binaryString[]) {
    int i = 0;

    while (number > 0) {
        binaryString[i] = (number % 2) + '0';
        number /= 2;
        i++;
    }

    // Inverte a sequência de caracteres
    int j, k = i - 1;
    for (j = 0; j < i / 2; j++) {
        char temp = binaryString[j];
        binaryString[j] = binaryString[k];
        binaryString[k] = temp;
        k--;
    }

    binaryString[i] = '\0';
}

int main(){

    int vetor[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    char binaryString[33];  // Considerando que um int ocupa até 32 bits

    FILE *arquivo = fopen("binario.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        decimalToBinary(vetor[i], binaryString);
        fprintf(arquivo, "%s\n", binaryString);
    }

    fclose(arquivo);

    printf("Os números foram convertidos para binário e gravados no arquivo 'binario.txt'.\n");

    return 0;
}