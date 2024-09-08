#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que leia a profissão e o tempo de serviço (em
anos) de cada um dos 5 funcionários de uma empresa e armazene-os no
arquivo “emp.txt”. Cada linha do arquivo corresponde aos dados de um
funcionário. Utilize o comando fprintf(). Em seguida, leia o mesmo
arquivo utilizando fscanf(). Apresente os dados na tela.*/

typedef struct {
    char profissao[50];
    int tempo_servico;
} Funcionario;

void escrever_arquivo(const char *nome_arquivo) {
    FILE *file = fopen(nome_arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    Funcionario funcionarios[5];
    for (int i = 0; i < 5; i++) {
        printf("Digite a profissão do funcionário %d: ", i + 1);
        scanf("%s", funcionarios[i].profissao);

        printf("Digite o tempo de serviço (em anos) do funcionário %d: ", i + 1);
        scanf("%d", &funcionarios[i].tempo_servico);

        fprintf(file, "%s %d\n", funcionarios[i].profissao, funcionarios[i].tempo_servico);
    }

    fclose(file);
}

void ler_arquivo(const char *nome_arquivo) {
    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Funcionario funcionarios[5];
    for (int i = 0; i < 5; i++) {
        fscanf(file, "%s %d", funcionarios[i].profissao, &funcionarios[i].tempo_servico);
    }

    fclose(file);

    printf("Dados dos funcionários:\n");
    for (int i = 0; i < 5; i++) {
        printf("Funcionário %d:\n", i + 1);
        printf("Profissão: %s\n", funcionarios[i].profissao);
        printf("Tempo de serviço: %d anos\n", funcionarios[i].tempo_servico);
        printf("\n");
    }
}

int main() {
    const char *nome_arquivo = "emp.txt";

    escrever_arquivo(nome_arquivo);
    ler_arquivo(nome_arquivo);

    return 0;
}