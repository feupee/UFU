#include <stdio.h>

//Exercicio D

int calcularQuocienteResto(int a, int b, int *quociente, int *resto) {
    if (b == 0) {
        return -1;  // Não é possível realizar as operações
    } else {
        *quociente = a / b;
        *resto = a % b;
        return 0;  // Operações realizadas com sucesso
    }
}

int main() {
    int a, b, quociente, resto;

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    int resultado = calcularQuocienteResto(a, b, &quociente, &resto);

    if (resultado == -1) {
        printf("Não é possível realizar a operação de divisão por zero.\n");
    } else {
        printf("Quociente: %d\n", quociente);
        printf("Resto: %d\n", resto);
    }

    return 0;
}