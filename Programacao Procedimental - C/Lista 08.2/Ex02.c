#include <stdio.h>

/*Crie um programa que contenha uma matriz de float contendo 3 linhas e 3
colunas. Utilizando aritmética de ponteiro, imprima o endereço de cada
posição dessa matriz.*/

int main()
{
    float matriz[3][3];
    float *p = &matriz[0][0];
    int i, j;
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
        printf("Endereco[%d][%d]: %p", i, j, &matriz[i][j]);
        printf("\n");
        }
        
    } 

    return 0;
}