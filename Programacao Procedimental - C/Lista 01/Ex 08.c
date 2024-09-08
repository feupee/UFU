#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Ke, Ce;

    printf("Digite a temperatura em Kelvin: ");
    scanf("%f", &Ke);

    Ce = Ke-273.15;

    printf("O valor da transformacao eh:  %f", Ce);

    return 0;

}

