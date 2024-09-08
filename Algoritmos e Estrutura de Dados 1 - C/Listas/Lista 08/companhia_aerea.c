#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "companhia_aerea.h"

Aeroporto* criarAeroporto(const char* nome, const char* sigla) {
    Aeroporto* novoAeroporto = (Aeroporto*)malloc(sizeof(Aeroporto));
    if (novoAeroporto != NULL) {
        strcpy(novoAeroporto->nome, nome);
        strcpy(novoAeroporto->sigla, sigla);
        novoAeroporto->prox = NULL;
    }
    return novoAeroporto;
}

Rota* criarRota(const char* origem, const char* destino, float preco) {
    Rota* novaRota = (Rota*)malloc(sizeof(Rota));
    if (novaRota != NULL) {
        strcpy(novaRota->origem, origem);
        strcpy(novaRota->destino, destino);
        novaRota->preco = preco;
        novaRota->prox = NULL;
    }
    return novaRota;
}

void adicionarAeroporto(Aeroporto** listaAeroportos, Aeroporto* aeroporto) {
    if (aeroporto != NULL) {
        aeroporto->prox = *listaAeroportos;
        *listaAeroportos = aeroporto;
    }
}

void adicionarRota(Rota** listaRotas, Rota* rota) {
    if (rota != NULL) {
        rota->prox = *listaRotas;
        *listaRotas = rota;
    }
}

void mostrarRotasMaisBaratas(Rota* listaRotas) {
    Rota* rotaMaisBarata = NULL;
    float precoMaisBarato = FLT_MAX; // Valor inicial muito alto

    Rota* atual = listaRotas;
    while (atual != NULL) {
        if (atual->preco < precoMaisBarato) {
            rotaMaisBarata = atual;
            precoMaisBarato = atual->preco;
        }
        atual = atual->prox;
    }

    if (rotaMaisBarata != NULL) {
        printf("Rota mais barata:\n");
        printf("Origem: %s\n", rotaMaisBarata->origem);
        printf("Destino: %s\n", rotaMaisBarata->destino);
        printf("Preco: %.2f\n", rotaMaisBarata->preco);
    } else {
        printf("Nao existe rotas disponíveis.\n");
    }
}

void mostrarRotasMaisCaras(Rota* listaRotas) {
    Rota* rotaMaisCara = NULL;
    float precoMaisCaro = 0;

    Rota* atual = listaRotas;
    while (atual != NULL) {
        if (atual->preco > precoMaisCaro) {
            rotaMaisCara = atual;
            precoMaisCaro = atual->preco;
        }
        atual = atual->prox;
    }

    if (rotaMaisCara != NULL) {
        printf("Rota mais cara:\n");
        printf("Origem: %s\n", rotaMaisCara->origem);
        printf("Destino: %s\n", rotaMaisCara->destino);
        printf("Preco: %.2f\n", rotaMaisCara->preco);
    } else {
        printf("Nao ha rotas disponíveis.\n");
    }
}

float consultarPreco(Rota* listaRotas, const char* origem, const char* destino) {
    Rota* atual = listaRotas;
    while (atual != NULL) {
        if (strcmp(atual->origem, origem) == 0 && strcmp(atual->destino, destino) == 0) {
            return atual->preco;
        }
        atual = atual->prox;
    }
    return -1.0; // Valor negativo indica que a rota não foi encontrada
}