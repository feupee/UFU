#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que leia quatro números a, b, c e d, que serão as
dimensões de duas matrizes, e:
a) Crie e leia uma matriz, dadas as dimensões dela;
b) Crie e construa uma matriz que seja o produto de duas matrizes. Na
sua função main(), imprima as duas matrizes e o produto entre elas,
se existir.
*/

int main(){
    int a, b, c, d, soma, n;
    int **A, **B, **AB;

    printf("Insira as dimensoes da matriz de inteiros Aaxb: ");
    scanf("%d %d",&a, &b);
    printf("Insira as dimensoes da matriz de inteiros Bcxd: ");
    scanf("%d %d",&c, &d);

    if((A = (int **)malloc(a*sizeof(int*))) == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }for(int i = 0; i < a; i++){
        if((A[i] = (int *)malloc(b*sizeof(int))) == NULL){
            printf("Erro de alocacao de memoria\n");
            exit(1);
        }
    }

    if((B = (int **)malloc(c*sizeof(int*))) == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }for(int i = 0; i < c; i++){
        if((B[i] = (int *)malloc(d*sizeof(int))) == NULL){
            printf("Erro de alocacao de memoria\n");
            exit(1);
        }
    }

    //escaneando as matrizes
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            printf("Insira A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    for(int i = 0; i < c; i++){
        for(int j = 0; j < d; j++){
            printf("Insira B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    if(b == c){
        if((AB = (int **)malloc(a*sizeof(int*))) == NULL){
            printf("Erro de alocacao de memoria\n");
            exit(1);
        }for(int i = 0; i < a; i++){
            if((AB[i] = (int *)malloc(d*sizeof(int))) == NULL){
                printf("Erro de alocacao de memoria\n");
                exit(1);
            }
        }
        //realizando a multiplicacao de matrizes
        n = b;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < d; j++){
                soma = 0;
                for(int k = 0; k < n; k++){
                    soma += A[i][k] * B[k][j];
                }
                AB[i][j] = soma;
            }
        }
    }

    //printando as matrizes
    printf("\nMatriz A:\n\n");
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    system("pause");
    printf("\n\nMatriz B:\n\n");
    for(int i = 0; i < c; i++){
        for(int j = 0; j < d; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    system("pause");
    if(b == c){
        printf("\nMatriz AB:\n\n");
        for(int i = 0; i < a; i++){
            for(int j = 0; j < d; j++){
                printf("%d ", AB[i][j]);
            }
            printf("\n");
        }
    }else printf("Impossivel multiplicar as matrizes A e B\n");

    return 0;
}