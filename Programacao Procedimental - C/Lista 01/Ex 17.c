#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Po, Cm;

    printf("Digite um valor em Centimetro: ");
    scanf("%f", &Cm);

     Po = Cm/2.54;

    printf("O valor da transformacao eh:  %f", Po);

    return 0;

}