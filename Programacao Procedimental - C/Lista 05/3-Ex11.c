#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char vet[100];
    int i, k, a, b;

    printf("Digite a string: ");
    gets(vet);

    k = strlen(vet);

    printf("De onde quer comecar (0 - %i): ", k);
    scanf("%i", &a);
    if(a < 0 || a > k){
        printf("Valor invalido");
        exit (0);
    }
    printf("De onde quer parar (%i - %i): ", a, k);
    scanf("%i", &b);
    if(b < 0 || b < a || b > k){
        printf("Valor invalido");
        exit (0);
    }

    for(i = a; i < b; i++){
        printf("%c", vet[i]);
    }
    printf("\n");

    return 0;
}