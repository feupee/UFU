#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que receba do usuário um arquivo texto e mostre na
tela quantas vezes cada letra do alfabeto aparece dentro do arquivo.*/

int main(){

    char nomeArquivo[100];
    char caracter;
    int count = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    FILE *file;
    file = fopen(nomeArquivo, "rt");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    do{
        caracter = fgetc(file);
        if(caracter >= 65 && caracter <= 90 || caracter >= 97 && caracter <= 122){
            count++;
        }
        if(caracter == EOF){
            break;
        }
    }while(caracter != EOF);
    fclose(file);

    printf("Quantidade de letras do alfabeto no arquivo: %d", count);

    return 0;
}