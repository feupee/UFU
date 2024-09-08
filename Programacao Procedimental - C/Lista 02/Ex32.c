#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int valor1, quantidade;
    float valorfinal;

    printf("100 - Cachorro Quente ");
    printf("\n");
    printf("101 - Bauru Simples ");
    printf("\n");
    printf("102 - Bauru com Ovo ");
    printf("\n");
    printf("103 - Hamburguer ");
    printf("\n");
    printf("104 - Cheeseburguer  ");
    printf("\n");
    printf("105 - Suco  ");
    printf("\n");
    printf("106 - Refrigerante ");
    printf("\n");
    printf("Digite o codigo do seu pedido: ");
    scanf("%i", &valor1);

    if (valor1 < 100 || valor1 > 106){
        printf("Valor invalido");
        exit(0);
    }

    printf("Digite a quantidade: ");
    scanf("%i", &quantidade);

    switch (valor1){
    case 100 :
    valorfinal = quantidade * 1.20;
    printf("O valor do seu pedido sera: %.2f", valorfinal);
    break;

    case 101 :
    valorfinal = quantidade * 1.30;
    printf("O valor do seu pedido sera: %.2f", valorfinal);
    break;

    case 102 :
    valorfinal = quantidade * 1.50;
    printf("O valor do seu pedido sera: %.2f", valorfinal);
    break;

    case 103 :
    valorfinal = quantidade * 1.20;
    printf("O valor do seu pedido sera: %.2f", valorfinal);
    break;

    case 104 :
    valorfinal = quantidade * 1.70;
    printf("O valor do seu pedido sera: %.2f", valorfinal);
    break;

    case 105 :
    valorfinal = quantidade * 2.20;
    printf("O valor do seu pedido sera: %.2f", valorfinal);
    break;

    case 106 :
    valorfinal = quantidade * 1;
    printf("O valor do seu pedido sera: %.2f", valorfinal);
    break;
    
    default:
        break;
    }


  return 0;
}
