#include <stdio.h>
#include <string.h>

int main(){

    int i, j, k = 0;

    char str[100];
    char str1[100];
    printf("Digite a string: ");
    fgets(str,100,stdin);

    j = strlen(str);

    for(i = 0; i < j; i++){
        if(str[i] != ' '){
            str1[k] = str[i];
            k++;
        }
    }

    str1[i] = '\0';

    printf("\n%s\n", str1);
     
    return 0;
}