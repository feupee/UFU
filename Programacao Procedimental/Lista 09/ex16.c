#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que leia dois números N e M:
a) Crie e leia uma matriz N x M de inteiros;
b) Crie e construa uma matriz transposta M x N de inteiros;
c) Mostre as duas matrizes.*/

int main(){
   int m, n, valorTemp;
   int **mat, **matTransposta;

   printf("Insira as dimensoes MxN da matriz: ");
   scanf("%d %d",&m, &n);

    if((mat = (int **)malloc(m*sizeof(int *))) == NULL){
        printf("Error de alocacao de memoria\n");
        exit(1);
    }
    for(int i=0; i<m; i++){
        if((mat[i] = (int *)malloc(n*sizeof(int))) == NULL){
            printf("Error de alocacao de de memoria\n");
        }
    }

    if((matTransposta = (int **)malloc(n*sizeof(int *))) == NULL){
        printf("Error de alocacao de memoria\n");
        exit(1);
    }
    for(int i=0; i<n; i++){
        if((matTransposta[i] = (int *)malloc(m*sizeof(int))) == NULL){
            printf("Error de alocacao de de memoria\n");
        }
    }

    printf("Insira a matriz A%dx%d\n", m, n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("Insira A[%d][%d]: ", i, j);
            scanf("%d", &valorTemp);
            mat[i][j] = valorTemp;
            matTransposta[j][i] = valorTemp;
        }
    }

    printf("\nMatriz A%dx%d\n",m, n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz A'%dx%d\n",n, m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d " , matTransposta[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++){
        free(mat[i]);
    }
    free(mat);
    mat = NULL;

    for(int i = 0; i < m; i++){
        free(matTransposta[i]);
    }
    free(matTransposta);
    matTransposta = NULL;
    
    return 0;
}