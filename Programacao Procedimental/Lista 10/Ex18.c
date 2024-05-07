#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa que leia um arquivo contendo o nome e o preço de
diversos produtos (separados por linha), e calcule o total da compra.*/

int main(){

    char prod[30];
    float qtd, valor, total = 0.0;
    FILE *f = fopen("compras.txt","r");
    if(f == NULL){
        printf("Erro na abertura");
        system("pause");
        exit(0);
    }

    while(!feof(f)){
        fscanf(f, "%s %f %f", prod, &qtd, &valor);
        total += qtd * valor;
    }

    printf("Total = %f\n", total);
    system("pause");

    return 0;
}