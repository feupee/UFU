#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Gr, Ra, Pi;

    printf("Digite um angulo em graus: ");
    scanf("%f", &Gr);

    Pi = 3.141592;

    Ra = Gr*Pi/180;

    printf("O valor da transformacao eh:  %f", Ra);

    return 0;

}