#include <stdio.h>
#include <math.h>

//Exercicio E

void calculaHexagono(float l, float *area, float *perimetro) {
    *area = (3 * sqrt(3) * l * l) / 2; // Fórmula da área do hexágono regular
    *perimetro = 6 * l; // Fórmula do perímetro do hexágono regular
}

int main() {
    float lado, area, perimetro;

    printf("Digite o valor do lado do hexágono: ");
    scanf("%f", &lado);

    calculaHexagono(lado, &area, &perimetro);

    printf("Área do hexágono: %.2f\n", area);
    printf("Perímetro do hexágono: %.2f\n", perimetro);

    return 0;
}