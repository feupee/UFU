#include "FuncHistograma.h"

void initializeHistogram(Histogram *hist) {
    memset(hist->count, 0, sizeof(hist->count));
}

void updateHistogram(Histogram *hist, const char *text) {
    int textLen = strlen(text);

    for (int i = 0; i < textLen; i++) {
        unsigned char currentChar = (unsigned char)text[i]; 
        hist->count[currentChar]++;
    }
}

void printHistogram(const Histogram *hist) {
    printf("Histograma de ocorrências de caracteres:\n");
    for (int i = 0; i < NUM_CHARS; i++) {
        if (hist->count[i] > 0) {
            printf("Caractere '%c' (ASCII %d): %d ocorrências\n", (char)i, i, hist->count[i]);
        }
    }
}