#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int valor1;
    float valorfinal;

    printf("Digite o codigo do seu pedido: ");
    scanf("%i", &valor1);

    if (valor1 < 0){
        printf("Valor invalido");
        exit(0);
    }

    if (valor1 <= 50) {
        valorfinal = valor1 + (valor1*0.05);
    }
    if (valor1 > 50 && valor1 <= 100) {
        valorfinal = valor1 + (valor1*0.10);
    }
    if (valor1 > 100) {
        valorfinal = valor1 + (valor1*0.15);
    }
    


    if (valorfinal <= 80) {
        printf("Barato");
    }
    if (valorfinal > 80 && valorfinal <= 120) {
        printf("Normal");
    }
    if (valorfinal > 120 && valorfinal <= 200) {
        printf("Caro");
    }
    if (valorfinal > 200) {
        printf("Muito caro");
    }


  return 0;
}
