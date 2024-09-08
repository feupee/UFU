// Enviando arquivo atrasado com permissão do Claudiney //

#include <stdio.h>
#include <string.h>

int main(){

    char string[100];
    int i, j;

    printf("Digite a string: ");
    fgets(string, 100, stdin);

    j = strlen(string);

    for(i = 0; i < j; i++){
        if(string[i+1] != ' ' && string[i+1] != '\n'){
        if(string[i] == 114){
            string[i] = 108;
                if(string[i+1] == 114){
                    string[i] = 118;
             }
        }
        if(string[i] == 82){
            string[i] = 76;
                if(string[i+1] == 82){
                    string[i] = 76;
             }
        }

    }
}

    printf("\n%s", string);

    return 0;
}
