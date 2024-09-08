#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int nota1, nota2, nota3, notafinal;

    printf("Escreva a nota 1(0-10): ");
    scanf("%i", &nota1);

    printf("Escreva a nota 2(0-10): ");
    scanf("%i", &nota2);

    printf("Escreva a nota 3(0-10): ");
    scanf("%i", &nota3);

    if (nota1 < 0 || nota2 < 0 || nota3 < 0 || nota1 > 10 || nota2 > 10 || nota3 > 10) {

    }

    notafinal = ((nota1 * 2) + (nota2 * 3) + (nota3 * 5))/10;

    if (notafinal >= 0 && notafinal <= 2.9) {
        printf("Voce esta reprovado");
        printf("\n");
        printf("Sua media eh: %i", notafinal);
    }

    if (notafinal >= 3 && notafinal <= 4.9) {
        printf("Voce esta de recuperacao");
        printf("\n");
        printf("Sua media eh: %i", notafinal);
    }

    if (notafinal > 5  && notafinal < 10) {
        printf("Voce passsou!");
        printf("\n");
        printf("Sua media eh: %i", notafinal);
    }

    return 0;
}