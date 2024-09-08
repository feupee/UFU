#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 41

/*Crie um programa que receba como entrada o número de alunos de uma
disciplina. Aloque dinamicamente dois vetores para armazenar as
informações a respeito desses alunos. O primeiro vetor contém o nome
dos alunos e o segundo contém suas notas finais. Crie um arquivo que
armazene, a cada linha, o nome do aluno e sua nota final. Use nomes
com no máximo 40 caracteres. Se o nome não contém 40 caracteres,
complete com espaço em branco*/

void criar_arquivo_alunos(int num_alunos, char **nomes, float *notas) {
    FILE *file = fopen("alunos.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    for (int i = 0; i < num_alunos; i++) {
        char nome_completo[MAX_NAME_LENGTH];
        strncpy(nome_completo, nomes[i], MAX_NAME_LENGTH - 1);
        nome_completo[MAX_NAME_LENGTH - 1] = '\0';  // Garante que o nome termina com '\0'

        fprintf(file, "%-40s %.2f\n", nome_completo, notas[i]);
    }

    fclose(file);
}

int main() {
    int num_alunos;

    printf("Digite o número de alunos: ");
    scanf("%d", &num_alunos);

    getchar();  // Limpar o buffer do teclado

    char **nomes = (char **)malloc(num_alunos * sizeof(char *));
    float *notas = (float *)malloc(num_alunos * sizeof(float));

    if (nomes == NULL || notas == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < num_alunos; i++) {
        nomes[i] = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
        if (nomes[i] == NULL) {
            printf("Erro na alocação de memória.\n");
            return 1;
        }

        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(nomes[i], MAX_NAME_LENGTH, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';  // Remover o caractere de nova linha

        printf("Digite a nota final do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);

        getchar();  // Limpar o buffer do teclado
    }

    criar_arquivo_alunos(num_alunos, nomes, notas);

    for (int i = 0; i < num_alunos; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(notas);

    return 0;
}