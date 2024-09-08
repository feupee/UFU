#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100

/*Faça um programa que receba do usuário um arquivo que contenha o
nome e a nota de diversos alunos (da seguinte forma: NOME: JOÃO
NOTA: 8), um aluno por linha. Mostre na tela o nome e a nota do aluno
que possui a maior nota.*/

void encontrar_aluno_com_maior_nota(const char* arquivo) {
    float maior_nota = -INFINITY;
    char aluno_maior_nota[MAX_LENGTH];
    char nome[MAX_LENGTH];
    float nota;

    FILE* file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fgets(nome, sizeof(nome), file) != NULL) {
        fgets(nome, sizeof(nome), file);
        fgets(nome, sizeof(nome), file);

        sscanf(nome, "NOME: %[^\n]", aluno_maior_nota);
        fscanf(file, "NOTA: %f", &nota);

        if (nota > maior_nota) {
            maior_nota = nota;
        }
    }

    fclose(file);

    printf("Aluno com a maior nota:\n");
    printf("Nome: %s\n", aluno_maior_nota);
    printf("Nota: %.2f\n", maior_nota);
}

int main() {
    char arquivo[MAX_LENGTH];

    printf("Digite o nome do arquivo: ");
    fgets(arquivo, sizeof(arquivo), stdin);
    arquivo[strcspn(arquivo, "\n")] = '\0'; // Remove o caractere de nova linha

    encontrar_aluno_com_maior_nota(arquivo);

    return 0;
}