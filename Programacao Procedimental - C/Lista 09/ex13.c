#include <stdio.h>
#include <stdlib.h>

/*.Escreva um programa que aloque dinamicamente uma matriz (de
inteiros) de dimensões definidas pelo usuário e a leia. Em seguida,
implemente uma função que receba um valor, retorne 1 caso o valor
esteja na matriz ou retorne 0 caso não esteja na matriz.*/

int searchValue(int x, int **matrix, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == x) return 1;
        }
    }
    return 0;
}

int main(){
    int m,n, x;
    int **a;

    printf("Insira as dimensoes da matriz Amxn: ");
    scanf("%d %d",&m,&n);

    if((a = (int **) malloc(m * sizeof(int *))) == NULL){
        printf("Error: sem memoria\n");
        exit(1);
    }

    for(int i = 0; i < m; i++){
        if((a[i] = (int *) malloc(n * sizeof(int))) == NULL){
            printf("Error: sem memoria\n");
            exit(1);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Insira A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Insira um valor para buscar na matriz: ");
    scanf("%d", &x);

    if(searchValue(x, a, m, n) == 1) printf("%d esta na matriz\n", x);
    else printf("%d nao esta na matriz\n", x);

    for(int i = 0; i < n; i++){
        free(a[i]);
    }
    free(a);
    a = NULL;
    return 0;
}