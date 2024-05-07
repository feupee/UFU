#include <stdio.h>

/*Escreva uma função que aceita como parâmetro um array de inteiros com N
valores, e determina o maior elemento do array e o número de vezes que
este elemento ocorreu no array. Por exemplo, para um array com os
seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a função deve retorna para
o programa que a chamou o valor 15 e o número 3 (indicando que o número
15 ocorreu 3 vezes). A função deve ser do tipo void.*/

void verificador(int *array, int maior, int cont){
    int i;

    for(i = 0; i < 5; i++){
        printf("Digite o valor %i: ", i);
        scanf("%d", &array[i]);
    }

    maior = array[0];

    for(i = 1; i < 5; i++){
        if(array[i] > maior){
            maior = array[i];
            cont = 0;
        }
        if(array[i] == maior){
            cont++;
        }
    }

    printf("O maior valor eh: %d", maior);
    printf("\nQuantas vezes ele aparece: %d", cont);
}

int main(){

    int cont = 0, maior = 0;

    int array[5];

    verificador(array, maior, cont);

    return 0;
}