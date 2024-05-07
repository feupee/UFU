#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int altura, peso;

    printf("Digite a altura em centimetros: ");
    scanf("%i", &altura);
    if(altura < 0 || altura > 230){
        printf("Valor invalido");
        exit(0);
    }
    printf("Digite o peso em KG: ");
    scanf("%i", &peso);
    if(peso < 0 || peso > 1000){
        printf("Valor invalido");
        exit(0);
    }

    if(altura < 120 && peso <= 60){
        printf("Sua classificacao eh: A ");
    }
    if(altura >= 120 && altura <= 170 && peso <= 60){
        printf("Sua classificacao eh: B ");
    }
    if(altura > 170 && peso < 60){
        printf("Sua classificacao eh: C ");
    }
    if(altura < 120 && peso > 60 && peso <= 90){
        printf("Sua classificacao eh: D ");
    }
    if(altura >= 120 && altura <= 170 && peso > 60 && peso <= 90){
        printf("Sua classificacao eh: E ");
    }
    if(altura > 170 && peso > 60 && peso <= 90){
        printf("Sua classificacao eh: F ");
    }
    if(altura < 120 && peso > 90){
        printf("Sua classificacao eh: G ");
    }
    if(altura >= 120 && altura <= 170 && peso > 90){
        printf("Sua classificacao eh: H ");
    }
    if(altura > 170 && peso > 90){
        printf("Sua classificacao eh: I ");
    }


  return 0;
}
