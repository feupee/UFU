#include <stdio.h>
#include <stdlib.h>

/*Crie um programa que declare uma estrutura para o cadastro de alunos.
a) Dever ao ser armazenados, para cada aluno: matrícula, sobrenome
(apenas um), e ano de nascimento;
b) Ao início do programa, o usuário deverá informar o número de alunos
que serão armazenados;
c) O programa deverá alocar dinamicamente a quantidade necessária
de memória para armazenar os registros dos alunos;
d) O programa deverá pedir ao usuário que entre com as informações
dos alunos;
e) Em seguida, essas informações dever ˜ao ser gravadas em um
arquivo;
f) Ao final, mostrar os dados armazenados e liberar a memória alocada.
Ao iniciar o programa, forneça ao usuário uma opção para carregar os
registros do arquivo para a memória do computador alocando
dinamicamente a quantidade de memória necessária.
Dica: para que o usuário possa entrar com novos dados, além dos que
foram obtidos a partir do arquivo, use a função realloc() para realocar a
quantidade de memória usada.*/

typedef struct {
    int matricula;
    char sobrenome[50];
    int ano_nascimento;
} Aluno;

void cadastrar_aluno(Aluno **alunos, int *num_alunos) {
    (*num_alunos)++;

    *alunos = (Aluno*)realloc(*alunos, (*num_alunos) * sizeof(Aluno));

    Aluno novo_aluno;

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &novo_aluno.matricula);

    printf("Digite o sobrenome do aluno: ");
    scanf(" %[^\n]", novo_aluno.sobrenome);

    printf("Digite o ano de nascimento do aluno: ");
    scanf("%d", &novo_aluno.ano_nascimento);

    (*alunos)[(*num_alunos) - 1] = novo_aluno;

    printf("Aluno cadastrado com sucesso!\n");
}

void salvar_registros(Aluno *alunos, int num_alunos) {
    FILE *arquivo = fopen("alunos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%d\n", num_alunos);

    for (int i = 0; i < num_alunos; i++) {
        fprintf(arquivo, "%d %s %d\n", alunos[i].matricula, alunos[i].sobrenome, alunos[i].ano_nascimento);
    }

    fclose(arquivo);
}

void carregar_registros(Aluno **alunos, int *num_alunos) {
    FILE *arquivo = fopen("alunos.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de alunos não encontrado. Iniciando uma nova lista de alunos.\n");
        return;
    }

    fscanf(arquivo, "%d", num_alunos);

    *alunos = (Aluno*)realloc(*alunos, (*num_alunos) * sizeof(Aluno));

    for (int i = 0; i < *num_alunos; i++) {
        fscanf(arquivo, "%d %s %d", &(*alunos)[i].matricula, (*alunos)[i].sobrenome, &(*alunos)[i].ano_nascimento);
    }

    fclose(arquivo);
}

void mostrar_registros(const Aluno *alunos, int num_alunos) {
    printf("Registros de Alunos:\n");

    for (int i = 0; i < num_alunos; i++) {
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Sobrenome: %s\n", alunos[i].sobrenome);
        printf("Ano de Nascimento: %d\n", alunos[i].ano_nascimento);
        printf("---------------------------\n");
    }
}

void liberar_memoria(Aluno *alunos) {
    free(alunos);
}

int main() {
    Aluno *alunos = NULL;
    int num_alunos = 0;

    int opcao;

    printf("Deseja carregar os registros do arquivo? (1 - Sim, 0 - Não): ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        carregar_registros(&alunos, &num_alunos);
        mostrar_registros(alunos, num_alunos);
    }

    do {
        printf("Selecione a opção:\n");
        printf("1. Cadastrar aluno\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_aluno(&alunos, &num_alunos);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

        printf("\n");

    } while (opcao != 0);

    salvar_registros(alunos, num_alunos);
    mostrar_registros(alunos, num_alunos);
    liberar_memoria(alunos);

    return 0;
}