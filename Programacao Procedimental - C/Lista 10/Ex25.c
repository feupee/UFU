#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[15];
    int dia_aniversario;
    int mes_aniversario;
} Contato;

void adicionar_contato(Contato *agenda, int *num_contatos) {
    Contato contato;

    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", contato.nome);

    printf("Digite o telefone do contato: ");
    scanf(" %[^\n]", contato.telefone);

    printf("Digite o dia de aniversário (1-31) do contato: ");
    scanf("%d", &contato.dia_aniversario);

    printf("Digite o mês de aniversário (1-12) do contato: ");
    scanf("%d", &contato.mes_aniversario);

    agenda[*num_contatos] = contato;
    (*num_contatos)++;

    printf("Contato adicionado com sucesso!\n");
}

void remover_contato(Contato *agenda, int *num_contatos) {
    char nome[50];
    int indice = -1;

    printf("Digite o nome do contato a ser removido: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < *num_contatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Contato não encontrado.\n");
    } else {
        for (int i = indice; i < *num_contatos - 1; i++) {
            agenda[i] = agenda[i + 1];
        }

        (*num_contatos)--;

        printf("Contato removido com sucesso!\n");
    }
}

void pesquisar_contato(const Contato *agenda, int num_contatos) {
    char nome[50];
    int encontrado = 0;

    printf("Digite o nome do contato a ser pesquisado: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < num_contatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Aniversário: %d/%d\n", agenda[i].dia_aniversario, agenda[i].mes_aniversario);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

void listar_contatos(const Contato *agenda, int num_contatos) {
    printf("Lista de Contatos:\n");

    for (int i = 0; i < num_contatos; i++) {
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("Aniversário: %d/%d\n", agenda[i].dia_aniversario, agenda[i].mes_aniversario);
        printf("---------------------------\n");
    }
}

void listar_contatos_por_letra(const Contato *agenda, int num_contatos) {
    char letra;

    printf("Digite a letra inicial dos contatos a serem listados: ");
    scanf(" %c", &letra);

    printf("Contatos cujo nome inicia com a letra %c:\n", letra);

    for (int i = 0; i < num_contatos; i++) {
        if (agenda[i].nome[0] == letra) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Aniversário: %d/%d\n", agenda[i].dia_aniversario, agenda[i].mes_aniversario);
            printf("---------------------------\n");
        }
    }
}

void imprimir_aniversariantes_mes(const Contato *agenda, int num_contatos) {
    int mes;

    printf("Digite o mês dos aniversariantes a serem listados: ");
    scanf("%d", &mes);

    printf("Aniversariantes do mês %d:\n", mes);

    for (int i = 0; i < num_contatos; i++) {
        if (agenda[i].mes_aniversario == mes) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Aniversário: %d/%d\n", agenda[i].dia_aniversario, agenda[i].mes_aniversario);
            printf("---------------------------\n");
        }
    }
}

void salvar_agenda(const Contato *agenda, int num_contatos) {
    FILE *arquivo = fopen("agenda.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fwrite(&num_contatos, sizeof(int), 1, arquivo);
    fwrite(agenda, sizeof(Contato), num_contatos, arquivo);

    fclose(arquivo);
}

void carregar_agenda(Contato *agenda, int *num_contatos) {
    FILE *arquivo = fopen("agenda.bin", "rb");

    if (arquivo == NULL) {
        printf("Arquivo de agenda não encontrado. Iniciando uma nova agenda.\n");
        return;
    }

    fread(num_contatos, sizeof(int), 1, arquivo);
    fread(agenda, sizeof(Contato), *num_contatos, arquivo);

    fclose(arquivo);
}

int main() {
    Contato agenda[100];
    int num_contatos = 0;

    carregar_agenda(agenda, &num_contatos);

    int opcao;

    do {
        printf("Selecione a opção:\n");
        printf("1. Inserir contato\n");
        printf("2. Remover contato\n");
        printf("3. Pesquisar contato pelo nome\n");
        printf("4. Listar todos os contatos\n");
        printf("5. Listar contatos por letra inicial\n");
        printf("6. Imprimir aniversariantes do mês\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_contato(agenda, &num_contatos);
                break;
            case 2:
                remover_contato(agenda, &num_contatos);
                break;
            case 3:
                pesquisar_contato(agenda, num_contatos);
                break;
            case 4:
                listar_contatos(agenda, num_contatos);
                break;
            case 5:
                listar_contatos_por_letra(agenda, num_contatos);
                break;
            case 6:
                imprimir_aniversariantes_mes(agenda, num_contatos);
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

    salvar_agenda(agenda, num_contatos);

    return 0;
}
/*Neste programa, os contatos são armazenados em um array de estruturas chamado agenda, com capacidade para até 100 contatos. A variável num_contatos mantém o controle do número atual de contatos na agenda.
As funções adicionar_contato, remover_contato, pesquisar_contato, listar_contatos, listar_contatos_por_letra e imprimir_aniversariantes_mes implementam as operações mencionadas, utilizando as estruturas de controle de repetição e condicional.
A função salvar_agenda recebe a agenda e o número de contatos como parâmetros e escreve os dados no arquivo binário "agenda.bin".
A função carregar_agenda lê os dados do arquivo binário "agenda.bin" e preenche a agenda e o número de contatos com esses dados.
No programa principal, a função carregar_agenda é chamada para carregar os contatos existentes no início do programa. Após cada operação na agenda, a função salvar_agenda é chamada para salvar os dados atualizados no arquivo binário.
O programa exibe um menu com as opções disponíveis para o usuário, e a operação correspondente é executada de acordo com a opção escolhida. O programa continua em execuç*/



