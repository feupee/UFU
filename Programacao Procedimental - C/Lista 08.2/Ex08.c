#include <stdio.h>

/*Considere a seguinte declaração: int A, *B, **C, ***D; Escreva um
programa que leia a variável ‘A’ e calcule e exiba o dobro, o triplo e o
quádruplo desse valor utilizando apenas os ponteiros B, C e D. O ponteiro B
deve ser usada para calcular o dobro, C o triplo e D o quádruplo.*/

int main(){

    int A, *B = &A, **C = &B, ***D = &C;

    printf("Digite a variavel A: ");
    scanf("%d", &A);

    printf("O dobro eh: %d", (*B*2));
    printf("\nO triplo eh: %d", (**C*3));
    printf("\nO quadruplo eh: %d", (***D*4));


    return 0;
}