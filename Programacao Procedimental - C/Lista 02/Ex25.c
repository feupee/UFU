#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int a,b, c, x, x1, x2, delta;

    printf("formato inicial: ax2 + bx + c = 0");

    printf("\n");

    printf("Digite o valor de a(diferente de 0): ");
    scanf("%i", &a);

    if(a == 0){
        printf(" ERRO 'a' igual a 0");
        exit(0);
    }

    printf("\n");

    printf("Digite o valor de b: ");
    scanf("%i", &b);

     printf("\n");

    printf("Digite o valor de c: ");
    scanf("%i", &c);

     printf("\n");

    delta = pow(b, 2) - 4 * a * c;

    if(delta < 0) {
        printf("nao existe raiz");
        exit(0);
    }

    if(delta == 0) {
        printf("Raiz unica");

        x = -b/2*a;

        printf("X = %i", x);
    }

    if(delta > 0){
        x1 = (-b + delta)/2*a;
        x2 = (-b - delta)/2*a;

        printf("A raizes serao: x1=%i e x2=%i", x1, x2);
    }
    
  return 0;
}
