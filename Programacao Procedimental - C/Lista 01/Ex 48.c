#include <stdio.h>
#include <stdlib.h>

int main() {

    float Se, Mi, Hr; 

    printf ("Digite um valor em segundos: "); 

    scanf ("%f", &Se); 

    Mi = Se / 60;
    Hr = Mi / 60;

    printf ("\n\n"); 
    printf ("O seu valor em horas eh: %f", Hr); 

}