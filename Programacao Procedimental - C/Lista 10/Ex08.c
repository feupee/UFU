#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que leia o conteúdo de um arquivo e crie um arquivo
com o mesmo conteúdo, mas com todas as letras minúsculas
convertidas para maiúsculas. Os nomes dos arquivos serão fornecidos,
via teclado, pelo usuário. A função que converte maiúscula para
minúscula é o toupper(). Ela é aplicada em cada caractere da string.*/

int main(){

    char nomeArquivo1[100];
    char nomeArquivo2[100];
    char caracter;

    printf("Digite o nome do arquivo1: ");
    scanf("%s", nomeArquivo1);
    printf("Digite o nome do arquivo2: ");
    scanf("%s", nomeArquivo2);

    FILE *file1, *file2;
    file1 = fopen(nomeArquivo1, "rt");
    if(file1 == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    file2 = fopen(nomeArquivo2, "w");
    if(file2 == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    do{
        caracter = fgetc(file1);
        if(caracter >= 97 && caracter <= 122){
            caracter = caracter - 32;
        }
        fprintf(file2, "%c", caracter);
        if(caracter == EOF){
            break;
        }
    }while(!feof(file1));

    fclose(file1);
    fclose(file2);

    return 0;
}