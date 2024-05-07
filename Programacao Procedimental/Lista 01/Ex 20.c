#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Kg, Lb;

    printf("Digite um valor em quilogramas: ");
    scanf("%f", &Kg);

    Lb = Kg/0.45;

    printf("O valor da transformacao eh:  %f", Lb);

    return 0;

}