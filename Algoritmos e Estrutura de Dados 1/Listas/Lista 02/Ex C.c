#include <stdio.h>
#include <stdlib.h>

int main(){

    int **matriz1, **matriz2, **matriz_soma, i, j;

    //alocando matrizes
    matriz1 = (int **) malloc(3*sizeof(int *));
    matriz2 = (int **) malloc(3*sizeof(int *));
    matriz_soma = (int **) malloc(3*sizeof(int *));

    for(i = 0; i < 3; i++){
        matriz1[i] = (int *)malloc(3 * sizeof(int));
        matriz2[i] = (int *)malloc(3 * sizeof(int));
        matriz_soma[i] = (int *) malloc(3 * sizeof(int));
    }
    //recebeno valores para matrizes
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Mat 1 - Digite o valor [%d][%d]: ", i,j);
            scanf("%d", &matriz1[i][j]);
        }
    }
    printf("\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Mat 2 - Digite o valor [%d][%d]: ", i,j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            matriz_soma[i][j] = matriz2[i][j] + matriz1[i][j];
        }
    }
    printf("\n");
    //imprimindo matrizes
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Mat1 - O valor de [%d][%d] eh: %d\n", i, j, matriz1[i][j]);
        }
    }
    printf("\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Mat2 - O valor de [%d][%d] eh: %d\n", i, j, matriz2[i][j]);
        }
    }
    printf("\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Mat3 - O valor de [%d][%d] eh: %d\n", i, j, matriz_soma[i][j]);
        }
    }
    //liberando matrizes
    for(i = 0 ; i < 3; i++){
        free(matriz1[i]);
        free(matriz2[i]);
        free(matriz_soma[i]);
    }

    free(matriz1);
    free(matriz2);
    free(matriz_soma);

    return 0;
}