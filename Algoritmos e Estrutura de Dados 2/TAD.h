#include "arvore_binaria.h"
#include "lista_de_adjascencia.h"
#include <time.h>

// Define um tipo para representar o tempo decorrido em segundos
#define MAX_NOME 100
#define MAX_AREAS 6
typedef time_t Tempo;

int a,b,L,L2; // Declaração das váriaveis das setas
int co,L3,L4; // Novas declarações do menu

TipoApontador Aux;
long i;
short FimListaAdj;
int  NArestas;
TipoPeso Peso;
TipoValorVertice NVertices;

typedef struct {
    char nome[MAX_NOME];  // Nome do jogador
    double tempoTotal;       // Tempo total de jogo
    double tempoPorArea[MAX_AREAS]; // Tempo gasto em cada área
    int pontuacaoCentral; // Pontuação na Área Central
} Jogador;

void Iniciar_Game(Apontador *p, Jogador *jogador);

void percursoCentral(TipoValorVertice verticeA, TipoGrafo *Grafo, Jogador* jogador);
void percurso(TipoValorVertice verticeA, TipoGrafo *Grafo, Jogador* jogador);

