#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int salario, emprestimo, condition;

    printf("Digite o salario do trabalhador: ");
    scanf("%i", &salario);

    printf("Digite o valor do emprestimo: ");
    scanf("%i", &emprestimo);

    condition = salario * 0.20;

    if (emprestimo > condition) {
        printf("Emprestimo nao concedido");
    }
    else {
        printf("Emprestimo concedido");
    }
    
    return 0;
}