#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int distancia, Lg;

    printf("Digite a distancia em KM: ");
    scanf("%i", &distancia);

    printf("Digite a quantidade de litros de gasolina gasta: ");
    scanf("%i", &Lg);

    void consumo(int distancia, int Lg);
    consumo(distancia, Lg);

    return 0;
}

void consumo(int distancia, int Lg){

    int kmL = distancia / Lg;

    if (kmL < 8) {
        printf("Venda o carro");
    }
    if (kmL >= 8 && kmL <= 14) {
        printf("Economico!");
    }
    if (kmL > 14) {
        printf("Super economico!");
    }
}