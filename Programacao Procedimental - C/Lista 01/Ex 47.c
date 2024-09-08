#include <stdio.h>
#include <stdlib.h>

int main() {

    int num, num1, num2, num3, num4; 

    printf ("Digite um numero de quatro digitos: "); 

    scanf ("%i", &num); 

    num1 = (num / 1000);

    num2 = (num % 1000)/100;

    num3 = (num % 100)/10;

    num4 = (num % 10);

    printf ("\n\n"); 
    printf ("O seu numero invertido eh: %i", num1); 

    printf ("\n\n"); 
    printf ("O seu numero invertido eh: %i", num2); 

    printf ("\n\n"); 
    printf ("O seu numero invertido eh: %i", num3);

    printf ("\n\n"); 
    printf ("O seu numero invertido eh: %i", num4);

}