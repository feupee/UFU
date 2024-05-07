#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int valor1, num1, num2;

    printf("1 - Soma de 2 numeros ");
    printf("\n");
    printf("2 - Diferenca de 2 numeros (maior pelo menor) ");
    printf("\n");
    printf("3 - Produto de 2 numeros ");
    printf("\n");
    printf("4 - Divisao de 2 numeros, o primeiro numerador e o seguinte denominador (denominador nao pode ser 0) ");
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
    if(num1 > num2){
    printf("Sua subtracao vai ser: %i", num1 - num2);
    break;
    }
    if(num2 > num1){
    printf("Sua subtracao vai ser: %i", num2 - num1);
    break;
    }

    case 3 :
    printf("Sua multiplicacao vai ser: %i", num1 * num2);
    break;

    case 4 :
    if(num2 == 0){
         printf("ERRO");
         exit(0);
         }
         else
            printf("Sua divisao vai ser: %i", num1 / num2);
    break;

    default:
        break;
    }

  return 0;
}
