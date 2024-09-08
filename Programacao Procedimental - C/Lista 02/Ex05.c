#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num1, resto;

    printf("Digite o numero: ");
    scanf("%i", &num1);

    resto = num1%2;
    
    if(resto == 1) {
        printf("O numero e impar");
    }
    if(resto == 0) {
        printf("O numero e par");
    }

    return 0;
}