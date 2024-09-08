#include <stdio.h>

/*8 Implemente uma função que receba como parâmetro um array de números
reais de tamanho N e retorne quantos números negativos há nesse array.
Essa função deve obedecer ao protótipo: int negativos(float *vet, int
N);
*/

int negativos(float *vet, int N){
    int i;

    for(i = 0; i < 5; i++){
        printf("Digite o numero %d: ", i);
        scanf("%f", &vet[i]);
    }

    for(i = 0; i < 5; i++){
        if(*(vet + i) < 0){
            N++;
        }
    }

    printf("\nQuantos negativos possui: %d", N);

    return 0;

}

int main(){

    int N = 0;

    float vet[5];

    negativos(vet, N);

    return 0;
}