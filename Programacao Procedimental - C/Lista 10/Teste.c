#include <stdio.h>

int main() {
    FILE *arquivo = fopen("matriz.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Encerra o programa com código de erro
    }
    
    int numeroLinha = 5; // Lê a linha de número 5
    char linha[256]; // Tamanho máximo da linha
    int contador = 1;
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (contador == numeroLinha) {
            printf("Linha %d: %s", contador, linha);
            break;
        }
        contador++;
    }
    
    fclose(arquivo);
    
    return 0;
}
