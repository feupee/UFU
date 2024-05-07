//Exercício A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct calendario{
    char dia[03];
    char mes[03];
    char ano[05];
};

typedef struct calendario calendario;

void imprime_data(calendario *A){
    printf("%s/%s/%s", A->dia, A->mes, A->ano);
}

int main()
{
    calendario A;

    printf("Digite o dia: ");
    fgets(A.dia, 3, stdin);
    fflush(stdin);
    printf("Digite o mes: ");
    fgets(A.mes, 3, stdin);
    fflush(stdin);
    printf("Digite o ano: ");
    fgets(A.ano, 5, stdin);
    fflush(stdin);

    imprime_data(&A);

    return 0;
}
