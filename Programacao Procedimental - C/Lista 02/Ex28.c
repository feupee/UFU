#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int valor1;
    float geometrica, harmonica, ponderada, aritmetica, num1, num2, num3;

    printf("1 - Geometrica");
    printf("\n");
    printf("2 - Ponderada");
    printf("\n");
    printf("3 - Harmonica");
    printf("\n");
    printf("4 - Aritmetica");
    printf("\n");
    printf("Digite um valor(1-4): ");
    scanf("%i", &valor1);
    
    if (valor1 < 1 || valor1 > 4){
        printf("Valor invalido");
        exit(0);
    }

    printf("\n");
    printf("\n");

    printf("Digite o numero 1: ");
    scanf("%f", &num1);
    printf("Digite o numero 2: ");
    scanf("%f", &num2);
    printf("Digite o numero 3: ");
    scanf("%f", &num3);

    switch(valor1){
        case 1 :
        geometrica = pow(num1*num2*num3,1.0/3.0);
        printf("A media geometrica sera: %.2f", geometrica);
        break;
        case 2 :
        ponderada = ((1*num1)+(2*num2)+(3*num3))/6;
        printf("A media ponderada sera: %.2f", ponderada);
        break;
        case 3 :
        harmonica = 3/((1/num1)+(1/num2)+(1/num3));
        printf("A media harmonica sera: %.2f", harmonica);
        break;
        case 4 :
        aritmetica = (num1 + num2 + num3)/3;
        printf("A media aritmetica sera: %.2f", aritmetica);
        break;
    }

    

  return 0;
}
