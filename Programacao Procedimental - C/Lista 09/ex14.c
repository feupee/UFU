#include <stdio.h>
#include <stdlib.h>

/*Construa um programa que leia o número de linhas e de colunas de uma
matriz de números reais, aloque espaço dinamicamente para esta e a
inicialize com valores fornecidos pelo usuário. Ao final, o programa
deverá retornar a matriz na saída padrão com layout apropriado.*/

int contaDigitos(int valor){
    int digitos = 0;
    do{
        digitos++;
        valor = valor / 10;
    }while (valor != 0);
    return digitos;
}

int main(){
    int m,n, maiorValor, qtdAlgarismos = 0;
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
            if(i == j && i == 0) maiorValor = a[i][j];
            else if(a[i][j] > maiorValor) maiorValor = a[i][j];
        }
    }

    qtdAlgarismos = contaDigitos(maiorValor);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int z = 0; z < (qtdAlgarismos - contaDigitos(a[i][j])); z++){
                printf("0");
            }
            printf("%d ", a[i][j]); 
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++){
        free(a[i]);
    }
    free(a);
    a = NULL;
    return 0;
}