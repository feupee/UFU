#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int ano;

    printf("O ano: ");
    scanf("%i", &ano);

    if (ano % 400 == 0 || ano % 4 == 0 && ano % 100 != 0){
        printf("Seu ano e bissexto");
    }
        else 
            printf("Seu ano nao e bissexto");
            
  return 0;
}
