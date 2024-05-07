#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float num1;

    printf("Digite o numero: ");
    scanf("%f", &num1);
    
    if(num1 > 0) {
        sqrt(num1);
    }
    if(num1 < 0) {
        printf("O numero e invalido");
    }

    return 0;
}