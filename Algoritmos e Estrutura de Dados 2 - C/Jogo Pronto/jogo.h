//---------------------------------------------
// Seção de inlcudes:
#include <time.h>
#define MAXNUMVERTICES 100
#define MAXNUMARESTAS 4500
#define FALSE 0
#define TRUE 1
#define MAX_NOME 100
#define MAX_NOME 100
#define MAX_AREAS 6

//---------------------------------------------
// Seção de Structs e Typedefs:

// GRAFO:
typedef time_t Tempo;

typedef int TipoValorVertice;
typedef int TipoPeso;

typedef struct TipoItem {
  TipoValorVertice Vertice;
  TipoPeso peso;
} TipoItem;

typedef struct TipoCelula {
  TipoItem Item;
  struct TipoCelula *Prox;
} TipoCelula;
typedef TipoCelula *TipoApontador;

typedef struct TipoLista {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

typedef struct TipoGrafo {
  TipoLista Adj[MAXNUMVERTICES];
  int NumVertices;
  int NumArestas;
} TipoGrafo;

typedef struct {
  char nome[MAX_NOME]; // Nome do jogador
  double tempoTotal;   // Tempo total de jogo
  double tempoPorArea[MAX_AREAS];  // Tempo gasto em cada área
  double tempoAreaCentral;
  int pontuacaoCentral;    // Pontuação na Área Central
} Jogador;
//

// ABB:
typedef struct info {
  TipoGrafo grafo;
} Info;

typedef Info TipoChave;

typedef struct registro {
  TipoChave Chave;
  /*outros componentes */
} Registro;

typedef struct No {
  Registro Reg;
  struct No *Esq;
  struct No *Dir;
} No;
typedef No *Apontador;
typedef Apontador *TipoDicionario;
//

//---------------------------------------------
// Seção de funções ABB:
void Retira_binaria(Registro x, Apontador *p);
void Antecessor_binaria(Apontador q, Apontador *r);
void Insere_binaria(Registro x, Apontador *p);
void Inicializa_binaria(Apontador *Dicionario);
int Vazio_binaria(Apontador *Dicionario);
//---------------------------------------------
// Seção de funções GRAFO:
void FLVazia(TipoLista *Lista);
short Vazia(TipoLista Lista);
void Insere(TipoItem *x, TipoLista *Lista);
void FGVazio(TipoGrafo *Grafo);
void InsereAresta(TipoValorVertice V1, TipoValorVertice V2, TipoPeso peso,
                  TipoGrafo *Grafo);
short ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2,
                   TipoGrafo *Grafo);
short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo);
TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo);
void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj,
             TipoPeso *Peso, TipoApontador *Prox, short *FimListaAdj);
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item);
void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso,
                  TipoGrafo *Grafo);
void LiberaGrafo(TipoGrafo *Grafo);
void ImprimeGrafo(TipoGrafo *Grafo);
void ImprimeLista(TipoLista Lista);
TipoGrafo LerGrafoDoArquivo(const char *nomeArquivo);
//---------------------------------------------
// Seção de funções DIVERSAS:
void criar_jogador(Jogador *jogador, char *nomeJogador);
Jogador chamaDadosJogador(char *nomeBusca);
void Iniciar_Game(No **p, Jogador *jogador);
void percursoCentral(TipoValorVertice verticeA, TipoGrafo *Grafo,
                     Jogador *jogador);
void percurso(TipoValorVertice verticeA, TipoGrafo *Grafo, Jogador *jogador);
void como_jogar();
void MostraDadosJogador(Jogador *jogador);
void criar_jogador(Jogador *jogador, char *nomeJogador);
//---------------------------------------------
// Seção de funções Ranking:
void InicializaRanking();
void adicionarJogador(Jogador novoJogador);
void ordenarRanking_TempoTotal();
void ordenarRanking_PontuacaoCentral();
void mostrarRanking();
void adicionarJogador_Arquivo(const Jogador novoJogador);