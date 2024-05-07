#include <stdio.h>

struct dados{
    char nome[50];
    char endereco[100];
    int dia;
    int mes;
    int ano;
    char cep[11];
};

int main(){

    int i, k;
    struct dados c;

    printf("Digite seu nome: ");
    fgets(c.nome, 50, stdin);
    k = strlen(c.nome);
    

    return 0;
}