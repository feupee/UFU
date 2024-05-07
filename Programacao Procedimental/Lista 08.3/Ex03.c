#include <stdio.h>

/*Crie um programa que contenha uma função que permita passar por
parâmetro dois números inteiros A e B. A função deverá calcular a soma
entre estes dois números e armazenar o resultado na variável A. Esta função
não deverá possuir retorno, mas deverá modificar o valor do primeiro
parâmetro. Imprima os valores de A e B na função principal.
*/

void soma(int *A, int *B){
    *A = *A + *B;
}

int main()
{
    int A, B;
    
    printf("Digite o valor A: ");
    scanf("%d", &A);
    printf("Digite o valor B: ");
    scanf("%d", &B);

    printf("\nValor 1: %d", A);
    printf("\nValor 2: %d\n", B);

    soma(&A, &B);

    printf("\nValor de A: %d", A);
    printf("\nValor de B: %d\n", B);

    return 0;
}
