#include <stdio.h>

int main(){

    int vet[10], i, j;

    for(i = 0; i < 10; i++){
        printf("Digite o vet[%i]: ", i);
        scanf("%d", &vet[i]);
            for(j = 0; j < i; j++){
                if(vet[i] == vet[j]){
                    printf("Numero ja digitado, digite outro; ", i);
                    i--;
                    break;
                }
            }

    }
        for(i = 0; i < 10; i++){
        printf("O vet[%d]: %i", i,vet[i]);
        printf("\n");
        }
    return 0;
}
