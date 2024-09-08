#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float altura, Pmasculino, Pfeminino, conversao;
    char sexo;

    printf("Digite o sexo (M ou F): ");
    scanf("%c", &sexo);

    printf("Digite a altura em cm: ");
    scanf("%f", &altura);

    conversao = altura / 100;
    
    Pmasculino = (72.7 * conversao) - 58;
    Pfeminino = (62.1 * conversao) - 44,7;

    if (sexo == 77) {
        printf("Masculino");
        printf("\n");
        printf("O peso ideal eh: %.2fKG", Pmasculino);
    }
    if (sexo == 70) {
        printf("Feminino:");
         printf("\n");
        printf("O peso ideal eh: %.2fKG", Pfeminino);
    }
    else {
        exit(0);
    }

    return 0;
}