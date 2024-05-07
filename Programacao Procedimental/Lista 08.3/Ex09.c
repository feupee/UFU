#include <stdio.h>

/*Escreva um programa que declare um array de inteiros e um ponteiro para
inteiros. Associe o ponteiro ao array. Agora, some mais um (+1) a cada
posição do array usando o ponteiro (use *).
*/

int main(){

    int array[5], *p = array, i;

    for(i = 0; i < 5; i++){
        printf("Digite valor %d: ", i);
        scanf("%d", &array[i]);
    }

    for(i = 0; i < 5; i++){
        printf("Vetor antigo: %d\n", array[i]);
    }

    for(i = 0; i < 5; i++){
        *(p + i) += 1;
    }

    printf("\n");

    for(i = 0; i < 5; i++){
        printf("Vetor novo: %d\n", array[i]);
    }

    return 0;
}