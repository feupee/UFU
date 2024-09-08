#include <stdio.h>
#include <stdlib.h>

int main() {

    
  int num1, antecessor, sucessor;

    printf("Informe um numero inteiro: ");
    scanf("%d", &num1);

    sucessor = num1 + 1;
    antecessor = num1 - 1;
  
    printf("O valor da sucessor eh:  %d", sucessor);
    printf("\n");
    printf("O valor da antecessor eh:  %d", antecessor);
    
  
    return(0);

}