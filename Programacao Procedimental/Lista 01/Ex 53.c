#include <stdio.h>
#include <stdlib.h>

int main() { 

    int l, c, Pmetro, Perimetro, Valor;

    printf("Digite a Largura: ");
    scanf("%i", &l);

    printf("Digite o Comprimento: ");
    scanf("%i", &c);

    printf("Digite o preco do metro: ");
    scanf("%i", &Pmetro);

    Perimetro = (l*2)+(c*2);
    Valor = Perimetro * Pmetro;

    printf("O valor a ser pago pelo servico eh: %i", Valor);
}