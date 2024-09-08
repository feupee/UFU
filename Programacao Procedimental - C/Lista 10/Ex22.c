#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 41

/*Faça um programa que recebe como entrada o nome de um arquivo de
entrada e o nome de um arquivo de saída. O arquivo de entrada contém
o nome de um aluno ocupando 40 caracteres e três inteiros que indicam
suas notas. O programa deverá ler o arquivo de entrada e gerar um
arquivo de saída onde aparece o nome do aluno e as suas notas em
ordem crescente.*/

typedef struct {
    char nome[MAX_NAME_LENGTH];
    int notas[3];
} Aluno;

int comparar_notas(const void *a, const void *b) {
    const int *nota1 = (const int *)a;
    const int *nota2 = (const int *)b;
    return (*nota1 - *nota2);
}

void gerar_arquivo_saida(const char *arquivo_entrada, const char *arquivo_saida) {
    FILE *file_entrada = fopen(arquivo_entrada, "r");
    if (file_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return;
    }

    FILE *file_saida = fopen(arquivo_saida, "w");
    if (file_saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(file_entrada);
        return;
    }

    Aluno aluno;
    while (fread(&aluno, sizeof(Aluno), 1, file_entrada) == 1) {
        qsort(aluno.notas, 3, sizeof(int), comparar_notas);
        fprintf(file_saida, "%-40s %d %d %d\n", aluno.nome, aluno.notas[0], aluno.notas[1], aluno.notas[2]);
    }

    fclose(file_entrada);
    fclose(file_saida);
}

int main() {
    char arquivo_entrada[MAX_NAME_LENGTH];
    char arquivo_saida[MAX_NAME_LENGTH];

    printf("Digite o nome do arquivo de entrada: ");
    fgets(arquivo_entrada, sizeof(arquivo_entrada), stdin);
    arquivo_entrada[strcspn(arquivo_entrada, "\n")] = '\0'; // Remover o caractere de nova linha

    printf("Digite o nome do arquivo de saída: ");
    fgets(arquivo_saida, sizeof(arquivo_saida), stdin);
    arquivo_saida[strcspn(arquivo_saida, "\n")] = '\0'; // Remover o caractere de nova linha

    gerar_arquivo_saida(arquivo_entrada, arquivo_saida);

    return 0;
}