#include <stdio.h>

    struct dados{
        char nome[50];
        int idade;
        char endereco[100];
    };

int main(){

    struct dados pessoa1;

    printf("Digite o nome: ");
    fgets(pessoa1.nome, 50, stdin);

    printf("\nDigite a idade: ");
    scanf("%d", &pessoa1.idade);

    printf("\nDigite o endereco: ");
    fgets(pessoa1.endereco, 100, stdin);

    return 0;
}
