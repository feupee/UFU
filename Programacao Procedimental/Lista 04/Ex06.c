#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int horas, minutos, segundos;

    printf("Digite o valor em horas: ");
    scanf("%i",&horas);
    printf("Digite o valor em minutos: ");
    scanf("%i",&minutos);
    printf("Digite o valor em segundos: ");
    scanf("%i",&segundos);

    if(horas < 0 || horas > 24 || minutos < 0 || minutos > 60 || segundos < 0 || segundos > 60){
        printf("valor invalido");
        exit(0);
    }

    void transformador(int horas, int minutos, int segundos);
    transformador(horas, minutos, segundos);
    
    return 0;
}

void transformador(int horas, int minutos, int segundos){

    int valorfinal;

    horas = (horas*60)*60;
    minutos = minutos*60;
    segundos = segundos;

    valorfinal = horas + (minutos + segundos);

    printf("O valor em segundos eh: %i", valorfinal);

}