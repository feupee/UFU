#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num1, num2;

    printf("Digite o primeiro numero: ");
    scanf("%i", &num1);

    printf("Digite o segundo numero: ");
    scanf("%i", &num2);

    if(num1 > num2) {
        printf("O maior numero eh: %i\n", num1);
    }
    if(num1 < num2) {
        printf("O maior numero eh: %i\n", num2);
    }
    if(num1 == num2) {
        printf("Numeros iguais");
    }


    return 0;
}