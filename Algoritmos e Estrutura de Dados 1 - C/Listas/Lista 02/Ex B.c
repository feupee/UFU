#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *vet;
    //alocando memoria 
    vet = (int *)malloc(5*sizeof(int));
    if (vet == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }
    //recebendo informações do vetor
    for(int i = 0; i< 5; i++){
        printf("Digite numero %d: ", (i+1));
        scanf("%d", &vet[i]);
    }
    
    //printando vetor
    for(int i = 0; i< 5; i++){
        printf("Numero %d eh: %d\n", (i+1), *(vet+i));
    }

    free(vet);

    return 0;
}