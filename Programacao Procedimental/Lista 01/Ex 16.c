#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Po, Cm;

    printf("Digite um valor em Polegadas: ");
    scanf("%f", &Po);

     Cm = Po*2.54;

    printf("O valor da transformacao eh:  %f", Cm);

    return 0;

}