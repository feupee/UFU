#include <stdio.h>
#include <stdlib.h>

struct voo{
    int in, out;
};

struct aeroporto{
    int entrada;
    int saida;
};

int main(){

    int i;
    struct aeroporto c[5];
    struct voo f[5];
    for(i = 0; i < 5; i++){
        f[i].out = 0;
        f[i].in = 0;
        c[i].entrada = 0;
        c[i].saida = 0;
    }
    for(i = 0; i < 5; i++){
        printf("Saida do voo %i: ", i);
        scanf("%d", &f[i].out);
        printf("Entrada do voo %i: ", i);
        scanf("%d", &f[i].in);

        if(f[i].out > 4 || f[i].out < 0 || f[i].in < 0 || f[i].in > 4){
            printf("Direcao invalida");
            return 0;
        }
        c[f[i].in].entrada += 1;
        c[f[i].out].saida += 1;
    }

    for(i = 0; i < 5; i++){
        printf("\nAeroporto %i saida: %i", i, c[i].saida);
        printf("\nAeroporto %i entrada: %i", i, c[i].entrada);
        printf("\n");
    }

    return 0;
}
