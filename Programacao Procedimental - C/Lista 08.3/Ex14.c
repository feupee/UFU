#include<stdio.h>
#include<math.h>

int raizes(float A, float B, float C, float *X1, float *X2){
    if(B*B-4*A*C<0){
        return 0;
    }
    *X1=((-1)*B-sqrt(B*B-4*A*C))/(2*A);
    *X2=((-1)*B+sqrt(B*B-4*A*C))/(2*A);
    if(*X1==*X2){
        return 1;
    }
    return 2;
}

int main(){
    float a, b, c, x1, x2;
    int aux;
    printf("Insira o valor de a: ");
    scanf("%f", &a);
    printf("Insira o valor de b: ");
    scanf("%f", &b);
    printf("Insira o valor de c: ");
    scanf("%f", &c);
    aux=raizes(a, b, c, &x1, &x2);
    if(aux==2){
        printf("Uma das raizes eh %.1f e a outra eh %.1f", x1, x2);
    } else if(aux==1){
        printf("A unica raiz eh %.1f", x1);
    } else{
        printf("Esse numero nao tem raizes reais");
    }
    return 0;
}