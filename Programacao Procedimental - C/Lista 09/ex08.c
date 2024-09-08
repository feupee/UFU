#include <stdio.h>
#include <stdlib.h>

/*Faça um programa para armazenar em memória um vetor de dados
contendo 1500 valores do tipo int, usando a função de alocação
dinâmica de memória CALLOC:
a) Faça um loop e verifique se o vetor contém realmente os 1500
valores inicializados com zero (conte os 1500 zeros do vetor);
b) Atribua para cada elemento do vetor o valor do seu índice junto a
este vetor;
c) Exibir na tela os 10 primeiros e os 10 últimos elementos do vetor*/

int main(){
    int *vetor = calloc(1500, sizeof(int)), i;
    for(i=0; i<1500; i++){
        if(vetor[i] != 0) exit(1);
        else{
            vetor[i] = i;
        }
    }
    
    for(i=0; i<10; i++){
        printf("vetor[%d] = %d\n",i, vetor[i]);
    }
    for(i=1500-10; i<1500; i++){
        printf("vetor[%d] = %d\n",i, vetor[i]);
    }

    return 0;
}