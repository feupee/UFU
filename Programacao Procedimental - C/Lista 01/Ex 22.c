#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Ja, Me;

    printf("Digite um valor em Jardas: ");
    scanf("%f", &Ja);

    Me = 0.91*Ja;

    printf("O valor da transformacao eh:  %f", Me);

    return 0;

}