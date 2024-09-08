#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ano,anoatual, idade;

    printf("Digite o ano de nascimento: ");
    scanf("%d", &ano);
    printf("Digite o ano atual: ");
    scanf("%d", &anoatual);
    idade = anoatual - ano;

    printf("A pessoa tem %d anos\n", idade);
    printf("Em 2030 a pessoa tera %d anos", (2030 - ano));

    return 0;

}