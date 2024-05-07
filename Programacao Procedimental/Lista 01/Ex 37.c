#include <stdio.h>
#include <stdlib.h>

int main() {

    
    int Pr, De;

    printf("Informe o valor do produto: ");
    scanf("%d", &Pr);

    De = Pr - (Pr*0.12);

    printf("\n");
    printf("O valor do produto com desconto eh:  %d", De);
    
    return(0);

}