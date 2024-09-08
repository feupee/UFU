#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 100

/*Faça um programa para gerenciar as notas dos alunos de uma turma
salva em um arquivo. O programa deverá ter um menu contendo as
seguintes opções:
 Definir informações da turma;
 Inserir aluno e notas;
 Exibir alunos e médias;
 Exibir alunos aprovados;
 Exibir alunos reprovados;
 Salvar dados em Disco;
 Sair do programa (fim).
Faça a rotina que gerencia o menu dentro do main, e para cada uma das
opções deste menu, crie uma função específica.*/

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float media;
} Aluno;

typedef struct {
    int quantidade_alunos;
    Aluno alunos[MAX_ALUNOS];
} Turma;

void definir_informacoes_turma(Turma *turma) {
    printf("Digite a quantidade de alunos na turma: ");
    scanf("%d", &turma->quantidade_alunos);
}

void inserir_aluno_notas(Turma *turma) {
    if (turma->quantidade_alunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido.\n");
        return;
    }

    Aluno novo_aluno;

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", novo_aluno.nome);

    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &novo_aluno.nota1);

    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &novo_aluno.nota2);

    novo_aluno.media = (novo_aluno.nota1 + novo_aluno.nota2) / 2.0;

    turma->alunos[turma->quantidade_alunos] = novo_aluno;
    turma->quantidade_alunos++;

    printf("Aluno cadastrado com sucesso!\n");
}

void exibir_alunos_medias(const Turma *turma) {
    printf("Alunos e Médias:\n");

    for (int i = 0; i < turma->quantidade_alunos; i++) {
        printf("Nome: %s\n", turma->alunos[i].nome);
        printf("Média: %.2f\n", turma->alunos[i].media);
        printf("---------------------------\n");
    }
}

void exibir_alunos_aprovados(const Turma *turma) {
    printf("Alunos Aprovados:\n");

    for (int i = 0; i < turma->quantidade_alunos; i++) {
        if (turma->alunos[i].media >= 6.0) {
            printf("Nome: %s\n", turma->alunos[i].nome);
            printf("Média: %.2f\n", turma->alunos[i].media);
            printf("---------------------------\n");
        }
    }
}

void exibir_alunos_reprovados(const Turma *turma) {
    printf("Alunos Reprovados:\n");

    for (int i = 0; i < turma->quantidade_alunos; i++) {
        if (turma->alunos[i].media < 6.0) {
            printf("Nome: %s\n", turma->alunos[i].nome);
            printf("Média: %.2f\n", turma->alunos[i].media);
            printf("---------------------------\n");
        }
    }
}

void salvar_dados_em_disco(const Turma *turma) {
    FILE *arquivo = fopen("notas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%d\n", turma->quantidade_alunos);

    for (int i = 0; i < turma->quantidade_alunos; i++) {
        fprintf(arquivo, "%s %.2f %.2f\n", turma->alunos[i].nome, turma->alunos[i].nota1, turma->alunos[i].nota2);
    }

    fclose(arquivo);

    printf("Dados salvos com sucesso!\n");
}

void carregar_dados_do_disco(Turma *turma) {
    FILE *arquivo = fopen("notas.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de dados não encontrado.\n");
        return;
    }

    fscanf(arquivo, "%d\n", &turma->quantidade_alunos);

    for (int i = 0; i < turma->quantidade_alunos; i++) {
        fscanf(arquivo, "%s %f %f\n", turma->alunos[i].nome, &turma->alunos[i].nota1, &turma->alunos[i].nota2);
        turma->alunos[i].media = (turma->alunos[i].nota1 + turma->alunos[i].nota2) / 2.0;
    }

    fclose(arquivo);

    printf("Dados carregados com sucesso!\n");
}

int main() {
    Turma turma;
    int opcao;

    carregar_dados_do_disco(&turma);

    do {
        printf("\n");
        printf("Selecione uma opção:\n");
        printf("1. Definir informações da turma\n");
        printf("2. Inserir aluno e notas\n");
        printf("3. Exibir alunos e médias\n");
        printf("4. Exibir alunos aprovados\n");
        printf("5. Exibir alunos reprovados\n");
        printf("6. Salvar dados em disco\n");
        printf("0. Sair do programa\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                definir_informacoes_turma(&turma);
                break;
            case 2:
                inserir_aluno_notas(&turma);
                break;
            case 3:
                exibir_alunos_medias(&turma);
                break;
            case 4:
                exibir_alunos_aprovados(&turma);
                break;
            case 5:
                exibir_alunos_reprovados(&turma);
                break;
            case 6:
                salvar_dados_em_disco(&turma);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}