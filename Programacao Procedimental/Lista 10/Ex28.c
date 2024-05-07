#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 30

/*Faça um programa que recebe como entrada o nome de um arquivo de
entrada e o nome de um arquivo de saída. Cada linha do arquivo de
entrada possui colunas de tamanho de 30 caracteres. No arquivo de
saída deverá ser escrito o arquivo de entrada de forma inversa. Veja um
exemplo:
Arquivo de entrada:
Hoje eh dia de prova de PP
A prova esta muito facil
Vou tirar uma boa nota
Arquivo de saida:
Aton aob amu rarit uov
Licaf otium atse avorp A
PP ed avorp ed aid he ejoH*/

void inverter_string(char *str) {
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char nome_arquivo_entrada[50];
    char nome_arquivo_saida[50];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nome_arquivo_entrada);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nome_arquivo_saida);

    FILE *arquivo_entrada = fopen(nome_arquivo_entrada, "r");
    FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");

    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    char linha[MAX_CHAR + 1];

    while (fgets(linha, sizeof(linha), arquivo_entrada) != NULL) {
        inverter_string(linha);
        fprintf(arquivo_saida, "%s", linha);
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Arquivo de saída gerado com sucesso.\n");

    return 0;
}