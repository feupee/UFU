#include <stdio.h>

int main(){

    int vet[6];
    int i, somapar = 0, quantimpar = 0;

    for(i = 0; i < 6; i++){
        printf("Digite o numero %i: ", i);
        scanf("%d", &vet[i]);
    }

    for(i = 0; i < 6; i++){
        
        if(vet[i] % 2 == 0){
            printf("O vet[%i] eh par: %i", i, vet[i]);
            printf("\n");
            somapar += vet[i];
        }
        else{
            printf("O vet[%i] eh impar: %i", i, vet[i]);
            printf("\n");
            quantimpar += 1;
        }
    }

    printf("A soma dos numeros pares eh: %i", somapar);
    printf("\n");

    printf("A quantidade de numeros impares eh: %i", quantimpar);

    return 0;
}