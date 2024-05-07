#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que receba dois arquivos do usuário, e crie um
terceiro arquivo com o conteúdo dos dois primeiros juntos (o conteúdo
do primeiro seguido do conteúdo do segundo).*/

int main(){

    char nomeArquivo1[100];
    char nomeArquivo2[100];
    char caracter;

    printf("Digite o nome do arquivo1: ");
    scanf("%s", nomeArquivo1);

    printf("Digite o nome do arquivo2: ");
    scanf("%s", nomeArquivo2);

    FILE *file1, *file2, *file3;
    file1 = fopen(nomeArquivo1, "rt");
    if(file1 == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    file2 = fopen(nomeArquivo2, "rt");
    if(file2 == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    file3 = fopen("testebom.txt", "w");
    if(file3 == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }

    do{
        caracter = fgetc(file1);
        fprintf(file3, "%c", caracter);
        if(caracter == EOF){
            break;
        }
    }while(!feof(file1));
    do{
        caracter = fgetc(file2);
        fprintf(file3, "%c" ,caracter);
        if(caracter == EOF){
            break;
        }
    }while(!feof(file2));

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}