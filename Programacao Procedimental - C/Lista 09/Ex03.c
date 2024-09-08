#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que leia do usuário o tamanho de um vetor a ser lido
e faça a alocação dinâmica de memória. Em seguida, leia do usuário
seus valores e mostre quantos dos números são pares e quantos são
ímpares.*/

int main(){

    int N, *array, countimpar = 0, countpar = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&N);

    array = (int *) malloc(N*sizeof(int));

    for(int i=0; i<N; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", (array + i));
        if(*(array + i) % 2 == 0 && *(array + i) != 0){
            countpar++;
        }else if(*(array + i) % 2 != 0 && *(array + i) != 0){
            countimpar++;
        }
    }

    printf("\nNumeros pares: %d\n", countpar);
    printf("Numeros impares: %d\n", countimpar);

    free(array);

    return 0;
}