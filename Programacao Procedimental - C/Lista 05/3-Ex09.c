#include <stdio.h>
#include <string.h>

int main(){

    int i, consumo[5], j = 0, k;
    char carros[5][100];
    int distancia;

    for(i = 0; i < 5; i++){
        
        printf("\nDigite o carro %i: ", i);
            gets(carros[i]);
            
        printf("Quantos o carro %i faz(Km/L): ", i);
            
            scanf("%i", &consumo[i]);
        getchar();

            if(consumo[i] > j){
                j = consumo[i];
                k = i;
            }
    }

        printf("\nO modelo de carro mais economico eh: %s\n", carros[k]);
    
    for(i = 0; i < 5; i++){

        distancia = 1000 / consumo[i];
        printf("O carro %s em 1000 quilometros gasta: %iL de gasolina\n", carros[i], distancia);
    }

    return 0;
}