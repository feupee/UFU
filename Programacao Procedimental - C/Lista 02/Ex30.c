#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int num1, num2, num3;

    printf("Digite o valor de numero 1: ");
    scanf("%i", &num1);
    printf("Digite o valor de numero 2: ");
    scanf("%i", &num2);
    printf("Digite o valor de numero 3: ");
    scanf("%i", &num3);

    if (num1 > num2 && num2 > num3){
        printf("A ordem crescente sera: %i %i %i", num3, num2, num1);
    }
    if (num1 > num3 && num3 > num2){
        printf("A ordem crescente sera: %i %i %i", num2, num3, num1);
    }
    if (num2 > num1 && num1 > num3){
        printf("A ordem crescente sera: %i %i %i", num3, num1, num2);
    }
    if (num2 > num3 && num3 > num1){
        printf("A ordem crescente sera: %i %i %i", num1, num3, num2);
    }
    if (num3 > num1 && num1 > num2){
        printf("A ordem crescente sera: %i %i %i", num2, num1, num3);
    }
    if (num3 > num2 && num2 > num1){
        printf("A ordem crescente sera: %i %i %i", num1, num2, num3);
    }


  return 0;
}
