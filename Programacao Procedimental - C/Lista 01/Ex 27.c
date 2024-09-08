#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float M2, He;

    printf("Digite um valor em hectares: ");
    scanf("%f", &He);

    M2 = He*10000;

    printf("O valor da transformacao eh:  %f", M2);

    return 0;

}