//Exercicio C

#include <stdio.h>

//Função para calcular número exponencial

float eleva(int X, int Y){
    
    float resultado = X;
    
    for(int i = 2; i <= Y; i++){
        resultado *= X;     
    }
    
    return resultado;
};

//Função para calcular fatorial

float fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        float resultado = 1;
        for (int i = 2; i <= n; i++) {
            resultado *= i;
        }
        return resultado;
    }
}

int main()
{
    int X,Y;
    float resultado, aux1, aux2;
    
    printf("Digite valor para aproximacao: ");
    scanf("%d", &X);
    printf("Digite a quantidade de termos para aproximar: ");
    scanf("%d", &Y);

    resultado = 1 + X;
    
    for(int i = 2; i <= Y; i++){
        aux1 = eleva(X, i);
        aux2 = fatorial(i);

        resultado += aux1/aux2;
    }

    printf("Resultado: %f", resultado);

    return 0;
}