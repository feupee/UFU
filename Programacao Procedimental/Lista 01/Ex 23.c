#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Ja, Me;

    printf("Digite um valor em Metros: ");
    scanf("%f", &Me);

    Ja = 0.91/Me;

    printf("O valor da transformacao eh:  %f", Ja);

    return 0;

}