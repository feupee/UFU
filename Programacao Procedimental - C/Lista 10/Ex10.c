#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa que receba o nome de um arquivo de entrada e outro
de saída. O arquivo de entrada contém em cada linha o nome de uma
cidade (ocupando 40 caracteres) e o seu número de habitantes. O
programa deverá ler o arquivo de entrada e gerar um arquivo de saída
onde aparece o nome da cidade mais populosa seguida pelo seu número
de habitantes*/

int main(){

    char NomeE[100];
    char NomeS[100];
    FILE *E, *S;
    char nome[40];
    int population;
    int auxnumero = 0;
    char auxchar[40];
    char string[100];
    char *sub1;
    char *sub2;
    char subchar[100];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", NomeE);
    E = fopen(NomeE, "rt");
    if(E == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    
    do{
    fgets(string, 100, E);
    sub1 = strtok(string,",");
    sub2 = strtok(NULL,",");
    strcpy(nome, sub1);
    strcpy(subchar, sub2);
    population = atoi(subchar);
    if(population > auxnumero){
        auxnumero = population;
        strcpy(auxchar, nome);
    }
    if(fgets(string, 100, E) == NULL){
        break;
    }
    }while(!feof(E));

    fclose(E);

    printf("Digite o arquivo de saida: ");
    scanf("%s", NomeS);
    S = fopen(NomeS, "w");
    if(S == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    fprintf(S, "Nome da cidade mais populosa: %s\nNumero de habitantes: %d", nome, auxnumero);
    fclose(S);
    return 0;
}