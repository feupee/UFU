#include <stdio.h>

struct carros{
    char carro[15];
    int ano;
    int preco;
};

int main(){

    struct carros c[5];
    int i;
    float p;

    for(i = 0; i < 5; i++){
        printf("Digite o nome do carro %i: ", i);
        setbuf(stdin, NULL);
        fgets(c[i].carro, 15, stdin);
        printf("Digite o ano do carro %i: ", i);
        scanf("%d", &c[i].ano);
        printf("Digite o preco do carro %i: ", i);
        scanf("%d", &c[i].preco);
    }

    printf("Digite um preco p: ");
    scanf("%f", &p);

    while(p != 0){
    for(i = 0; i < 5; i++){
        if(c[i].preco < p){
            printf("\nNome: %s", c[i].carro);
            printf("Ano: %d", c[i].ano);
            printf("\nPreco: %d", c[i].preco);
        }
    }

    printf("\nDigite um preco p: ");
    scanf("%f", &p);
    }

    return 0;
}