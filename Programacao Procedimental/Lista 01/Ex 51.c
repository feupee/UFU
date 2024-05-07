#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() { 

    float X=0, Y=0, R=0;

    printf("Insira a coordenada X: ");
    scanf("%f",&X);
    printf("\n");

    printf("Insira a coordenada Y: ");
    scanf("%f",&Y);

    R=sqrt(pow(X,2)+pow(Y,2));

    printf("\n");
    printf("A distancia entre os dois pontos no plano eh: %.2f", R);
}