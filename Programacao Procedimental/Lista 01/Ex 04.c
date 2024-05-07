#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1;

    printf("Digite um numero real: ");
    scanf("%f", &num1);

    printf("\n");
    printf("Seu numero eh: %.2f", num1*num1);
    

  return 0;
}