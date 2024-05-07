#include <stdio.h>
#include <stdlib.h>

int main() {

    int num, num1, num2, num3; 

    printf ("Digite um numero de tres digitos: "); 

    scanf ("%i", &num); 

    num1 = num%10;

    num = num/10;

	num2 = num%10;

	num = num/10;

	num3=num%10;

	num=num/10;

    printf ("\n\n"); 
    printf ("O seu numero invertido eh: %i%i%i", num1, num2, num3); 

}