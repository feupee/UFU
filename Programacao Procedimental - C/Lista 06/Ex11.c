#include <stdio.h>

typedef struct{
    char nome[50];
    char matricula[15];
    float media;
}dados;

int main(){

    int i, j = 0, l = 0;
    dados vetalunos[10], vetaprovados[10], vetreprovados[10];

    for(i = 0; i < 10; i++){
        printf("Digite o nome do aluno %i: ", i);
        setbuf(stdin, NULL);
        fgets(vetalunos[i].nome, 50, stdin);
        printf("Digite a matricula do aluno %i: ", i);
        setbuf(stdin, NULL);
        fgets(vetalunos[i].matricula, 50, stdin);
        printf("Digite a media do aluno %i: ", i);
        scanf("%f", &vetalunos[i].media);	
    }
    for(i = 0; i < 10; i++){
        if(vetalunos[i].media >= 5){
            vetaprovados[j] = vetalunos[i];
            j++;
        }
        if(vetalunos[i].media < 5){
            vetreprovados[l] = vetalunos[i];
            l++;
        }
    }

    printf("Aprovados -->");
    for(i = 0; i < j; i++){
        printf("\nAluno: %s", vetaprovados[i].nome);
        printf("Matricula: %s", vetaprovados[i].matricula);    
        printf("Media: %.2f\n", vetaprovados[i].media);
        
    }

    printf("\nReprovados -->");
    for(i = 0; i < l; i++){
        printf("\nAluno: %s", vetreprovados[i].nome);
        printf("Matricula: %s", vetreprovados[i].matricula);    
        printf("Media: %.2f\n", vetreprovados[i].media);
    }

    return 0;
}