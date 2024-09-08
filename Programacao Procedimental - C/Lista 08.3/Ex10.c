#include <stdio.h>
#include <stdlib.h>

/*Crie uma função para somar dois arrays. Esta função deve receber dois
arrays e retornar a soma em um terceiro array. Caso o tamanho do primeiro
e segundo array seja diferente então a função retornará ZERO (0). Caso a
função seja concluída com sucesso a mesma deve retornar o valor UM (1).
Utilize aritmética de ponteiros para manipulação do array.*/

int somar(int *array1, int *array2, int *array3, int M, int N){
    
    if(M != N){
        printf("Valor de N e != de M");
        return 0;
    }else{
    int i;
    for(i = 0; i < N; i++){
        printf("Vet 1 valor %d: ", i);
        scanf("%d", &array1[i]);
    }
    for(i = 0; i < N; i++){
        printf("Vet 2 valor %d: ", i);
        scanf("%d", &array2[i]);
    }
    for(i = 0; i < N; i++){
        *(array3 + i) = *(array1 + i) + *(array2 + i);
    }

    printf("\n");

    for(int i = 0; i < N; i++){
        printf("Valor %d somado: %d\n", i, *(array3 + i));
    }

    return 1;
    }
}

int main(){

    int N, M;

    printf("Digite o valor de N: ");
    scanf("%d",&N);

    printf("Digite o valor de M: ");
    scanf("%d",&M);

    int *array1 = (int *)malloc(N * sizeof(int));
    int *array2 = (int *)malloc(M * sizeof(int));
    int *array3 = (int *)malloc(N * sizeof(int));
    
    somar(array1, array2, array3, M, N);

    return 0;
}