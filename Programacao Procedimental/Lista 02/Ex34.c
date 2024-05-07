#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int nota, faltas;

    printf("Digite as faltas do aluno: ");
    scanf("%i", &faltas);
    
    if(faltas < 0){
        printf("Valor invalido");
        exit(0);
    }

    printf("Digite a nota do aluno: ");
    scanf("%i", &nota);
    if(nota < 0 || nota > 10){
        printf("Valor invalido");
        exit(0);
    }

    if(nota >= 9 && nota <= 10 && faltas <= 20){
        printf("Aluno conceito: A ");
    }
    if(nota >= 7.5 && nota <= 8.9 && faltas <= 20){
        printf("Aluno conceito: B ");
    }
    if(nota >= 5 && nota <= 7.4 && faltas <= 20){
        printf("Aluno conceito: C ");
    }
    if(nota >= 4 && nota <= 4.9 && faltas <= 20){
        printf("Aluno conceito: D ");
    }
    if(nota >= 0 && nota <= 3.9 && faltas <= 20){
        printf("Aluno conceito: E ");
    }


    if(nota >= 9 && nota <= 10 && faltas > 20){
        printf("Aluno conceito: B ");
    }
    if(nota >= 7.5 && nota <= 8.9 && faltas > 20){
        printf("Aluno conceito: C ");
    }
    if(nota >= 5 && nota <= 7.4 && faltas > 20){
        printf("Aluno conceito: D ");
    }
    if(nota >= 4 && nota <= 4.9 && faltas > 20){
        printf("Aluno conceito: E ");
    }
    if(nota >= 0 && nota <= 3.9 && faltas > 20){
        printf("Aluno conceito: E ");
    }

    


  return 0;
}
