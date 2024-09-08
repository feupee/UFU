#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa para associar nomes as linhas de uma matriz de
caracteres. O usuário irá informar o número máximo de nomes que
poderão ser armazenados. Cada nome poderá ter até 30 caracteres com
o '\0'. O usuário poderá usar 5 opções diferentes para manipular a
matriz:
a) Gravar um nome em uma linha da matriz;
b) Apagar o nome contido em uma linha da matriz;
c) Informar um nome, procurar a linha onde ele se encontra e substituir
por outro nome;
d) Informar um nome, procurar a linha onde ele se encontra e apagar;
e) Pedir para recuperar o nome contido em uma linha da matriz.*/

char printfMenu();
void operacoes(char op, char **matriz, int nMax);
void opA(char **matriz, int nMax);
void opB(char **matriz, int nMax);
void opC(char **matriz, int nMax);
void opD(char **matriz, int nMax);
void opE(char **matriz, int nMax);

int main(){
    int nMax, i;
    char **matriz, op;

    printf("Insira o numero maximo de nomes: ");
    scanf("%d",&nMax);

    if((matriz = (char**)calloc(nMax, sizeof(char*))) == NULL){
        printf("Error: Out of memory");
        exit(1);
    }
    for(i = 0; i < nMax; i++){
        if((matriz[i] = (char*)calloc(30, sizeof(char))) == NULL){
            printf("Error: Out of memory");
            exit(1);
        }
    }

    do{
        do{
            op = printfMenu();
            if((op < 'a' || op > 'e') && (op != 'x')){
                printf("Operacao invalida, escolha outra\n");
                system("pause");
                system("cls");
            }
            if(op == 'x' || op == 'X') break;
        }while((op < 'a' || op > 'e') && (op != 'x' || op != 'X'));
        
        if(op == 'x' || op == 'X') break;
        operacoes(op, matriz, nMax);
        
    }while(op != 'x' || op != 'X');

    return 0;
}

char printfMenu(){
    char op;
    printf("\nEscolha uma opcao:\n");
    printf("'a' - Gravar um nome em uma linha da matriz\n");
    printf("'b' - Apagar o nome contido em uma linha da matriz\n");
    printf("'c' - Informar um nome, procurar a linha onde ele se encontra e substituir por outro nome\n");
    printf("'d' - Informar um nome, procurar a linha onde ele se encontra e apagar\n");
    printf("'e' - Pedir para recuperar o nome contido em uma linha da matriz\n");
    printf("'x' - Encerrar programa\n");
    printf("Insira a operacao: ");
    setbuf(stdin, NULL);
    scanf("%c", &op);
    return op;
}

void operacoes(char op, char **matriz, int nMax){
    switch(op){
        case 'a':
            opA(matriz, nMax);
            break;
        case 'b':
            opB(matriz, nMax);
            break;
        case 'c':
            opC(matriz, nMax);
            break;
        case 'd':
            opD(matriz, nMax);
            break;
        case 'e':
            opE(matriz, nMax);
            break;
    }
}

void opA(char **matriz, int nMax){
    int linha, i;
    printf("Insira a linha a inserir: ");
    scanf("%d", &linha);
    if(linha >= nMax || linha < 0){
        printf("Linha invalida\n");
    }else{
        for(i = 0; matriz[linha][i] == 0; i++);
        if(i >= 29){
            printf("Insira o nome: ");
            setbuf(stdin, NULL);
            fgets(matriz[linha], 30, stdin);
    }else{
        printf("Linha ja preenchida\n");
    }
    }
}

void opB(char **matriz, int nMax){
    int linha, i;
    printf("Insira a linha a apagar: ");
    scanf("%d", &linha);
    if(linha >= nMax || linha < 0){
        printf("Linha invalida\n");
    }else{
        for(i = 0; i < 30 ; i++){
            matriz[linha][i] = 0;
        }
    }
}

void opC(char **matriz, int nMax){
    char nomeTemp[30], nomeTrocar[30];
    int i = 0;
    printf("Insira um nome a buscar: ");
    setbuf(stdin, NULL);
    fgets(nomeTemp, 30, stdin);
    for(i = 0; i < nMax; i++){
        if(strcmp(nomeTemp, matriz[i]) == 0){
            printf("Insira um nome para substituir: ");
            setbuf(stdin, NULL);
            fgets(nomeTrocar, 30, stdin);
            strcpy(matriz[i], nomeTrocar);
            break;
        }
    }
    if(i == nMax){
        nomeTemp[strlen(nomeTemp) - 1] = '\0';
        printf("%s nao encontrado: \n", nomeTemp);
    }
}

void opD(char **matriz, int nMax){
    char nomeTemp[30];
    int i = 0, j = 0;
    printf("Insira um nome a buscar: ");
    setbuf(stdin, NULL);
    fgets(nomeTemp, 30, stdin);
    for(i = 0; i < nMax; i++){
        if(strcmp(nomeTemp, matriz[i]) == 0){
            for(j = 0; j < 30; j++){
                matriz[i][j] = 0;
            }
            break;
        }
    }
    if(i == nMax){
        nomeTemp[strlen(nomeTemp) - 1] = '\0';
        printf("%s nao encontrado: \n", nomeTemp);
    }
}

void opE(char **matriz, int nMax){
    int linha;
    printf("Insira a linha a imprimir: ");
    scanf("%d", &linha);
    if(linha >= nMax || linha < 0){
        printf("Linha invalida\n");
    }else if(matriz[linha][0] != 0){
        printf("Linha %d = %s", linha, matriz[linha]);
    }else{  
        printf("Linha vazia\n");
    }
}