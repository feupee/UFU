#include <stdio.h>
#include <string.h>
#include "FuncHistograma.c"

int main() {
    char text[MAX_TEXT_SIZE];
    Histogram hist;

    initializeHistogram(&hist);

    printf("Digite o texto (máximo de %d caracteres):\n", MAX_TEXT_SIZE);
    fgets(text, sizeof(text), stdin);

    // Remova a quebra de linha do final da entrada
    text[strcspn(text, "\n")] = '\0';

    updateHistogram(&hist, text);

    printHistogram(&hist);

    return 0;
}