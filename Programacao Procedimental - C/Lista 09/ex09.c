#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que leia uma quantidade qualquer de números
armazenando-os na memória e pare a leitura quando o usuário entrar
um número negativo. Em seguida, imprima o vetor lido. Use a função
REALLOC*/

int main(){
    int *vetor = malloc(0 * sizeof(int)), i = 0, n, j;

    do{
        scanf("%d", &n);
        if(n >= 0){
            vetor = realloc(vetor, (i + 1) * sizeof(int));
            vetor[i] = n;
            i++;
        }
    }while(n >= 0);

    for(j = 0; j < i; j++){
        printf("Vetor[%d] = %d\n", j, vetor[j]);
    }

    return 0;
}