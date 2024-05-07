#include <stdio.h>
#include <stdlib.h>

int main() {

    
    int Sa, Au;

    printf("Informe o salario: ");
    scanf("%d", &Sa);

    Au = Sa + (Sa*0.25);

    printf("\n");
    printf("O valor do aumento com o salario eh:  %d", Au);
    
    return(0);

}