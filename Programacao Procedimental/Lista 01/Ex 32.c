#include <stdio.h>
#include <stdlib.h>

int main() {

    
  int num1, antecessor, sucessor;

    printf("Informe um numero inteiro: ");
    scanf("%d", &num1);

    sucessor = (num1*3) + 1;
    antecessor = (num1*2) - 1;
  
    printf("\n");
    printf(" O valor da soma eh:  %d", sucessor + antecessor);
    
    return(0);

}