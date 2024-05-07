#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct livro{   //título, autor, ano;
    char tit[32], aut[17];
    unsigned int yr;
} liv;


int substringVer(char sub[], char S[]);     //função que checa se uma string é substring de outra;


int main(){
    //var. pesq é a variável que armazena a string pesquisada pelo usuário;
    liv l[5];
    char pesq[32];
    int i, j;

    printf("\tARQUIVO DE LIVROS\n\n");      //coleta de dados dos livros;
    for(i = 0; i < 5; i++){
        printf("Insira o titulo do %do livro (max 30 caracteres).\n>> ", i+1);
        setbuf(stdin, NULL);
        fgets(l[i].tit, 32, stdin);
        for(j = 0; l[i].tit[j] != '\0'; j++){       //removendo o \n do fgets();
            if(l[i].tit[j] == '\n') l[i].tit[j] = 0;
        }

        printf("Insira o autor do %do livro (max 15 caracteres).\n>> ", i+1);
        setbuf(stdin, NULL);
        fgets(l[i].aut, 32, stdin);
        for(j = 0; l[i].aut[j] != '\0'; j++){       //removendo o \n do fgets();
            if(l[i].aut[j] == '\n') l[i].aut[j] = 0;
        }

        printf("Insira o ano de lancamento do %do livro.\n>> ", i+1);
        scanf("%u", &l[i].yr);
        printf("\n\t= = = = = = = = =\n\n");
    }

    //loop do programa, permite que o usuário pesquise vários resultados no banco de dados de livros;
    do{
        j = 0;  //j está sendo reciclada como variável de checagem para conferir se algum livro foi encontrado pela ferramenta de pesquisa;
        printf("\n\n\nPesquise um livro por titulo (ou escreva '!' para encerrar o programa).\n>> ");
        setbuf(stdin, NULL);
        fgets(pesq, 32, stdin);
        for(i = 0; pesq[i] != '\0'; i++){
            if(pesq[i] == '\n') pesq[i] = 0;
        }
        printf("\n");

        //loop de exibição de livros;
        for(i = 0; i < 5; i++){
            if(substringVer(pesq, l[i].tit) == 1){
                printf("\t- %s\t%s\t%u -\n", l[i].tit, l[i].aut, l[i].yr);
                j++;
            }
            if(i == 4 && j == 0 && pesq[0] != 33){
                printf("Nenhum livro encontrado.\n");
            }
        }
    }while((strlen(pesq) != 1) || (pesq[0] != '!'));

    printf("Encerrando...");

    printf("\n\n");
    system("pause");
    return 0;
}


int substringVer(char sub[], char S[]){

    //var. temp é uma string temporária;
    int i, j, k = 0;
    char temp[32];

    //loop principal: testa cada caracter de S;
    for(i = 0; S[i] != '\0'; i++){
        for(j = i; sub[k] != '\0'; j++){
            temp[k] = S[j]; //passa os caracteres para uma string temporária, antes de comparar esta com sub;
            k++;
        }
        if(strcmp(temp, sub) == 0){
            return 1;
        }
        k = 0;
    }
    return 0;
}