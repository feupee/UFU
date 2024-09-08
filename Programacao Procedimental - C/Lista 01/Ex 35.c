#include <stdio.h>

int main() {

    
    int a, b, H;

    printf("Informe o valor de a: ");
    scanf("%d", &a);
    printf("Informe o valor de b: ");
    scanf("%d", &b);

    H = sqrt((a*a)+(b*b));

    printf("\n");
    printf("O valor da hipotenusa eh:  %d", H);
    
    return(0);

}