#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float M2, He;

    printf("Digite um valor em metros quadrados: ");
    scanf("%f", &M2);

    He = M2*0.0001;

    printf("O valor da transformacao eh:  %f", He);

    return 0;

}