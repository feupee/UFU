#include <stdio.h>
#include <string.h>

int main(){

    char string1[100], string2[100], stringaux[100];
    int i, l, j, k;

    printf("Digite a string 1: ");
    gets(string1);

    printf("Digite a string 2: ");
    gets(string2);

    l = strlen(string2);

    printf("Quanto deseja concatenar da string2(0 - %i) ate a string1: ", l);
    scanf("%i", &j);

    for(i = 0; i < j; i++){
        stringaux[i] = string2[i];
    }

    strcat(string1, stringaux);

    k = strlen(string1);

    if(string1[k] == '\0'){
        printf("\nString concatenateda eh: %s\n", string1);
    }
    
    return 0;
}