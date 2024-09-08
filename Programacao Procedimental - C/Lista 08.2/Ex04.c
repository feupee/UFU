#include <stdio.h>

/*Crie um programa que contenha um array contendo 5 elementos inteiros.
Leia esse array do teclado e imprima o endereço das posições contendo
valores pares.*/

int main() {
  int valores[5];
  int *ptr_valores = valores;

  for(int i = 0; i < 5; ++i) {
    printf("Insira um número: ");
    scanf("%d", ptr_valores);
    ++ptr_valores;
  }
  
  ptr_valores = valores;

  for(int i = 0; i < 5; ++i) {
    if(*ptr_valores % 2 == 0){
    printf("%d\n", (*ptr_valores));
    }
    ++ptr_valores;
  }

  return 0;
}