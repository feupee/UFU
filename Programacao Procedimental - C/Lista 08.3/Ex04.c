#include <stdio.h>

/*Faça um programa que leia três valores inteiros e chame uma função que
receba estes 3 valores de entrada e retorne eles ordenados, ou seja, o
menor valor na primeira variável, o segundo menor valor na variável do
meio, e o maior valor na última variável. A função deve retornar o valor 1 se
os três valores forem iguais e 0 se existirem valores diferentes. Exibir os
valores ordenados na tela.*/

int ordem(int *A, int *B, int *C){
    int aux;

    if(*A == *B && *B == *C){
        return 1;
    }
    if(*A > *C && *C > *B){
        aux = *B;
        *B = *C;
        *C = aux;
    }
    if(*B > *A && *A > *C){
        aux = *A;
        *A = *B;
        *B = aux;
    }
    if(*B > *C && *C > *A){
        aux = *A;
        *A = *B;
        *B = *C;
        *C = aux;
    }
    if(*C > *A && *A > *B){
        aux = *A;
        *A = *C;
        *C = *B;
        *B = aux;
        
    }
    if(*C > *B && *B > *A){
        aux = *A;
        *A = *C;
        *C = aux;
    }
    
    return 0;
}

int main()
{
    int A, B, C;
    
    printf("Digite o valor A: ");
    scanf("%d", &A);
    printf("Digite o valor B: ");
    scanf("%d", &B);
    printf("Digite o valor C: ");
    scanf("%d", &C);

    printf("\nValor 1: %d", A);
    printf("\nValor 2: %d", B);
    printf("\nValor 3: %d\n", C);

    ordem(&A, &B, &C);

    printf("\nValor de A: %d\nValor de B: %d\nValor de C: %d\n", C,B,A);

    return 0;
}
