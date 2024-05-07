#include <stdio.h>
#include <stdlib.h>

int main() { 

    float AmigoA, AmigoB, AmigoC, ValorAmigo, Premio;

    printf("Quanto o Amigo A investiu: ");
    scanf("%f",&AmigoA);

    printf("Quanto o Amigo B investiu: ");
    scanf("%f",&AmigoB);

    printf("Quanto o Amigo C investiu: ");
    scanf("%f",&AmigoC);
    printf("\n");

    ValorAmigo = AmigoA + AmigoB + AmigoC;
    Premio = 1000000;

    float ValorA, ValorB, ValorC;

    ValorA = (AmigoA * 100)/ValorAmigo;
    ValorB = (AmigoB * 100)/ValorAmigo;
    ValorC = (AmigoC * 100)/ValorAmigo;

    printf("O valor que o amigo A recebera eh: R$%.2f", (Premio * ValorA/100));
    printf("\n");
    printf("O valor que o amigo B recebera eh: R$%.2f", (Premio * ValorB/100));
    printf("\n");
    printf("O valor que o amigo C recebera eh: R$%.2f", (Premio * ValorC/100));

}