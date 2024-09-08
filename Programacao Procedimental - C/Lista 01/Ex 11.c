#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Km, Ms;

    printf("Digite a velocidade em m/s: ");
    scanf("%f", &Ms);

    Km = Ms * 3.6;

    printf("O valor da transformacao eh:  %f", Km);

    return 0;

}
