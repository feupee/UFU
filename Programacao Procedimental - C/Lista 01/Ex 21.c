#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float Kg, Lb;

    printf("Digite um valor em Libras: ");
    scanf("%f", &Lb);

    Kg = Lb*0.45;

    printf("O valor da transformacao eh:  %f", Kg);

    return 0;

}