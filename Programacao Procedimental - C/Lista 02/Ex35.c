#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int dia, mes, ano, anoatual = 2022;

    printf("Digite o dia: ");
    scanf("%i", &dia);
    
    if(dia < 0 || dia > 31){
        printf("Valor invalido");
        exit(0);
    }

    printf("Digite o mes: ");
    scanf("%i", &mes);
    
    if(mes < 0 || mes > 12){
        printf("Valor invalido");
        exit(0);
    }

    printf("Digite o ano (depois de cristo): ");
    scanf("%i", &ano);
    
    if(ano < 0 && ano < anoatual){
        printf("Valor invalido");
        exit(0);
    }

        switch(mes){

            case 1 :
            case 3 :
            case 5 :
            case 7 :
            case 8 :
            case 10 :
            case 12 :
                if (dia > 0 && dia <= 31){
                    printf("Essa data existe!");
                }
                else 
                    printf("Essa data nao existe!");
            break;

            case 2 :
                if(ano % 400 == 0){
                    if (dia > 0 && dia <= 29){
                        printf("Essa data existe!");
                    }
                    else 
                        printf("Essa data nao existe!");
                }
                if(ano % 400 != 0){
                    if (dia > 0 && dia <= 28){
                        printf("Essa data existe!");
                    }
                    else 
                        printf("Essa data nao existe!");
                }
            break;
            case 4 :
            case 6 :
            case 9 :
            case 11 :
                if (dia > 0 && dia <= 30){
                    printf("Essa data existe!");
                }
                else 
                    printf("Essa data nao existe!");
            break;

            
    }

  return 0;
}


