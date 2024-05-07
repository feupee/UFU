#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int linhas;

    printf("Digite o valor de linhas: ");
    scanf("%i", &linhas);

    void desenha_linha(int linhas);
    desenha_linha(linhas);

    return 0;
}

void desenha_linha(int linhas){

    int cont;

    for(cont = 0; cont < linhas; cont++){
        printf("=");
    }

}