#include <stdio.h>
#include <stdlib.h>

//Crie um programa que:
//a) Aloque dinamicamente um array de 5 números inteiros;
//b) Peça para o usuário digitar os 5 números no espaço alocado;
//c) Mostre na tela os 5 números;
//d) Libere a memória alocada.

int main(){

    //a)

    int *array, N = 5;

    array = (int *) malloc(N*sizeof(int));

    //b)

    for(int i = 0; i < 5; i++){
        printf("Digite numero %d: ", i+1);
        scanf("%d", (array + i));
    }

    //c)

    for(int i = 0; i < 5; i++){
        printf("Numero %d: %d\n", i+1, *(array + i));
    }

    //d)

    free(array);

    return 0;
}