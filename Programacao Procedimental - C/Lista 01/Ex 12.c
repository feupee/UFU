#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float M, Km;

    printf("Digite uma distancia em milhas: ");
    scanf("%f", &M);

    Km = 1.61*M;

    printf("O valor da transformacao eh:  %f", Km);

    return 0;

}