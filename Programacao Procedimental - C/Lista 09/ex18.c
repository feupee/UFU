#include <stdio.h>
#include <stdlib.h>

/*.Escreva um programa para fazer a alocação dinâmica dos blocos de
dados conforme solicitado abaixo:
a) Vetor de 1024 Bytes (1 Kbyte);
b) Matriz de inteiros de dimensão 10 × 10;
c) Vetor para armazenar 50 registros contendo: nome do produto (30
caracteres), código do produto (inteiro) e preço em reais;
d) Texto de até 100 linhas com até 80 caracteres em cada linha*/

typedef struct registros{
    char nome[30];
    int cod;
    float preco;
}registros;

int main(){
    void *vetor1024;
    int **matriz10x10;
    registros *registro;
    char **texto;

    //alocacao vetor 1Kb
    if((vetor1024 = calloc(1024, 1)) == NULL){
        printf("Erro na alocacao do vetor de 1Kb\n");
        exit(1);
    }

    //alocacao matriz10x10
    if((matriz10x10 = (int**)calloc(10, sizeof(int*))) == NULL){
        printf("Erro na alocacao da matriz 10x10\n");
        exit(1);
    }
    for(int i = 0; i < 10; i++){
        if((matriz10x10[i] = (int*)calloc(10, sizeof(int))) == NULL){
            printf("Erro na alocacao da matriz 10x10\n");
            exit(1);
        }
    }

    //alocacao registros
    if((registro = calloc(50, sizeof(registros))) == NULL){
        printf("Erro na alocacao dos registros\n");
        exit(1);
    }

    //alocacao texto
    if((texto = (char**)calloc(100, sizeof(char*))) == NULL){
        printf("Erro na alocacao do texto\n");
        exit(1);
    }
    for(int i = 0; i < 100; i++){
        if((texto[i] = (char*)calloc(80, sizeof(char))) == NULL){
            printf("Erro na alocacao do texto\n");
            exit(1);
        }
    }
    
    printf("Alocacoes bem sucedidas\n");
    return 0;
}