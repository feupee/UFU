#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float num;
    int numinteiro;

    printf("Digite o numero para verificacao: ");
    scanf("%f", &num);

    numinteiro = num;

    if(num < 1 || num != numinteiro){
        printf("Nao eh um quadrado perfeito");
        exit(0);
    }
    void verificador(float num);
    verificador(num);

    return 0;
}

void verificador(float num){

    float verificador1 = sqrt(num);
    int verificador2 = verificador1;

    if(verificador2 == verificador1){
        printf("O numero eh um quadrado perfeito de %.2f: ", verificador1);
    }
    else 
        printf("O numero nao eh um quadrado perfeito");

}
