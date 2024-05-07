#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que receba do usuário um arquivo texto e mostre na
tela quantas letras são vogais e quantas são consoantes.*/

int main(){

    char nomeArquivo[100];
    int countvogal = 0, countconsoante = 0;
    char caracter;

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

        if(caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u'
        || caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U'){
            countvogal++;
        }else{
            countconsoante++;
        }
        if(caracter == EOF){
            break;
        }
    }while(caracter != EOF);

    printf("Quantidade vogais eh: %d\nQuantidade de vogais eh: %d", countvogal, countconsoante);
    
    fclose(file);

    return 0;
}