#include <stdio.h>

/*Crie um programa que contenha um array de inteiros contendo 5 elementos.
Utilizando apenas aritmética de ponteiros, leia esse array do teclado e
imprima o dobro de cada valor lido.*/

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
    printf("%d\n", (*ptr_valores) * 2);
    ++ptr_valores;
  }

  return 0;
}