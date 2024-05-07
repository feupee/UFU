#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 41

/*Crie um programa que receba como entrada o número de alunos de uma
disciplina. Aloque dinamicamente em uma estrutura para armazenar as
informações a respeito desses alunos: nome do aluno e sua nota final.
Use nomes com no máximo 40 caracteres. Em seguida, salve os dados
dos alunos em um arquivo binário. Por fim, leia o arquivo e mostre o
nome do aluno com a maior nota.*/

typedef struct {
    char nome[MAX_NAME_LENGTH];
    float nota;
} Aluno;

void salvar_dados_alunos(int num_alunos, Aluno *alunos) {
    FILE *file = fopen("alunos.bin", "wb");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fwrite(alunos, sizeof(Aluno), num_alunos, file);

    fclose(file);
}

void encontrar_aluno_com_maior_nota(int num_alunos) {
    FILE *file = fopen("alunos.bin", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Aluno aluno_maior_nota;
    float maior_nota = -1.0;

    for (int i = 0; i < num_alunos; i++) {
        Aluno aluno;
        fread(&aluno, sizeof(Aluno), 1, file);

        if (aluno.nota > maior_nota) {
            maior_nota = aluno.nota;
            aluno_maior_nota = aluno;
        }
    }

    fclose(file);

    printf("Aluno com a maior nota:\n");
    printf("Nome: %s\n", aluno_maior_nota.nome);
    printf("Nota: %.2f\n", aluno_maior_nota.nota);
}

int main() {
    int num_alunos;

    printf("Digite o número de alunos: ");
    scanf("%d", &num_alunos);

    getchar();  // Limpar o buffer do teclado

    Aluno *alunos = (Aluno *)malloc(num_alunos * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < num_alunos; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, MAX_NAME_LENGTH, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';  // Remover o caractere de nova linha

        printf("Digite a nota final do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota);

        getchar();  // Limpar o buffer do teclado
    }

    salvar_dados_alunos(num_alunos, alunos);

    free(alunos);

    encontrar_aluno_com_maior_nota(num_alunos);

    return 0;
}