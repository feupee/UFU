#include <stdio.h>

/*Escreva um programa que receba um array de inteiros com 10 elementos
digitados pelo usuário e encontre o menor (min) e o maior (max) elemento
desse array. Utilize ponteiros tanto para acessar o array quanto para acessar
as variáveis min e max, ou seja, são necessários pelo menos 3 ponteiros.*/

int main(){

    int valores[10];
    int *ptr_valores = valores;
    int maior = 0, menor = 0;
    int *ptr_maior = &maior, *ptr_menor = &menor;

    for(int i = 0; i < 10; i++){
        printf("Digite o valor: ");
        scanf("%d", ptr_valores);
        if(i == 0){
            *ptr_maior = *ptr_valores;
            *ptr_menor = *ptr_valores;
        }
        if(*ptr_valores > maior){
            maior = *ptr_valores;
        }
        if(*ptr_valores < menor){
            menor = *ptr_valores;
        }
        ++ptr_valores;
    }

    printf("\nO maior valor eh: %d", *ptr_maior);
    printf("\nO menor valor eh: %d", *ptr_menor);

    return 0;
}

