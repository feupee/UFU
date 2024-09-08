#include <stdio.h>

    struct aluno{
        char nome[50];
        char matricula[10];
        char curso[50];
    };

int main(){

    int i;
    struct aluno c[5];
    

    for(i = 0; i < 5; i++){
        
        
        printf("\nDigite o nome do aluno %i: ", (i+1));
        fflush(stdin);
        fgets(c[i].nome, 50, stdin);

        printf("Digite a matricula: ");
        fflush(stdin);
        fgets(c[i].matricula, 10, stdin);
    
        printf("Digite o curso do aluno: %i: ", (i+1));
        fflush(stdin);
        fgets(c[i].curso, 50, stdin);
         

    }

    for(i = 0; i < 5; i++){

        printf("\nAluno %i\n", (i+1));
        printf(" O nome: %s\n A matricula: %s\n O curso: %s\n", c[i].nome, c[i].matricula, c[i].curso);

        }
    return 0;
}