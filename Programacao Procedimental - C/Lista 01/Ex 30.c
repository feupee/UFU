#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Re, dollar;

    printf("Digite a cotacao do dollar: ");
    scanf("%f", &dollar);

    printf("Digite um valor em real: ");
    scanf("%f", &Re);
    
    printf("O valor da transformacao eh:  %.2f", (Re*dollar));

    return 0;

}