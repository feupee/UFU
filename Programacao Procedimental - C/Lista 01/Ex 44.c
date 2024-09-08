#include <stdio.h>
#include <stdlib.h>

int main() {

    
    float De, Al, Qt;

    printf("Digite o tamanho do degrau: ");
    scanf("%f", &De);

    printf("Digite a altura que deseja chegar: ");
    scanf("%f", &Al);

    Qt = Al/De;

    printf("\n");
    printf("A quantiade de degraus a ser subidos :  %f", Qt);

    return(0);

}