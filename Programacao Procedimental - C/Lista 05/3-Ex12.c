#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char vet[200];
    int i, k;

    printf("Digite a string: ");
    gets(vet);

    k = strlen(vet);

    for(i = 0; i < k; i++){

        if(vet[i] >= 65 || vet[i] == 32){
            if(vet[i] <= 90){

            if(vet[i] == 88){
                vet[i] = 65;
                printf("%c", vet[i]);
            }
            else if(vet[i] == 89){
                vet[i] = 66;
                printf("%c", vet[i]);
            }
            else if(vet[i] == 90){
                vet[i] = 67;
                printf("%c", vet[i]);
            }
            else if(vet[i] == 32){
            printf("%c", vet[i]);
            }
            else{
                printf("%c", vet[i]+3);
            }
            }
        } 
        if(vet[i] >= 97){
            if(vet[i] <= 122){
            if(vet[i] == 120){
                vet[i] = 97;
                printf("%c", vet[i]);
            }
            else if(vet[i] == 121){
                vet[i] = 98;
                printf("%c", vet[i]);
            }
            else if(vet[i] == 122){
                vet[i] = 99;
                printf("%c", vet[i]);
            }
            else if(vet[i] == 32){
            printf("%c", vet[i]);
            }
            else{
                printf("%c", vet[i]+3);
            }
        } 
        }
        }
    printf("\n");

    return 0;

}