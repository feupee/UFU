#include <stdio.h>

int main(){

    int i, j;
    int matriz[5][5];
    int x;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("Digite o valor [%i,%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
    }

    printf("Digite o valor X: ");
    scanf("%i", &x);
    
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(x == matriz[i][j]){
                printf("Valor encontrado em [%i,%i]", i, j);
                break;
            }
        }
    }

    return 0;
}