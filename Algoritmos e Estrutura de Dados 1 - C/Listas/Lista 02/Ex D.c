#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, *vet, i;

    //recebendo informações do vetor

    printf("Digite tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int *)malloc(n*sizeof(int));

    for(i = 0; i < n; i++){
        printf("Digite elemento %d: ", i);
        scanf("%d", &vet[i]);
    }

    // Removendo elementos ímpares
    int novotamanho = 0;
    for (int i = 0; i < n; i++) {
        if (vet[i] % 2 == 0) {
            vet[novotamanho] = vet[i];
            novotamanho++;
        }
    }

    vet = realloc(vet, novotamanho*sizeof(int));

    for(i = 0; i < novotamanho; i++){
        printf("Valor %d: %d\n", i, vet[i]);
    }

    //liberando memória

    free(vet);

    return 0;
}