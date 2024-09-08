#include <stdio.h>
#include <string.h>
#include <ctype.h>

void analisarTexto(char texto[], char caracteres_unicos[], int contagem_caracteres[], int *num_caracteres_unicos) {
    *num_caracteres_unicos = 0;

    for (int i = 0; i < strlen(texto); i++) {
        if (!isalpha(texto[i])) {
            continue; // Ignorar caracteres não alfabéticos
        }
        
        char char_lower = tolower(texto[i]);

        int found = 0;
        for (int j = 0; j < *num_caracteres_unicos; j++) {
            if (caracteres_unicos[j] == char_lower) {
                contagem_caracteres[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            caracteres_unicos[*num_caracteres_unicos] = char_lower;
            contagem_caracteres[*num_caracteres_unicos] = 1;
            (*num_caracteres_unicos)++;
        }
    }
}

int main() {
    char texto[401]; // Para acomodar até 400 caracteres + '\0'
    printf("Digite um texto de até 400 caracteres: ");
    fgets(texto, sizeof(texto), stdin);

    int num_caracteres_unicos;
    char caracteres_unicos[400]; // Para armazenar caracteres únicos
    int contagem_caracteres[400]; // Para armazenar contagens correspondentes

    analisarTexto(texto, caracteres_unicos, contagem_caracteres, &num_caracteres_unicos);

    printf("\nCaracteres unicos no texto:\n");
    for (int i = 0; i < num_caracteres_unicos; i++) {
        printf("%c ", caracteres_unicos[i]);
    }

    printf("\nQuantidade de vezes que cada caractere aparece:\n");
    for (int i = 0; i < num_caracteres_unicos; i++) {
        printf("%d ", contagem_caracteres[i]);
    }

    return 0;
}