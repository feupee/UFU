#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float M2, Ac;

    printf("Digite um valor em acres: ");
    scanf("%f", &Ac);

    M2 = Ac/4048.58;

    printf("O valor da transformacao eh:  %f", M2);

    return 0;

}