#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num1, num2;

    printf("Digite a primeira nota: ");
    scanf("%i", &num1);

    printf("Digite a segunda nota: ");
    scanf("%i", &num2);

    if(num1 < 0 || num2 < 0 || num1 > 10 || num2 > 10) {
        printf("Nota(s) invalida(s)");
        exit(0);
    }
    else{
        printf("A media das notas eh: %i", (num1 + num2)/2);
    }

    return 0;
}