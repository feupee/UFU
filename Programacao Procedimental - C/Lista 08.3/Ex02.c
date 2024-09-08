#include <stdio.h>

/*Faça um programa que leia dois valores inteiros e chame uma função que
receba estes 2 valores de entrada e retorne o maior valor na primeira
variável e o menor valor na segunda variável. Escreva o conteúdo das 2
variáveis na tela.*/

void troca(int *int1, int *int2){
    int aux;

        aux = *int1;
        *int1 = *int2;
        *int2 = aux;

}

int main()
{
    int int1, int2;
    
    printf("Digite o valor 1: ");
    scanf("%d", &int1);
    printf("Digite o valor 2: ");
    scanf("%d", &int2);

    printf("\nValor 1: %d", int1);
    printf("\nValor 2: %d\n", int2);

    if(int2 > int1){
        troca(&int1, &int2);
    }

    printf("\nO maior valor eh: %d", int1);
    printf("\nO menor valor eh: %d\n", int2);

    return 0;
}
