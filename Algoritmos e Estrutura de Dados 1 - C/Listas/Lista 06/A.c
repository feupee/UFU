#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "A.h"

struct String *criarString(){
    struct String *str = (struct String*)malloc(sizeof(struct String));
    if(str != NULL){
        str->length = 0;
        str->data = NULL;
        return str;
    } else{
        printf("Não foi possível alocar");
        exit(0);
    }
}
void AssociarString(struct String *str, const char *valor){
    if (str->data != NULL) {
        memset(str->data, 0, str->length);
        free(str->data);
    }else{
    str->length = strlen(valor);
    str->data = (char*)malloc((str->length + 1) * sizeof(char)); // +1 para o caractere nulo '\0'
    strcpy(str->data, valor);
    }
}
void RetornarTamanho(struct String *str) {
    if (str && str->length) {
        printf("Tamanho: %d\n", str->length);
    }
}
void ContagemOcorrencia(struct String *str, const char caracter) {
    int i, count = 0;

    for (i = 0; i < str->length; i++) {
        if (str->data[i] == caracter) {
            count++;
        }
    }

    printf("Contagem: %d\n", count);
}
void ExibirString(struct String *str){
    if (str && str->data) {
        printf("String: %s\n", str->data);
    }
}

int main() {
    int escolha;
    char caracter, AuxString[100];
    struct String* minhaString = NULL; 

    do {
        printf("O que deseja fazer?\n\n1 - Criar String\n2 - Associar Valor para String\n3 - Mostrar tamanho da string\n4 - Mostrar quantidade de ocorrencias\n5 - Exibir String\n6 - Sair\n\nResposta: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (minhaString == NULL) { // Verifique se já não está alocada
                    minhaString = criarString();
                } else {
                    printf("Uma string já foi criada.\n");
                }
                break;
            case 2:
                if (minhaString != NULL) {
                    fflush(stdin);
                    printf("Digite o valor: ");
                    fgets(AuxString, 100, stdin);
                    AssociarString(minhaString, AuxString);
                } else {
                    printf("Nenhuma string criada ainda.\n");
                }
                break;
            case 3:
                if (minhaString != NULL) {
                    RetornarTamanho(minhaString);
                } else {
                    printf("Nenhuma string criada ainda.\n");
                }
                break;
            case 4:
                if (minhaString != NULL) {
                    printf("Digite o caracter: ");
                    scanf(" %c", &caracter);
                    ContagemOcorrencia(minhaString, caracter);
                } else {
                    printf("Nenhuma string criada ainda.\n");
                }
                break;
            case 5:
                if (minhaString != NULL) {
                    ExibirString(minhaString);
                } else {
                    printf("Nenhuma string criada ainda.\n");
                }
                break;
        }
    } while (escolha != 6);

    // Libere a memória alocada para minhaString antes de sair
    if (minhaString != NULL) {
        memset(minhaString->data, 0, minhaString->length);
        free(minhaString->data);
        free(minhaString);
    }

    return 0;
}