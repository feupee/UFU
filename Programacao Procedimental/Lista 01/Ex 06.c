#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int Ce, Fa;

    printf("Digite a temperatura em Celsius: ");
    scanf("%i", &Ce);

    Fa = (Ce * 9/5) + 32;

    printf("O valor da transformacao eh:  %i", Fa);

    return 0;

}

