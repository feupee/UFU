#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int Fa, Ce;

    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%i", &Fa);

    Ce = 5.0*(Fa- 32.0)/9.0;

    printf("O valor da transformacao eh:  %i", Ce);

    return 0;

}

