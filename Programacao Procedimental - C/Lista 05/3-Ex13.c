#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char palavra_inicial[100];
    char palavra_invertida[100];
    int i, k, j;

    printf("Digite a string: ");
    gets(palavra_inicial);

    k = strlen(palavra_inicial);
    
    j = k - 1;

    for(i = 0; i < k; i++){
        palavra_invertida[j] = palavra_inicial[i];
        j--;
    }

    j = k - 1;

    for(i = 0; i < k; i++){

        if(palavra_inicial[i] != palavra_invertida[i]){
            printf("\nPalavra original: %s", palavra_inicial);
            printf("\nPalavra invertida: %s\n", palavra_invertida);
            printf("A palavra nao eh um palindromo\n");
            exit(0);
        }
    }

    printf("\nPalavra original: %s", palavra_inicial);
    printf("\nPalavra invertida: %s\n", palavra_invertida);

    printf("\nA palavra digita eh um palindromo\n");

    return 0;

}