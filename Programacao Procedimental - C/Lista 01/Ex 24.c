#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float M2, Ac;

    printf("Digite um valor de área em metros quadrados: ");
    scanf("%f", &M2);

    Ac = M2*0.000247;

    printf("O valor da transformacao eh:  %f", Ac);

    return 0;

}