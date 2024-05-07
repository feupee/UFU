#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int num1, soma = 0;

    printf("Escreva um numero maior que zero: ");
    scanf("%i", &num1);

    if(num1 <= 0 ){
        printf("Numero invalido");
        exit(0);
    }

    if(num1 > 0){
        while(num1 > 0){
            soma = soma+num1%10;
            num1 = num1/10;
        }

        printf("A soma dos algarismos eh: %i",soma);
    }
    return 0;
}