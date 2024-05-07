#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa que permita que o usuário entre com diversos nomes
e telefone para cadastro, e crie um arquivo com essas informações, uma
por linha. O usuário finaliza a entrada com ‘0’ para o telefone*/

struct cadastro {
    char nome[50];
    char telefone[50];
};

int main(){

    char result;
    struct cadastro pessoa;
    FILE *file = fopen("cadastro.txt", "w");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }

    do{
        printf("Digite o nome da pessoa: ");
        scanf("%s", pessoa.nome);
        printf("Digite o telefone no formato: ");
        scanf("%s", pessoa.telefone);
        fprintf(file, "Nome:%s, Telefone:%s\n", pessoa.nome, pessoa.telefone);
        printf("Deseja digitar outro perfil? Se sim entre com qualquer tecla, se nao entre com 0\nResposta: ");
        scanf(" %c", &result);
    }while(result != '0');

    fclose(file);

    return 0;
}