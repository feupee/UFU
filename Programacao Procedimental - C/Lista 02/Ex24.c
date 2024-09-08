#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int valor1, valorD, valorfinal;

    printf("1 - MG ");
    printf("\n");
    printf("2 - SP ");
    printf("\n");
    printf("3 - RJ ");
    printf("\n");
    printf("4 - MS ");
    printf("\n");
    printf("Digite um valor(1-4) para envio: ");
    scanf("%i", &valor1);

    if (valor1 < 1 || valor1 > 4){
        printf("Valor invalido");
        exit(0);
    }

    printf("Digite o valor: ");
    scanf("%i", &valorD);

    switch (valor1){
    case 1 :
    valorfinal = (valorD + (valorD * 0.07));
    printf("O valor final para MG sera: %i", valorfinal);
    break;

    case 2 :
    valorfinal = (valorD + (valorD * 0.12));
    printf("O valor final para SP sera: %i", valorfinal);
    break;

    case 3 :
    valorfinal = (valorD + (valorD * 0.15));
    printf("O valor final para RJ sera: %i", valorfinal);
    break;

    case 4 :
    valorfinal = (valorD + (valorD * 0.08));
    printf("O valor final para MS sera: %i", valorfinal);
    break;

    default:
        break;
    }

  return 0;
}
