#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int Bmaior, Bmenor, altura, Area;

    printf("Digite a base maior: ");
    scanf("%i", &Bmaior);

    printf("Digite a base maior: ");
    scanf("%i", &Bmenor);

    printf("Digite a alturaa: ");
    scanf("%i", &altura);

    if (Bmaior <= 0 || Bmenor <= 0){
        exit(0);
    }

    Area = ((Bmaior + Bmenor) * altura)/2;

    printf("O valor da area eh: %i", Area);

  return 0;
}

    