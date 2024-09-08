#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float M3, Li;

    printf("Digite um valor em metro cubico: ");
    scanf("%f", &M3);

    Li = 1000*M3;

    printf("O valor da transformacao eh:  %f", Li);

    return 0;

}