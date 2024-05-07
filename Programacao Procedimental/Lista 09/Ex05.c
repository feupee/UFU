#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que leia um número N e:
a) Crie dinamicamente e leia um vetor de inteiro de N posições;
b) Leia um número inteiro X e conte e mostre os múltiplos desse número
que existem no vetor.*/

int main(){

    int N, *vetor, X;

    printf("Digite um valor N: ");
    scanf("%d",&N);

    vetor = (int*)malloc(N*sizeof(int));

    for(int i = 0; i < N; i++){
        printf("Digite valor %d: ", i);
        scanf("%d", (vetor + i));
    }

    printf("Digite o valor X: ");
    scanf("%d",&X);
    
    for(int i = 0; i < N; i++){

    if (X % *(vetor+i) == 0)
        {
            printf("%d\n", *(vetor+i));
        }

    }

    free(vetor);
    return 0;
}