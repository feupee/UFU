#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa no qual o usuário informa o nome do arquivo e uma
palavra, e retorne o número de vezes que aquela palavra aparece no
arquivo.*/

int main(){

    char nomeArquivo[100];
    char palavra[20];
    char conteudo[100];
    int count = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);
    printf("Digite a palavra: ");
    scanf("%s", palavra);

    FILE *file = fopen(nomeArquivo, "rt");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    while (fgets(conteudo, 100, file) != NULL) {
        char *tmp = conteudo;
        while ((tmp = strstr(tmp, palavra)) != NULL) {
            count++; // encontrei uma ocorrência
            tmp++; // continua a busca a partir da posição seguinte
        }
    }
    fclose(file);

    printf("A palavra \"%s\" ocorre %d vezes no arquivo %s\n", palavra, count, nomeArquivo);

    return 0;
}