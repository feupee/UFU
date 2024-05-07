#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int num1, resto1, resto2;

    printf("Digite um numero a ser verificado: ");
    scanf("%i", &num1);

    resto1 = num1%3;
    resto2 = num1%5;

    if(resto1 == resto2){
        printf("O numero e divisel pelos dois");
        exit(0);
    }

    if (resto1 == 0){
        printf("O numero eh divisel por 3");
    }

    if (resto2 == 0){
        printf("O numero eh divisel por 5");
    }

  return 0;
}
