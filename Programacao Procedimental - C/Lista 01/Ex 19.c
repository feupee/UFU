#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float M3, Li;

    printf("Digite um valor em litros: ");
    scanf("%f", &Li);

    M3 = 1000/Li;

    printf("O valor da transformacao eh:  %f", M3);

    return 0;

}