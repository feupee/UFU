//Exercicio B

#include <stdio.h>

int eleva(int X, int Y){
    
    int resultado = X;
    
    for(int i = 2; i <= Y; i++){
        resultado *= X;     
    }
    
    return resultado;
};

int main()
{
    int resultado, X, Y;
    
    printf("Digite valor de X: ");
    scanf("%d", &X);
    
    printf("Digite valor de Y: ");
    scanf("%d", &Y);
    
    resultado = eleva(X, Y);

    printf("%d elevado a %d eh: %d", X, Y, resultado);

    return 0;
}