#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float num1, num2, num3;

    printf("Digite Num1: ");
    scanf("%f", &num1);
    printf("Digite Num2: ");
    scanf("%f", &num2);
    printf("Digite Num3: ");
    scanf("%f", &num3);

    printf("O valor da transformacao eh:  %f", (num1*num1)+(num2*num2)+(num3*num3));

    return 0;

}