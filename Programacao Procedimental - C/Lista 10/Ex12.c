#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Abra um arquivo texto, calcule e escreva o número de caracteres, o
número de linhas e o número de palavras neste arquivo. Escreva
também quantas vezes cada letra ocorre no arquivo (ignorando letras
com acento). Obs.: palavras são separadas por um ou mais caracteres
espaço, tabulação ou nova linha.*/

int main(){

    char caracter;
    int countcaracter = 0;
    char palavra[100];
    int countlinha = 0;
    int countpalavra = 0;
    char *sub1;
    char texto[100];
    int k;
    FILE *file = fopen("cidade.txt", "r");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        system("pause");
        exit(0);
    }
    //contar caracteres, linha
    do{
        caracter = fgetc(file);
        if(caracter == EOF){
            break;
        }
        if(caracter != '\n'){
            countcaracter++;
        }
        if(caracter == '\n'){
            countlinha++;
        }
        if(caracter == EOF){
            break;
        }
    }while(caracter != EOF);
    
    do{
        
    fgets(palavra, 100, file);
    sub1 = strtok(palavra," ,!.");
    strcpy(texto, sub1);

    if(fgets(texto, 100, file) == NULL){
        break;
    }
    /*k = strlen(texto);
    for(int i = 0; i < k; i++){
        if(texto[i] == '\n'){
            countpalavra++;
        }
    } contar palavras falhando*/
    }while(!feof(file));

    printf("A quantidade de letras no arquivo eh: %d", countcaracter);
    printf("\nA quantidade de linhas no arquivo eh: %d", countlinha);
    printf("\nA quantidade de palavras no arquivo eh: %d", countpalavra);

    fclose(file);
    return 0;
}