//Exercício B

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int troca(int tam, char *String, char caracter){

    int count = 0;

    for(int i = 0; i < tam; i++){
        if(*(String+i) == caracter){
            *(String+i) = '*';
            count++;
        }
    }

    return count;

}

int main(){

    int tam, count;
    char caracter;

    printf("Digite o tamanho da string: ");
    scanf("%d", &tam);

    char *String;

    String = malloc(tam*sizeof(char));

    printf("Digite qual caracter deve mudar: ");
    scanf(" %c", &caracter);
    fflush(stdin);

    printf("Digite a String: ");
    fgets(String, tam, stdin);

    count = troca(tam, String, caracter);

    printf("contador: %d\n", count);
    printf("String modificada: %s", String);

    // Libere a memória alocada quando não precisar mais do vetor
    free(String);

    return 0;
}