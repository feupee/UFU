#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Dado um arquivo contendo um conjunto de nome e data de nascimento
(DD MM AAAA), isto é, 3 inteiros em sequência), faça um programa que
leia o nome do arquivo e a data de hoje e construa outro arquivo
contendo o nome e a idade de cada pessoa do primeiro arquivo.
*/

int main(){

    FILE *file = fopen("pessoas.txt", "r");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    FILE *file2 = fopen("idade.txt ", "w");
    if(file2 == NULL){
        printf("Nao foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }
    char string[100];
    char nome[80];
    int dia;
    int mes;
    int ano;
    char *sub;
    int diaatual;
    int mesatual;
    int anoatual;
    int idade;

    printf("Digite a data atual -->\n");
    printf("Digite o ano: ");
    scanf("%d", &anoatual);
    printf("Digite o mes: ");
    scanf("%d", &mesatual);
    while(mesatual > 12 || mesatual < 0){
        printf("mes invalido, digite novamente:");
        scanf("%d", &mesatual);
    }
    printf("Digite o dia: ");
    scanf("%d", &diaatual);
    if(mesatual == 1 || mesatual == 3 || mesatual == 5 || mesatual == 7 || mesatual == 8 || mesatual == 10 || mesatual == 12 ){
        while(diaatual > 31 || diaatual < 0){
            printf("Dia inexistente nesse mes, digite novamente: ");
            scanf("%d", &diaatual);
        }
    }
    if(mesatual == 4 || mesatual == 6 || mesatual == 9 || mesatual == 11){
        while(diaatual > 30 || diaatual < 0){
            printf("Dia inexistente nesse mes, digite novamente: ");
            scanf("%d", &diaatual);
        }
    }
    if(mesatual == 2){
        if(anoatual % 400 == 0){
        while(diaatual > 29|| diaatual < 0){
            printf("Dia inexistente nesse mes, digite novamente: ");
            scanf("%d", &diaatual);
        }
        }else{
           while(diaatual > 28|| diaatual < 0){
            printf("Dia inexistente nesse mes, digite novamente: ");
            scanf("%d", &diaatual);
        } 
        }
    }
    
    do{
    fgets(string, 100, file);
    sub = strtok(string,",");
    strcpy(nome,sub);
    sub = strtok(NULL," ");
    dia = atoi(sub);
    sub = strtok(NULL," ");
    mes = atoi(sub);
    sub = strtok(NULL," ");
    ano = atoi(sub);

    if(ano > anoatual){
        idade = 0;
        break;
    }

    idade = anoatual - ano;

    if(mesatual < mes){
        idade--;
    }
    if(mesatual == mes){
        if(diaatual < dia){
            idade--;
        }
    }

    fprintf(file2, "Nome: %s, Idade: %d\n", nome, idade);
    
    }while(fgets(string, 100, file) != NULL);
    fclose(file);
    fclose(file2);
    return 0;

    
}