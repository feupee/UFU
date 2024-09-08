#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float A, B;

    printf("Digite o valor do primeiro numero: ");
    scanf("%f",&A);
    printf("Digite o valor do segundo numero: ");
    scanf("%f",&B);

    void maior(float A, float B);
    maior(A, B);

    return 0;
}

void maior(float A, float B){

    if(A > B){
        printf("%.2f eh o maior", A);
    }
    if(A < B){
        printf("%.2f eh o maior", B);
    }
    if(A == B){
        printf("Os dois valores sao iguais");
    }
    

}