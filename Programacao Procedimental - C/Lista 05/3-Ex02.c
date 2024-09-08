#include <stdio.h>
#include <string.h>

int main(){

    int i, j;
    int count = 1;

    char str[20];
    printf("Digite a string: ");
    gets(str);

    j = strlen(str) - 1;

    for(i = 0; i < j; i++){
        if(str[i] == '1'){
            count++;
        }
    }

    printf("A quantidade 1's na string eh: %i\n", count);

    return 0;
}