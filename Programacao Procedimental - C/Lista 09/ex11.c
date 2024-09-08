#include <stdio.h>
#include <stdlib.h>

/*Crie um programa que declare uma estrutura (registro) para o cadastro
de alunos.
a) Deverão ser armazenados, para cada aluno: matrícula, sobrenome
(apenas um) e ano de nascimento;
b) Ao início do programa, o usuário deverá informar o número de alunos
que serão armazenados;
c) O programa deverá alocar dinamicamente a quantidade necessária
de memória para armazenar os registros dos alunos;
d) O programa deverá pedir ao usuário que entre com as informações
dos alunos.
e) Ao final, mostrar os dados armazenados e liberar a memória alocada.*/

typedef struct alunos{
    char matricula[10];
    char sobrenome[25];
    int anoNascimento;
} alunos;

int main(){
    int n;
    alunos *aluno;

    printf("Insira a quantidade de alunos a adicionar: ");
    scanf("%d",&n);

    aluno = (alunos*)malloc(n * sizeof(alunos));
    for(int i = 0; i < n; i++){
        printf("\n");
        printf("Insira a matricula do aluno %d: ",i+1);
        setbuf(stdin, NULL);
        fgets(aluno[i].matricula,10,stdin);
        printf("Insira o sobrenome do aluno %d: ",i+1);
        setbuf(stdin, NULL);
        fgets(aluno[i].sobrenome,25,stdin);
        printf("Insira o ano de nascimento do aluno %d: ",i+1);
        scanf("%d",&aluno[i].anoNascimento);
    }

    for(int i = 0; i < n; i++){
        printf("\n");
        printf("Aluno %d:", i+1);
        printf("Matricula: %s",aluno[i].matricula);
        printf("Sobrenome: %s",aluno[i].sobrenome);
        printf("Ano de nascimento: %d\n",aluno[i].anoNascimento);
    }

    return 0;
}