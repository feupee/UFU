#include <stdio.h>
#include <stdlib.h>

int main() {

    
    float Sa, Gr, Im, Final;

    printf("Digite o valor do salario base: ");
    scanf("%f", &Sa);

    Gr = Sa*0.05;
    Im = Sa*0.07;

    Final = (Sa + Gr) - Im;

    printf("\n");
    printf("O valor a ser pago final eh:  %f", Final);

    return(0);

}