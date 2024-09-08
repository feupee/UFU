#include <stdio.h>
#define pi 3.14
#include <math.h>

/*Implemente uma função que calcule a área da superfície e o volume de uma
esfera de raio R. Essa função deve obedecer ao protótipo:
void calc_esfera(float R, float *area, float *volume);
A área da superfície e o volume são dados, respectivamente, por:
A = 4 * pi * R²
V = 4/3 * pi * R³*/

void calc_esfera(float R, float *area, float *volume){
    *area = 4.0 * pi * pow(R,2);
    *volume = 4.0/3.0 * pi * pow(R,3);
}

int main(){

    float R, area, volume;

    printf("Digite o raio: ");
    scanf("%f", &R);

    calc_esfera(R, &area, &volume);

    printf("Valor de R: %f", R);
    printf("\nValor da area: %f", area);
    printf("\nValor do volume: %f", volume);

    return 0;
}