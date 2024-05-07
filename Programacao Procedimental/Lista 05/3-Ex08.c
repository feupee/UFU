#include <stdio.h>
#include <string.h>

int main(){

    int i, j;
    char A, B;
    char str[20];

    printf("Digite a string: ");
    fgets(str, 20, stdin);

    setbuf(stdin, NULL);

    printf("Digite qual letra deseja trocar: ");
    scanf("%c", &A);

    setbuf(stdin, NULL);

    printf("Digite por qual letra trocar: ");
    scanf("%c", &B);

    j = strlen(str);

    for(i = 0; i < j; i++){
        if(str[i] == A){
            str[i] = B;
        }
    }

    printf("\n%s\n", str);

    return 0;
}