#include <stdio.h>

int main() {
    int ano, ano_atual;
    float salario = 2000, aumento;

    printf("Digite o ano atual: ");
    scanf("%d", &ano_atual);

    aumento = (salario * 0.015);
    salario = salario + aumento;

    for(ano = 1996; ano < ano_atual; ano++){
        aumento = 2*aumento;
        salario = salario + aumento;
    }

    printf("Salario atual: R$%.2f\n", salario);

}