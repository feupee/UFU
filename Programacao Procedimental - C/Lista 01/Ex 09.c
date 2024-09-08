#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Ke, Ce;

    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &Ce);

    Ke = Ce + 273.15;

    printf("O valor da transformacao eh:  %f", Ke);

    return 0;

}
