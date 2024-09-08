#include <stdio.h>

int main(){

    int soma = 0;
    int vetA[5];
    //questão A//
    vetA[0] = 1;
    vetA[1] = 0;
    vetA[2] = 5;
    vetA[3] = -2;
    vetA[4] = -5;
    vetA[5] = 7;
    //questão B//
    soma = vetA[0] + vetA[1] + vetA[5];

    printf("A soma das posicoes 0, 1 e 5 eh: %i", soma);
    printf("\n");

    //questão C//
    vetA[4] = 100;

    //questão D//
    int i;
    for(i = 0; i < 6; i++){
        printf("O valor de vetA[%i]: %i", i, vetA[i]);
        printf("\n");
    }

    return 0;
}



