#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Elabore um programa que dado um array e um valor do mesmo tipo do
array, preencha os elementos de array com esse valor. Não utilize índices
para percorrer o array, apenas aritmética de ponteiros.*/

void preencheVetor(char *array, char elemento, int tamanho) {
    int i = 0;
    
    while(i<tamanho) {
        *array = elemento;
        array++;
        i++;
    } 
}

void imprimeVetor(char *array, int tamanho) {
    int i;
    
    for (i=0; i<tamanho; i++) 
        printf("\n[%d]: %c", (i+1), *(array+i));
}

int main(){

    int tamanho;
    char elemento;
    int i;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);
    
    char array[tamanho];
    
    printf("Qual valor deseja preencher o array: ");
    scanf(" %c", &elemento);
    
    preencheVetor(array, elemento, tamanho);
    imprimeVetor(array, tamanho);
    
 
}