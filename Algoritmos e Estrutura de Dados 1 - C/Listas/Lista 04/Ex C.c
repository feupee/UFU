#include <stdio.h>

/*void swap(int *a, int *b){
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}*/

void inverte(int tam, int vet[]) {
    int j = tam - 1;
    int temp;
    for (int i = 0; i < tam / 2; i++) {
        temp = vet[j];
        vet[j] = vet[i];
        vet[i] = temp;
        j--;
    }
}

int main(){

    int tam = 5;

    int vet[5];

    for(int i = 0; i < tam; i++){
        printf("Digite o vetor a ser trocado %d: ", i);
        scanf("%d", &vet[i]);
    }

    inverte(tam, vet);

    printf("O vetor modificado eh: ");
    for(int i = 0; i < tam; i++){
        printf("%d", vet[i]);
    }

    
    

    return 0;
}