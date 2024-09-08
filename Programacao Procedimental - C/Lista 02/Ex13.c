#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int nota1, nota2, nota3, notafinal;

    printf("Escreva a nota da prova 1: ");
    scanf("%i", &nota1);

    printf("Escreva a nota da prova 2: ");
    scanf("%i", &nota2);

    printf("Escreva a nota da prova 3: ");
    scanf("%i", &nota3);

    notafinal = ((nota1 * 1) + (nota2 * 1) + (nota3 * 2))/4;

    printf("\n");

    if (notafinal >= 60 ) {
        printf("Parabens, voce passou!");
    }

    else {
        printf("Voce nao passou!");
    }

    return 0;
}