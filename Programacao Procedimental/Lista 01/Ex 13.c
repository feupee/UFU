#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float M, Km;

    printf("Digite uma distancia em quilometros: ");
    scanf("%f", &Km);

    M = 1.61/Km;

    printf("O valor da transformacao eh:  %f", M);

    return 0;

}