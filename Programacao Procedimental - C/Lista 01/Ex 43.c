#include <stdio.h>
#include <stdlib.h>

int main() {

    
    float Vl, V10, Sj3, D5v, D5p;

    printf("Digite o valor: ");
    scanf("%f", &Vl);

    V10 = Vl - (Vl*0.10);

    Sj3 = Vl / 3;

    D5v = V10 * 0.05;

    D5p = Vl * 0.05;

    printf("\n");
    printf("O valor a ser pago com 10 porcento de desconto:  R$%.2f", V10);

    printf("\n");
    printf("\n");
    printf("O valor de cada parcela em 3x sem juros eh:  R$%.2f", Sj3);

    printf("\n");
    printf("\n");
    printf("O valor da comissao do vendedor no caso da venda ser a vista eh:  R$%.2f", D5v);

    printf("\n");
    printf("\n");
    printf("O valor da comissao do vendedor no caso da venda ser parcelada eh:  R$%.2f", D5p);

    return(0);

}