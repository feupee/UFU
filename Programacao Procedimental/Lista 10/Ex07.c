#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que receba do usuário um arquivo texto. Crie outro
arquivo texto contendo o texto do arquivo de entrada, mas com as
vogais substituídas por ‘*’.*/

int main(){

    char nomeArquivo[100];
    char caracter;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    FILE *file, *file2;
    file = fopen(nomeArquivo, "rt");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    file2 = fopen("Exemplar.txt", "w");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
        while(!feof(file)){
            caracter = fgetc(file); 
            if(caracter == '\n'){
                break;
            }
            else if(caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u'
            || caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U'){
                caracter = '*';
            }
            fprintf(file2, "%c", caracter);
            if(caracter == EOF){
            break;
            }
        }

    fclose(file);
    fclose(file2);

    return 0;
}