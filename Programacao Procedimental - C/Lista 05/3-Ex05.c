#include <stdio.h>
#include <string.h>

int main(){

    int i, j;
    char str[20];
    printf("Digite a string em MAIUSCULAS: ");
    gets(str);

    j = strlen(str);

    for(i = 0; i < j; i++){
        str[i] = str[i] + 32;
    }

    printf("\n%s\n", str);

    return 0;
}