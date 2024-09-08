#ifndef COMPANHIA_AEREA_H
#define COMPANHIA_AEREA_H

typedef struct Aeroporto {
    char nome[50];
    char sigla[4];
    struct Aeroporto *prox;
} Aeroporto;

typedef struct Rota {
    char origem[4];
    char destino[4];
    float preco;
    struct Rota *prox;
} Rota;

Aeroporto* criarAeroporto(const char* nome, const char* sigla);
Rota* criarRota(const char* origem, const char* destino, float preco);

void adicionarAeroporto(Aeroporto** listaAeroportos, Aeroporto* aeroporto);
void adicionarRota(Rota** listaRotas, Rota* rota);

void mostrarRotasMaisBaratas(Rota* listaRotas);
void mostrarRotasMaisCaras(Rota* listaRotas);
float consultarPreco(Rota* listaRotas, const char* origem, const char* destino);

#endif