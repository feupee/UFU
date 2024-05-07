#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int valor1, num1, num2;

    printf("1 - Adicao ");
    printf("\n");
    printf("2 - Subtracao ");
    printf("\n");
    printf("3 - Multiplicacao ");
    printf("\n");
    printf("4 - Divisao ");
    printf("\n");
    printf("Digite um valor(1-4): ");
    scanf("%i", &valor1);

    if (valor1 < 1 || valor1 > 4){
        printf("Valor invalido");
        exit(0);
    }

    printf("Digite o primeiro numero: ");
    scanf("%i", &num1);

    printf("Digite o primeiro numero: ");
    scanf("%i", &num2);

    switch (valor1){
    case 1 :
    printf("Sua soma vai ser: %i", num1 + num2);
    break;

    case 2 :
    printf("Sua subtracao vai ser: %i", num1 - num2);
    break;

    case 3 :
    printf("Sua multiplicacao vai ser: %i", num1 * num2);
    break;

    case 4 :
    printf("Sua divisao vai ser: %i", num1 / num2);
    break;
    
    default:
        break;
    }

  return 0;
}
