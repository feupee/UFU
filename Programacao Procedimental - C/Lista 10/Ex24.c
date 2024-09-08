#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*.Implemente um controle simples de mercadorias em uma despensa
doméstica. Para cada produto armazene um código numérico, descrição
e quantidade atual. O programa deve ter opções para entrada e retirada
de produtos, bem como um relatório geral e um de produtos não
disponíveis. Armazene os dados em arquivo binário.
*/

typedef struct {
    int codigo;
    char descricao[50];
    int quantidade;
} Mercadoria;

void adicionar_mercadoria(FILE *file) {
    Mercadoria mercadoria;

    printf("Digite o código da mercadoria: ");
    scanf("%d", &mercadoria.codigo);

    printf("Digite a descrição da mercadoria: ");
    scanf(" %[^\n]", mercadoria.descricao);

    printf("Digite a quantidade da mercadoria: ");
    scanf("%d", &mercadoria.quantidade);

    fwrite(&mercadoria, sizeof(Mercadoria), 1, file);

    printf("Mercadoria adicionada com sucesso!\n");
}

void retirar_mercadoria(FILE *file) {
    int codigo;

    printf("Digite o código da mercadoria a ser retirada: ");
    scanf("%d", &codigo);

    Mercadoria mercadoria;
    int encontrada = 0;

    while (fread(&mercadoria, sizeof(Mercadoria), 1, file) == 1) {
        if (mercadoria.codigo == codigo) {
            encontrada = 1;

            int quantidade_retirada;

            printf("Digite a quantidade a ser retirada: ");
            scanf("%d", &quantidade_retirada);

            if (quantidade_retirada > mercadoria.quantidade) {
                printf("Quantidade insuficiente.\n");
            } else {
                mercadoria.quantidade -= quantidade_retirada;
                fseek(file, -sizeof(Mercadoria), SEEK_CUR);
                fwrite(&mercadoria, sizeof(Mercadoria), 1, file);
                printf("Mercadoria retirada com sucesso!\n");
            }

            break;
        }
    }

    if (!encontrada) {
        printf("Mercadoria não encontrada.\n");
    }
}

void relatorio_geral(FILE *file) {
    Mercadoria mercadoria;

    printf("Relatório Geral:\n");

    while (fread(&mercadoria, sizeof(Mercadoria), 1, file) == 1) {
        printf("Código: %d\n", mercadoria.codigo);
        printf("Descrição: %s\n", mercadoria.descricao);
        printf("Quantidade: %d\n", mercadoria.quantidade);
        printf("---------------------------\n");
    }
}

void relatorio_indisponiveis(FILE *file) {
    Mercadoria mercadoria;

    printf("Relatório de Produtos Indisponíveis:\n");

    while (fread(&mercadoria, sizeof(Mercadoria), 1, file) == 1) {
        if (mercadoria.quantidade == 0) {
            printf("Código: %d\n", mercadoria.codigo);
            printf("Descrição: %s\n", mercadoria.descricao);
            printf("---------------------------\n");
        }
    }
}

int main() {
    FILE *file = fopen("despensa.bin", "rb+");
    if (file == NULL) {
        file = fopen("despensa.bin", "wb+");
        if (file == NULL) {
            printf("Erro ao criar o arquivo.\n");
            return 1;
        }
    }

    int opcao;

    do {
        printf("Selecione a opção:\n");
        printf("1. Adicionar mercadoria\n");
        printf("2. Retirar mercadoria\n");
        printf("3. Relatório Geral\n");
        printf("4. Relatório de Produtos Indisponíveis\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_mercadoria(file);
                break;
            case 2:
                retirar_mercadoria(file);
                break;
            case 3:
                relatorio_geral(file);
                break;
            case 4:
                relatorio_indisponiveis(file);
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

    fclose(file);

    return 0;
}
