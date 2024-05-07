#include <stdio.h>
#include <stdlib.h>

int main() {

    
    int Ht, Nh, Final, soma;

    printf("Digite o valor da hora de trabalho: ");
    scanf("%d", &Ht);

    printf("Digite o valor de horas trabalhadas no mes: ");
    scanf("%d", &Nh);

    soma = Ht * Nh;
    Final = soma + (soma*0.10);

    printf("\n");
    printf("O valor a ser pago com os descontos eh:  %d", Final);

    return(0);

}