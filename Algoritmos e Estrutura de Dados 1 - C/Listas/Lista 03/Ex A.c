//Exercício A

#include <stdio.h>

int recebe(int N){
    int soma = 0;
    
    for(int i = 1; i <= N; i++){
        soma += i;
    }
    return soma;
}

int main()
{
    
    int N;
    
    int resultado;
    
    printf("Digite N: ");
    scanf("%d", &N);
    
    resultado = recebe(N);
    
    printf("Resultado: %d", resultado);
    return 0;
}