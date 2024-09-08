#include <stdio.h>
#include <stdlib.h>

/*Escreva uma função que retorna o maior valor de um array de tamanho N.
Escreva um programa que leia N valores inteiros, imprima o array com ‘k’
elementos por linha, e o maior elemento. O valor de ‘k’ também deve ser
fornecido pelo usuário.*/

int main(){

    int N, i, k, count = 0;

    printf("Digite o valor do vetor: ");
    scanf("%d",&N);

    int *vetor = (int*)malloc(N*sizeof(int));

    printf("Digite a quantidade de elementos por linha: ");
    scanf("%d",&k);

    for(i = 0; i < N; i++){
        printf("Digite valor %d: ", i);
        scanf("%d", (vetor + i));
    }

    for(i = 0; i < N; i++){
        printf("%d ", *(vetor + i));
        count++;

        if(count == k){
            count = 0;
            printf("\n");
        }
        
    }
    
    return 0;
}