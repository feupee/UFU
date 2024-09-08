#include <stdio.h>
#include <stdlib.h>
#include "companhia_aerea.c"

int main() {
    Aeroporto* listaAeroportos = NULL;
    Rota* listaRotas = NULL;

    // Adicionar aeroportos
    Aeroporto* aeroporto1 = criarAeroporto("Aeroporto A", "AAA");
    Aeroporto* aeroporto2 = criarAeroporto("Aeroporto B", "BBB");
    Aeroporto* aeroporto3 = criarAeroporto("Aeroporto C", "CCC");
    adicionarAeroporto(&listaAeroportos, aeroporto1);
    adicionarAeroporto(&listaAeroportos, aeroporto2);
    adicionarAeroporto(&listaAeroportos, aeroporto3);

    // Adicionar rotas
    Rota* rota1 = criarRota("AAA", "BBB", 100.0);
    Rota* rota2 = criarRota("BBB", "CCC", 150.0);
    Rota* rota3 = criarRota("AAA", "CCC", 200.0);
    adicionarRota(&listaRotas, rota1);
    adicionarRota(&listaRotas, rota2);
    adicionarRota(&listaRotas, rota3);

    // Mostrar rota mais barata
    printf("Mostrando a rota mais barata:\n");
    mostrarRotasMaisBaratas(listaRotas);

    // Mostrar rota mais cara
    printf("\nMostrando a rota mais cara:\n");
    mostrarRotasMaisCaras(listaRotas);

    // Consultar preço de uma rota
    const char* origem = "AAA";
    const char* destino = "CCC";
    float preco = consultarPreco(listaRotas, origem, destino);

    if (preco >= 0) {
        printf("\nO preco da rota de %s para %s é %.2f\n", origem, destino, preco);
    } else {
        printf("\nRota nao encontrada.\n");
    }

    return 0;
}