#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa que receba como entrada o ano corrente e o nome de
dois arquivos: um de entrada e outro de saída. Cada linha do arquivo de
entrada contém o nome de uma pessoa (ocupando 40 caracteres) e o
seu ano de nascimento. O programa deverá ler o arquivo de entrada e
gerar um arquivo de saída onde aparece o nome da pessoa seguida por
uma string que representa a sua idade.
- Se a idade for menor do que 18 anos, escreva “menor de idade”;
- Se a idade for maior do que 18 anos, escreva “maior de idade”;
- Se a idade for igual a 18 anos, escreva “entrando na maior idade”.*/

int main(){

    char nomeArquivo1[50];
    char nomeArquivo2[50];
    char stringidade[10];
    char string[100];
    char nome[40];
    char *sub;
    int anoatual;
    int idade;
    int anonascimento;

    //Pegar arquivos de entrada e saida
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivo1);
    printf("Digite o nome do arquivo de saida: ");
    scanf("%s", nomeArquivo2);
    FILE *file = fopen(nomeArquivo1, "rt");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    FILE *file2 = fopen(nomeArquivo2, "w");
    if(file2 == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    //Pegar ano
    printf("Digite o ano: ");
    scanf("%d", &anoatual);
    
    do{
    fgets(string, 100, file);
    sub = strtok(string,",");
    strcpy(nome,sub);
    sub = strtok(NULL," ");
    anonascimento = atoi(sub);
    if(anoatual <= anonascimento){
        idade = 0;
    }else
    idade = anoatual - anonascimento;
    sprintf(stringidade, "%d", idade);

    if(idade < 18){
        fprintf(file2, "Nome: %s, Idade: %s, Menor de idade\n", nome, stringidade);
    }
    if(idade == 18){
        fprintf(file2, "Nome: %s, Idade: %s, Entrando na maior de idade\n", nome, stringidade);
    }
    if(idade > 18){
        fprintf(file2, "Nome: %s, Idade: %s, Maior de idade\n", nome, stringidade);
    }
    
    
    }while(fgets(string, 100, file) != NULL);
    fclose(file);
    fclose(file2);
    return 0;

    return 0;
}