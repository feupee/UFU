#include <stdio.h>
#include <stdlib.h>

int main() {

    
    float Ra,Ar,Pi;

    printf("Informe o valor do raio: ");
    scanf("%f", &Ra);
  
    Pi = 3.141592;

    Ar = Pi*(Ra*Ra);

    printf("\n");
    printf(" O valor da area do quadrado eh:  %f", Ar);
    
    return(0);

}