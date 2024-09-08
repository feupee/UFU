#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que receba do usuário um arquivo texto e mostre na
tela quantas linhas esse arquivo possui.*/

int main(){

    int count = 0;
    char texto[100];
    char nomeArquivo[20];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    FILE *file;

    file = fopen(nomeArquivo, "rt");

    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        system("pause");
        exit(0);
    }

    while(fgets(texto, 100, file) != NULL){
        count++;
    }

    printf("\nA quantidade de linhas eh: %d", count);

    fclose(file);

    return 0;
}