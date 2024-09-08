#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int idade, tempo;

    printf("Digite a idade do trabalhador: ");
    scanf("%i", &idade);

    printf("Digite o tempo de trabalho do trabalhador em anos: ");
    scanf("%i", &tempo);

    if (idade >= 65 || tempo >= 30 || idade >= 60 && tempo >= 25){
        printf("Voce esta em condicoes de aposentar");
    }
    else 
        printf("falha nos requisitos");

  return 0;
}
