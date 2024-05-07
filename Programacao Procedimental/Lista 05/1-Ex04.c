#include <stdio.h>
#include <math.h>

int main(){

    int vet[5];
    int maior = 0; 
    int menor;
    int i;

    for(i = 0; i < 5; i++){
        printf("Digite o valor da posicao %i: ", i);
        scanf("%i", &vet[i]);

        if(maior < vet[i]){
            maior = vet[i];
        }
        if(menor > vet[i]){
            menor = vet[i];
        }
    }

    printf("O maior numero e o menor sao: %i e %i", maior, menor);

    return 0;
}