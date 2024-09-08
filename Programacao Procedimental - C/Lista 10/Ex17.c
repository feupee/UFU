#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa que leia um arquivo que contenha as dimensões de
uma matriz (linha e coluna), a quantidade de posições que serão
anuladas, e as posições a serem anuladas (linha e coluna). O programa
lê esse arquivo e, em seguida, produz um novo arquivo com a matriz
com as dimensões dadas no arquivo lido, e todas as posições
especificadas no arquivo ZERADAS e o restante recebendo o valor 1.
*/

int main(){

    FILE *file = fopen("matriz.txt", "r");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivos\n");
        system("pause");
        exit(0);
    }
    FILE *file2 = fopen("saida_matriz.txt", "w");
    if(file2 == NULL){
        printf("Nao foi possivel abrir o arquivos\n");
        system("pause");
        exit(0);
    }
    int contador = 0;
    int linha, coluna, zerados;
    int linhaEx, colunaEx;
    char texto[100];

     
    if (contador == 0) {
        fscanf(file, "%d %d %d", &linha, &coluna, &zerados);
        if((linha * coluna) < zerados){
            printf("Valores invalidos para zerar\n");
            system("pause");
            exit(0);
        }
    }

    int matriz[linha][coluna];
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matriz[i][j] = 1;
        }
    }

    contador = 0;
    while (fgets(texto, sizeof(linha), file) != NULL){
        if(contador > 0){
            fscanf(file, "%d %d", &linhaEx, &colunaEx);
            matriz[linhaEx][colunaEx] = 0;
            printf("Linha: %d\nColuna: %d\n", linhaEx, colunaEx);
        }
        contador++;
    }
    fclose(file);
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            fprintf(file2, "%d ", matriz[i][j]);
            if(j == coluna-1){
                fprintf(file2, "\n");
            }
        }
    }
    fclose(file2);

    return 0;
}