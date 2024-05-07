#include <stdio.h>

int main() {

    
    int Dias, Vdias;

    float Final;

    printf("Informe os dias trabalhados: ");
    scanf("%d", &Dias);

    Vdias = Dias * 30;
    Final = Vdias - (Vdias*0.08);

    printf("\n");
    printf("A quantia liquida com o desconto do imposto de renda eh:  R$%.2f", Final);

    return(0);

}