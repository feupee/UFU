#include <stdio.h>
#include <stdlib.h>

int main() {

    
    int Al, Ra, Pi, Vo;

    printf("Informe o valor da altura: ");
    scanf("%d", &Al);
    printf("Informe o valor do raio: ");
    scanf("%d", &Ra);

    Pi = 3.141592;

    Vo = Pi * (Ra*Ra) * Al;

    printf("\n");
    printf("O valor do volume eh:  %d", Vo);
    
    return(0);

}