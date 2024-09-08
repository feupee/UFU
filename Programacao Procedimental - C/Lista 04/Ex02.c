#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int ano, mes, dia;

    printf("Digite o ano: ");
    scanf("%i", &ano);

    printf("Digite o mes: ");
    scanf("%i", &mes);

    printf("Digite o dia: ");
    scanf("%i", &dia);

    int verificador();
        verificador(dia, mes, ano);

    void transformarMes();
        transformarMes(dia, mes, ano);

    

    return 0;
}

int verificador(int dia,int mes,int ano){

    if (ano < 0){
        printf("Ano invalido");
        exit(0);
    }
    else if(mes < 0 || mes > 12){
        printf("Mes invalido");
        exit(0);
    }
    else if(dia > 31 || dia < 0){
        printf("Dia invalido");
        exit(0);
    }

}

void transformarMes(int dia,int mes,int ano){

    switch(mes){
        case 1 : 
        printf("%i de Janeiro de %i", dia, ano);
        break;
        case 2 : 
        if(ano % 400 == 0){
            if(dia > 29){
                printf("Dia invalido");
                exit(0);
            }
        } 
        else 
            if(ano % 400 != 0){
                if(dia > 29){
                    printf("Dia invalido");
                    exit(0);
                }
            } 
        printf("%i de Fevereiro de %i", dia, ano);
        break;
        case 3 : 
        printf("%i de Marco de %i", dia, ano);
        break;
        case 4 : 
        printf("%i de Abril de %i", dia, ano);
        break;
        case 5 : 
        printf("%i de Maio de %i", dia, ano);
        break;
        case 6 : 
        printf("%i de Junho de %i", dia, ano);
        break;
        case 7 : 
        printf("%i de Julho de %i", dia, ano);
        break;
        case 8 : 
        printf("%i de Agosto de %i", dia, ano);
        break;
        case 9 : 
        printf("%i de Setembro de %i", dia, ano);
        break;
        case 10 : 
        printf("%i de Outubro de %i", dia, ano);
        break;
        case 11 : 
        printf("%i de Novembro de %i", dia, ano);
        break;
        case 12 : 
        printf("%i de Dezembro de %i", dia, ano);
        break;
    }
}
