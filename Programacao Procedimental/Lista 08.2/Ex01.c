#include <stdio.h>

/*Crie um programa que contenha um array de float contendo 10 elementos.
Utilizando aritmética de ponteiro, imprima o endereço de cada posição
desse array*/

int main()
{
    float imprimir[10];
    float *p = &imprimir[0];
    int i;
    
    for(i = 0; i < 10; i++){
        printf("Endereco: %p", p+i);
        printf("\n");
    } 

    return 0;
}