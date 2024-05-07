#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que receba do usuário um arquivo texto e um
caractere. Mostre na tela quantas vezes aquele caractere ocorre dentro
do arquivo.*/

int main(){

    char nomeArquivo[100];
    char letra;
    char caracter;
    int count = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    printf("Digite a letra: ");
    scanf(" %c", &letra);

    FILE *file;
    file = fopen(nomeArquivo, "rt");

    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    
    do{
        caracter = fgetc(file);
        if(caracter == letra){
            count++;
        }
        if(caracter == EOF){
            break;
        }
    }while(caracter != EOF);
    fclose(file);

    printf("Quantas vezes a letra %c aparece no arquivo eh: %d", letra, count);

    return 0;
}