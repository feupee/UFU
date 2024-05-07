#include <stdio.h>

int main(){

    int vet[6];
    int i;

    for(i = 0; i < 6; i++){
        printf("Digite o valor %i: ", i);
        scanf("%i", &vet[i]);
    }
    for(i = 5; i >= 0; i--){
        printf("%i", vet[i]);
        printf("\n");
    }

    return 0;
}