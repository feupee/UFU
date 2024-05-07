#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float n1, n2, n3, n4;

    printf("Digite Num1: ");
    scanf("%f", &n1);
    printf("Digite Num2: ");
    scanf("%f", &n2);
    printf("Digite Num3: ");
    scanf("%f", &n3);
    printf("Digite Num4: ");
    scanf("%f", &n4);

    printf("O valor da transformacao eh:  %f", (n1+n2+n3+n4)/4);

    return 0;

}