#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    int i, j;
    int matriz[4][4];

    srand(time(NULL));
//matriz original//
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            matriz[i][j] = rand() % 20; 
        }
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("[%-2i]", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
//matriz transformada//
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(j > i){
                matriz[i][j] = 0;
            } 
        }
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("[%-2i]", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}