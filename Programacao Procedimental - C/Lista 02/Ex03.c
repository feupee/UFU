#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float num1;

    printf("Digite um numero real: ");
    scanf("%f", &num1);
    
    if(num1 > 0) {
        printf("A raiz quadrada do numero eh: %.2f\n", sqrt(num1));
    }
    else {
        printf("O quadrado do numero eh: %.2f\n", num1*num1);
    }

    return 0;
}