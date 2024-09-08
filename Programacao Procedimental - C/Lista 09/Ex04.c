#include <stdio.h>
#include <stdlib.h>
//
/*Faça um programa que receba do usuário o tamanho de uma string e
chame uma função para alocar dinamicamente essa string. Em seguida,
o usuário deverá informar o conteúdo dessa string. O programa imprime
a string sem suas vogais*/

void tirarvogais(char *array){
    int i, j;

    for(i = 0; *(array+i) != '\0'; i++){
        if(*(array + i) ==  'a' || *(array + i) ==  'e' || *(array + i) ==  'i' || *(array + i) ==  'o' || *(array + i) ==  'u' 
        || *(array + i) ==  'A' || *(array + i) ==  'E' || *(array + i) ==  'I' || *(array + i) ==  'O' || *(array + i) ==  'U'){
            for(j = i; *(array+j) != '\0'; j++){
                *(array + j) = *(array+j+1); 
            }
            i--;
        }
    }

}

int main(){

    int N;
    char *array;

    printf("Digite o tamanho da string: ");
    scanf("%d",&N);
    fflush(stdin);

    array = (char *) malloc(N*(sizeof(char)));

    printf("Digite a string: ");
    fgets(array, N, stdin);

    tirarvogais(array);

    printf("Palavra sem as vogais: %s", array);

    free(array);

    return 0;
}