#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que leia números do teclado e os armazene em um
vetor alocado dinamicamente. O usuário irá digitar uma sequência de
números, sem limite de quantidade. Os números serão digitados um a
um e, sendo que caso ele deseje encerrar a entrada de dados, ele irá
digitar o número ZERO. Os dados devem ser armazenados na memória
deste modo:
a) Inicie com um vetor de tamanho 10 alocado dinamicamente;
b) Após, caso o vetor alocado esteja cheio, aloque um novo vetor do
tamanho do vetor anterior adicionado espaço para mais 10 valores
(tamanho N+10, onde N inicia com 10);
c) Copie os valores já digitados da área inicial para esta área maior e
libere a memória da área inicial;
d) Repita este procedimento de expandir dinamicamente com mais 10
valores o vetor alocado cada vez que o mesmo estiver cheio. Assim o
vetor irá ser “expandido” de 10 em 10 valores.
Ao final, exiba o vetor lido. Não use a função REALLOC.*/

int main(){
    int valor, *vetor = (int*)malloc(10 * sizeof(int)), *vetorAux, count10 = 0, totalEntradas = 0;

    do{
        printf("Insira a entrada %d: ", totalEntradas + 1);
        scanf("%d",&valor);
        vetor[totalEntradas] = valor;
        totalEntradas++;
        if(totalEntradas%10 == 0){
            count10++;

            if((vetorAux = (int*)malloc(totalEntradas * sizeof(int))) == NULL){
                printf("Erro de alocacao de memoria");
                exit(1);
            }
            for(int i = 0; i < totalEntradas; i++){
                vetorAux[i] = vetor[i];
            }
            free(vetor);

            if((vetor = (int*)malloc((totalEntradas+10) * sizeof(int))) == NULL){
                printf("Erro de alocacao de memoria");
                exit(1);
            }
            for(int i = 0; i < 10*count10; i++){
                vetor[i] = vetorAux[i];
            }
            free(vetorAux);
        }
        if(valor==0) break;

    }while(valor!=0);

    for(int i = 0; i < totalEntradas-1; i++){
        printf("%d ", vetor[i]);
    }
    free(vetor);
    return 0;
}