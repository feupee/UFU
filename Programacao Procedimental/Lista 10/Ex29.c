#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Codifique um programa que manipule um arquivo contendo registros
descritos pelos seguintes campos: codigo_vendedor, nome_vendedor,
valor_da_venda e mes. A manipulação do arquivo em questão é feita
através da execução das operações disponibilizadas pelo seguinte menu:
 Criar o arquivo de dados;
 Incluir um determinado registro no arquivo;
 Excluir um determinado vendedor no arquivo;
 Alterar o valor de uma venda no arquivo;
 Imprimir os registros na saída padrão;
 Excluir o arquivo de dados;
 Finalizar o programa.
Os registros devem estar ordenados no arquivo, de forma crescente, de
acordo com as Informações contidas nos campos código vendedor e mês.
Não deve existir mais de um registro no arquivo com mesmos valores nos
campos código vendedor e mês.*/

typedef struct {
    int codigo_vendedor;
    char nome_vendedor[30];
    float valor_da_venda;
    int mes;
} Registro;

void criar_arquivo() {
    FILE *arquivo = fopen("dados.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de dados.\n");
        return;
    }
    fclose(arquivo);
    printf("Arquivo de dados criado com sucesso.\n");
}

void incluir_registro() {
    Registro registro;
    FILE *arquivo = fopen("dados.bin", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de dados.\n");
        return;
    }

    printf("Digite o código do vendedor: ");
    scanf("%d", &registro.codigo_vendedor);

    printf("Digite o nome do vendedor: ");
    scanf("%s", registro.nome_vendedor);

    printf("Digite o valor da venda: ");
    scanf("%f", &registro.valor_da_venda);

    printf("Digite o mês: ");
    scanf("%d", &registro.mes);

    fwrite(&registro, sizeof(Registro), 1, arquivo);
    fclose(arquivo);
    printf("Registro incluído com sucesso.\n");
}

void excluir_registro() {
    int codigo_vendedor, mes;
    printf("Digite o código do vendedor a ser excluído: ");
    scanf("%d", &codigo_vendedor);
    printf("Digite o mês do registro a ser excluído: ");
    scanf("%d", &mes);

    FILE *arquivo = fopen("dados.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de dados não encontrado.\n");
        return;
    }

    FILE *arquivo_temp = fopen("temp.bin", "wb");
    if (arquivo_temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    Registro registro;
    int encontrado = 0;

    while (fread(&registro, sizeof(Registro), 1, arquivo) == 1) {
        if (registro.codigo_vendedor == codigo_vendedor && registro.mes == mes) {
            encontrado = 1;
        } else {
            fwrite(&registro, sizeof(Registro), 1, arquivo_temp);
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    remove("dados.bin");
    rename("temp.bin", "dados.bin");

    if (encontrado) {
        printf("Registro excluído com sucesso.\n");
    } else {
        printf("Registro não encontrado.\n");
    }
}

void alterar_valor_venda() {
    int codigo_vendedor, mes;
    printf("Digite o código do vendedor do registro a ser alterado: ");
    scanf("%d", &codigo_vendedor);
    printf("Digite o mês do registro a ser alterado: ");
    scanf("%d", &mes);

    FILE *arquivo = fopen("dados.bin", "rb+");
    if (arquivo == NULL) {
        printf("Arquivo de dados não encontrado.\n");
        return;
    }

    Registro registro;
    int encontrado = 0;

    while (fread(&registro, sizeof(Registro), 1, arquivo) == 1) {
        if (registro.codigo_vendedor == codigo_vendedor && registro.mes == mes) {
            printf("Digite o novo valor da venda: ");
            scanf("%f", &registro.valor_da_venda);
            fseek(arquivo, -sizeof(Registro), SEEK_CUR);
            fwrite(&registro, sizeof(Registro), 1, arquivo);
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (encontrado) {
        printf("Valor da venda alterado com sucesso.\n");
    } else {
        printf("Registro não encontrado.\n");
    }
}

void imprimir_registros() {
    FILE *arquivo = fopen("dados.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de dados não encontrado.\n");
        return;
    }

    Registro registro;

    while (fread(&registro, sizeof(Registro), 1, arquivo) == 1) {
        printf("Código do Vendedor: %d\n", registro.codigo_vendedor);
        printf("Nome do Vendedor: %s\n", registro.nome_vendedor);
        printf("Valor da Venda: %.2f\n", registro.valor_da_venda);
        printf("Mês: %d\n", registro.mes);
        printf("--------------------\n");
    }

    fclose(arquivo);
}

void excluir_arquivo() {
    if (remove("dados.bin") == 0) {
        printf("Arquivo de dados excluído com sucesso.\n");
    } else {
        printf("Erro ao excluir o arquivo de dados.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Criar arquivo de dados\n");
        printf("2. Incluir registro\n");
        printf("3. Excluir registro\n");
        printf("4. Alterar valor de uma venda\n");
        printf("5. Imprimir registros\n");
        printf("6. Excluir arquivo de dados\n");
        printf("7. Finalizar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criar_arquivo();
                break;
            case 2:
                incluir_registro();
                break;
            case 3:
                excluir_registro();
                break;
            case 4:
                alterar_valor_venda();
                break;
            case 5:
                imprimir_registros();
                break;
            case 6:
                excluir_arquivo();
                break;
            case 7:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

        printf("--------------------\n");
    } while (opcao != 7);

    return 0;
}