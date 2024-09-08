#include <stdio.h>
#include <string.h>

int main(){

    float mercadoria_valor, avista, desconto;
    char mercadoria_nome[20];

    printf("Digite o nome da mercadoria: ");
    fgets(mercadoria_nome, 20, stdin);

    printf("Digite o valor da mercadoria em reais: ");
    scanf("%f", &mercadoria_valor);

    avista = mercadoria_valor - (mercadoria_valor*0.1);
    desconto = mercadoria_valor*0.1;

    printf("O nome da mercadoria eh: %s\n", mercadoria_nome);
    printf("O valor total(sem descontos): %.2fR$\n", mercadoria_valor);
    printf("O valor do desconto eh: %.2fR$\n", desconto);
    printf("O valor a ser pago a vista eh: %.2fR$\n", avista);

    return 0;
}