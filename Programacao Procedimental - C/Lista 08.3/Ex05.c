#include <stdio.h>

/*Escreva uma função que dado um número real passado como parâmetro,
retorne a parte inteira e a parte fracionária deste número. Escreva um
programa que chama esta função.
*/

void frac(float real, int *inteiro, float *fracao){
    *inteiro = real;
    *fracao = real - *inteiro;
}

int main()
{
    float real, fracao;
    int inteiro; 
    
    printf("Digite o valor real: ");
    scanf("%f", &real);

    printf("Valor real: %f", real);

    frac(real, &inteiro, &fracao);

    printf("\nValor inteiro: %d", inteiro);
    printf("\nValor fracionario:  %f\n", fracao);
    

    return 0;
}
