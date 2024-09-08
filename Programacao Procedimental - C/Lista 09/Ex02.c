#include <stdio.h>
#include <stdlib.h>

//Faça um programa que leia do usuário o tamanho de um vetor a ser lido
//e faça a alocação dinâmica de memória. Em seguida, leia do usuário
//seus valores e imprima o vetor lido

int main(){

    int N, *array;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&N);

    array = (int *) malloc(N*sizeof(int));

    for(int i=0; i<N; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", (array + i));
    }
    for(int i = 0; i < N; i++){
        printf("Numero %d: %d\n", i+1, *(array + i));
    }

    free(array);

    return 0;
}