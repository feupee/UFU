#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que leia primeiro os 6 números gerados pela
loteria e depois os 6 números do seu bilhete. O programa então compara
quantos números o jogador acertou. Em seguida, ele aloca espaço para
um vetor de tamanho igual a quantidade de números corretos e guarda
os números corretos nesse vetor. Finalmente, o programa exibe os
números sorteados e os seus números corretos.*/

int contaAcertos(int *sorteados, int *bilhete, int *vetAcertos);

int main(){
    int sorteados[6], bilhete[6], i, qtdAcertos = 0, *vetAcertos;
    vetAcertos = (int*)malloc(0*sizeof(int));
    
    for(i = 0; i < 6; i++){
        printf("Insira o %do nmro sorteado: ", i+1);
        scanf("%d", &sorteados[i]);
    }

    for(i = 0; i < 6; i++){
        printf("Insira o %do nmro do seu bilhete: ", i);
        scanf("%d", &bilhete[i]);
    }

    qtdAcertos = contaAcertos(sorteados, bilhete, vetAcertos);

    printf("%d valores acertados: ", qtdAcertos);
    for(i = 0; i < qtdAcertos; i++){
        printf("%d ", vetAcertos[i]);
    }
    if(qtdAcertos == 6) printf("\nVocê ganhou na loteria!");

    return 0;
}

int contaAcertos(int *sorteados, int *bilhete, int *vetAcertos){
    int qtd = 0, i, j;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            if(sorteados[i] == bilhete[j]){
                qtd++;
                sorteados[i] = -1;
                vetAcertos = realloc(vetAcertos, qtd*sizeof(int));
                vetAcertos[qtd-1] = bilhete[j];
            }
        }
    }
    return qtd;
}