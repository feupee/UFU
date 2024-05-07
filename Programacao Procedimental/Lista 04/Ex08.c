#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int A, B;

    printf("Digite o valor do primeiro cateto: ");
    scanf("%d",&A);
    printf("Digite o valor do segundo cateto: ");
    scanf("%d",&B);

    if(A < 0 || B < 0){
        printf("Valor invalido");
        exit(0);
    }

    void hipotenusa(int A, int B);
    hipotenusa(A, B);

    return 0;
}

void hipotenusa(int A, int B){

    float hipotenusa = sqrt((A*A)+(B*B));
    printf("A hipotenusa eh: %f", hipotenusa);

}
