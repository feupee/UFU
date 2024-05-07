#include <stdio.h> //Biblioteca para entrada e saída de dados
#include <stdlib.h> //Biblioteca para função exit e pause

/*Escreva um programa que:
a) Crie/abra um arquivo texto de nome “arq.txt”;
b) Permita que o usuário grave diversos caracteres nesse arquivo, até
que o usuário entre com o caractere ‘0’;
c) Feche o arquivo.
Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela
todos os caracteres armazenados.*/

int main(){

    char caracter;
    FILE *file;

    file = fopen("arq.txt", "w");
    if(file == NULL){
    printf("Erro ao abrir o arquivo\n");
    system("pause");
    exit(0);
    }
        while(caracter != '0'){
            printf("Digite o caractere: ");
            scanf(" %c", &caracter);
            fprintf(file, "%c", caracter);
    }
    fclose(file);
    file = fopen("arq.txt", "r");

    if(file == NULL){
    printf("Erro ao abrir o arquivo\n");
    system("pause");
    exit(0);
    }

    do
{
    //faz a leitura do caracter no arquivo apontado por pont_arq
    caracter = fgetc(file);
    
    //exibe o caracter lido na tela
    printf("%c" , caracter);    
    
}while (caracter != EOF);

    fclose(file);
    return 0;
}