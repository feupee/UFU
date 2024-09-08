#include <stdio.h>

/*Faça um programa que leia 2 valores inteiros e chame uma função que
receba estas 2 variáveis e troque o seu conteúdo, i.e., esta função é
chamada passando duas variáveis A e B, por exemplo, e após a execução da
função, A conterá o valor de B e B terá o valor de A. Imprima os valores
antes e depois da troca.*/

void trocar(int *int1, int *int2){
    int aux;
    
    aux = *int1;
    *int1 = *int2;
    *int2 = aux;

}

int main()
{
    int int1, int2;
    
    printf("Digite o valor 1: ");
    scanf("%d", &int1);
    printf("Digite o valor 2: ");
    scanf("%d", &int2);

    printf("\nValor 1: %d", int1);
    printf("\nValor 2: %d\n", int2);
    
    trocar(&int1, &int2);
    
    printf("\nValor 1 trocado: %d", int1);
    printf("\nValor 2 trocado: %d\n", int2);

    return 0;
}
