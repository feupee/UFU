#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    float num1;

    printf("Escreva um numero: ");
    scanf("%f", &num1);

    if (num1 < 0) {
        printf("Numero invalido");
        exit(0);
    }

    if (num1 > 0) {
        printf("O logaritmo do numero eh: %.2f", log10(num1));
    }

    return 0;
}