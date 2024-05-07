#include <stdio.h>
#include <stdlib.h>

int main() { 

    int AnoA, AnoN, Idade;

    printf("Insira o ano que estamos: ");
    scanf("%i",&AnoA);
    printf("\n");

    printf("Insira sua idade: ");
    scanf("%i",&Idade);

    AnoN = AnoA - Idade;

    printf("\n");
    printf("O ano de nascimento eh: %i", AnoN);

}