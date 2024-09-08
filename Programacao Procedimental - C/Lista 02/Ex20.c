#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int A, B, C;

    printf("Digite o valor A: ");
    scanf("%i", &A);
    printf("\n");
    printf("Digite o valor B: ");
    scanf("%i", &B);
    printf("\n");
    printf("Digite o valor C: ");
    scanf("%i", &C);
    printf("\n");

    if(A + B < C || A + C < B || B + C < A ){
        printf("Valores invalidos para um triangulo");
        exit(0);
    }

    if (A == B && B == C) {
        printf("O triangulo e equilatero");
    }

        else
            if (A == B || B == C || A == C) {
            printf("O triangulo e isoceles");
            }      
                else 
                    printf("O triangulo e escaleno");

  return 0;
}
