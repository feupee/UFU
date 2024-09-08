#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Faça um programa que pergunte ao usuário quantos valores ele deseja
armazenar em um vetor de double, depois use a função MALLOC para
reservar (alocar) o espaço de memória de acordo com o especificado
pelo usuário. Esse vetor deve ter um tamanho maior ou igual a 10
elementos. Use este vetor dinâmico como um vetor comum, atribuindo
aos 10 primeiros elementos do vetor valores aleatórios (usando a função
rand) entre 0 e 100. Exiba na tela os valores armazenados nos 10
primeiros elementos do vetor.*/

int main(){
    double *vetor;
    int i, n;

    do{
        printf("Insira o tamanho do vetor (>=10): ");
        scanf("%d", &n);
        if(n < 10) printf("Erro (vetor com menos de 10 posicoes)\n");
    }while(n < 10);
    

    vetor = (double *)malloc(n * sizeof(double));

    for(i = 0; i < 10; i++){
        vetor[i] = (rand() % 10000)/100.0;
    }

    for(i = 0; i < 10; i++){
        printf("Vetor[%d] = %.2lf\n", i, vetor[i]);
    }

    return 0;
}