//Exercício A

#include <stdio.h>
#include <stdlib.h>

void recebe(int tam, float * media, int * maior, int * p){

    int i;

    *media = *p;
    *maior = *p;

    for(i = 1; i < tam; i++){
        *media += *(p+i);
    }

    *media /= tam;

}

int main()
{
    int tam, maior;
    float media;


    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    if(tam <= 0){
        printf("Impossivel continuar");
        return 0;
    }    

    int *p;
    
    p = malloc(tam*sizeof(int));
    
    for(int i = 0; i < tam; i++){
        printf("Digite valor %d: ", i);
        scanf("%d", (p+i));
    }

    recebe(tam, &media, &maior, p); 

    printf("media eh: %f\n", media);
    printf("maior valor eh: %d\n", maior);

    // Libere a memória alocada quando não precisar mais do vetor
    free(p);

    return 0;
}
