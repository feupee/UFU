#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Gr, Ra, Pi;

    printf("Digite um angulo em radianos: ");
    scanf("%f", &Ra);

    Pi = 3.141592;

    Gr = Ra*180/Pi;

    printf("O valor da transformacao eh:  %f", Gr);

    return 0;

}