#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Km, Ms;

    printf("Digite a velocidade em Km/h: ");
    scanf("%f", &Km);

    Ms = Km/3.6;

    printf("O valor da transformacao eh:  %f", Ms);

    return 0;

}
