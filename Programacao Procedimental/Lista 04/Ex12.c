#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int numinteiro, num, soma = 0;

    printf("Digite o valor: ");
    scanf("%i",&num);

    numinteiro = num;

    if (numinteiro != num){
        printf("O valor nao eh inteiro");
        exit(0);
    }

    void somadenumeros(int num, int soma);
    somadenumeros(num, soma);

    return 0;
}

void somadenumeros(int num, int soma){


    if(num <= 0 ){
        printf("Numero invalido");
        exit(0);
    }

    if(num > 0){
        while(num > 0){
            soma = soma+num%10;
            num = num/10;
        }

        printf("A soma dos algarismos eh: %i",soma);
    }
}

