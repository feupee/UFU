//---------------------------------------------
// Seção de inlcudes:
#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//---------------------------------------------
// Seção de funções ABB:

void Antecessor_binaria(Apontador q, Apontador *r) {
  if ((*r)->Dir != NULL) {
    Antecessor_binaria(q, &(*r)->Dir);
    return;
  }
  q->Reg = (*r)->Reg;
  q = *r;
  *r = (*r)->Esq;
  free(q);
}

void Insere_binaria(Registro x, Apontador *p) {
  if (*p == NULL) {
    *p = (Apontador)malloc(sizeof(No));
    (*p)->Reg = x;
    (*p)->Esq = NULL;
    (*p)->Dir = NULL;
    return;
  }

  if (x.Chave.grafo.NumVertices < (*p)->Reg.Chave.grafo.NumVertices) {
    Insere_binaria(x, &(*p)->Esq);
    return;
  }
  if (x.Chave.grafo.NumVertices > (*p)->Reg.Chave.grafo.NumVertices)
    Insere_binaria(x, &(*p)->Dir);
}

void Inicializa_binaria(Apontador *Dicionario) { *Dicionario = NULL; }

int Vazio_binaria(Apontador *Dicionario) { return (Dicionario == NULL); }

//---------------------------------------------
// Seção de funções GRAFO:

void FLVazia(TipoLista *Lista) {
  Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Primeiro;
  Lista->Primeiro->Prox = NULL;
}

short Vazia(TipoLista Lista) { return (Lista.Primeiro == Lista.Ultimo); }

void Insere(TipoItem *x, TipoLista *Lista) {
  /*-- Insere depois do ultimo item da lista --*/
  Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Ultimo->Prox;
  Lista->Ultimo->Item = *x;
  Lista->Ultimo->Prox = NULL;
}

void FGVazio(TipoGrafo *Grafo) {
  long i;
  for (i = 0; i < Grafo->NumVertices; i++)
    FLVazia(&Grafo->Adj[i]);
}

void InsereAresta(TipoValorVertice V1, TipoValorVertice V2, TipoPeso Peso,
                  TipoGrafo *Grafo) {
  TipoItem x;
  x.Vertice = V2;
  x.peso = Peso;
  Insere(&x, &Grafo->Adj[V1]);
}

short ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2,
                   TipoGrafo *Grafo) {
  TipoApontador Aux;
  short EncontrouAresta = FALSE;
  Aux = Grafo->Adj[Vertice1].Primeiro->Prox;
  while (Aux != NULL && EncontrouAresta == FALSE) {
    if (Vertice2 == Aux->Item.Vertice)
      EncontrouAresta = TRUE;
    Aux = Aux->Prox;
  }
  return EncontrouAresta;
}

short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo) {
  return (Grafo->Adj[*Vertice].Primeiro == Grafo->Adj[*Vertice].Ultimo);
}

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo) {
  return (Grafo->Adj[*Vertice].Primeiro->Prox);
}

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj,
             TipoPeso *peso, TipoApontador *Prox, short *FimListaAdj) {
  /* Retorna Adj e Peso do Item apontado por Prox */
  *Adj = (*Prox)->Item.Vertice;
  *peso = (*Prox)->Item.peso;
  *Prox = (*Prox)->Prox;
  if (*Prox == NULL)
    *FimListaAdj = TRUE;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
  /*--Obs.: item a ser retirado e o seguinte ao apontado por p--*/
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
    printf("Erro: Lista vazia ou posicao nao existe\n");
    return;
  }
  q = p->Prox;
  *Item = q->Item;
  p->Prox = q->Prox;
  if (p->Prox == NULL)
    Lista->Ultimo = p;
  free(q);
}

void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *peso,
                  TipoGrafo *Grafo) {
  TipoApontador AuxAnterior, Aux;
  short EncontrouAresta = FALSE;
  TipoItem x;
  AuxAnterior = Grafo->Adj[*V1].Primeiro;
  Aux = Grafo->Adj[*V1].Primeiro->Prox;
  while (Aux != NULL && EncontrouAresta == FALSE) {
    if (*V2 == Aux->Item.Vertice) {
      Retira(AuxAnterior, &Grafo->Adj[*V1], &x);
      Grafo->NumArestas--;
      EncontrouAresta = TRUE;
    }
    AuxAnterior = Aux;
    Aux = Aux->Prox;
  }
}

void LiberaGrafo(TipoGrafo *Grafo) {
  TipoApontador AuxAnterior, Aux;
  for (int i = 0; i < Grafo->NumVertices; i++) {
    Aux = Grafo->Adj[i].Primeiro->Prox;
    free(Grafo->Adj[i].Primeiro); /*Libera celula cabeca*/
    Grafo->Adj[i].Primeiro = NULL;
    while (Aux != NULL) {
      AuxAnterior = Aux;
      Aux = Aux->Prox;
      free(AuxAnterior);
    }
  }
  Grafo->NumVertices = 0;
}

void ImprimeGrafo(TipoGrafo *Grafo) {
  int i;
  TipoApontador Aux;
  for (i = 0; i < Grafo->NumVertices; i++) {
    printf("Vertice%2d:", i);
    if (!Vazia(Grafo->Adj[i])) {
      Aux = Grafo->Adj[i].Primeiro->Prox;
      while (Aux != NULL) {
        printf("%3d (%d)", Aux->Item.Vertice, Aux->Item.peso);
        Aux = Aux->Prox;
      }
    }
    putchar('\n');
  }
}

void ImprimeLista(TipoLista Lista) {
  TipoApontador Aux;
  Aux = Lista.Primeiro->Prox;
  while (Aux != NULL) {
    printf("SALA: [%d] ---- VALOR: (%d)\n", Aux->Item.Vertice, Aux->Item.peso);
    Aux = Aux->Prox;
  }
}

TipoGrafo LerGrafoDoArquivo(const char *nomeArquivo) {
  FILE *arquivo;
  TipoGrafo grafo;

  // Abre o arquivo para leitura
  arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para ler os grafos.\n");
    exit(1);
  }
  // Lê o número de vértices e arestas do arquivo
  fscanf(arquivo, "%d %d", &grafo.NumVertices, &grafo.NumArestas);
  FGVazio(&grafo);

  // Lê as arestas do arquivo e insere no grafo
  for (int i = 0; i < grafo.NumArestas; i++) {
    int V1, V2;
    TipoPeso p;
    fscanf(arquivo, "%d %d %d", &V1, &V2, &p);
    InsereAresta(V1, V2, p, &grafo);
  }

  // Fecha o arquivo
  fclose(arquivo);

  return grafo;
}

//---------------------------------------------
// Seção de funções DIVERSAS:

void MostraDadosJogador(Jogador *jogador) {
  printf("Nome do jogador: %s\n", jogador->nome);
  printf("Tempo total de jogo: %.2lf segundos\n", jogador->tempoTotal);
  printf("Tempo gasto em cada area:\n");
  for (int i = 0; i < MAX_AREAS; i++) {
    printf("Area %d: %.2lf segundos\n", i + 1, jogador->tempoPorArea[i]);
  }
  printf("Area Central: %f\n", jogador->tempoAreaCentral);
  printf("Pontuacao na Area Central: %d\n", jogador->pontuacaoCentral);
}

void como_jogar() {
  printf("Como Jogar: Jogo de Labirinto\n");
  printf("Objetivo do Jogo:\n");
  printf("O objetivo do jogo e escapar do labirinto, avancando por diferentes "
         "areas ate chegar a Area Central. Cada avanco de fase aumenta a "
         "dificuldade, adicionando mais salas ao labirinto. O jogador deve "
         "encontrar o caminho correto para avancar sem cair em salas sem "
         "saida. Alem disso, e importante acumular pontos na Area Central para "
         "subir no ranking.\n\n");
  printf("Instrucoes:\n");
  printf("Escolha do Caminho:\n\n");
  printf("Ao entrar em uma area, o jogador devera escolher para qual sala "
         "deseja se mover.\n");
  printf("Cada sala pode levar a uma saida ou a uma sala sem saida.\n");
  printf("Se o jogador entrar em uma sala sem saida, ele deve recomecar a "
         "partir da sala inicial daquela area.\n");
  printf("Se encontrar a saida, avanca para outra area do mapa.\n\n");
  printf("Area Central:\n\n");
  printf("Diferente das outras salas, a Area Central contabiliza pontuacao "
         "para cada avanco e permite ao jogador retroceder uma sala "
         "sacrificando um ponto.\n");
  printf("A derrota ocorre apenas se o jogador encontrar uma sala sem pontos "
         "acumulados para usar o retorno.\n\n");
  printf("Dificuldade do Percurso:\n\n");
  printf("A dificuldade e determinada pelo numero de salas na area inicial.\n");
  printf("A cada avanco de fase, o numero de salas da proxima area aumenta em "
         "uma unidade em relacao a anterior.\n\n");
  printf("Mapa do Labirinto:\n\n");
  printf("Composto por caminhos que levam a Area Central.\n");
  printf("Cada regiao do mapa determina um conjunto de areas, e o progresso "
         "para uma nova regiao e feito completando todas as areas da regiao "
         "anterior.\n");
  printf("Todas as areas levam ao fim do labirinto, independentemente do "
         "caminho escolhido.\n\n");
  printf("Sistema de Ranking:\n\n");
  printf("Baseado no tempo de cada partida e na pontuacao feita na Area "
         "Central.\n");
  printf("O tempo e contado a partir do inicio do percurso e termina ao "
         "completar o labirinto.\n");
  printf("Armazena somente as ultimas 10 vitorias, organizando de forma "
         "crescente as informacoes do jogador (nome, tempo total, tempo gasto "
         "em cada area e pontuacao feita na Area Central).\n");
}

void criar_jogador(Jogador *jogador, char *nomeJogador) {
  strcpy(jogador->nome, nomeJogador);
  jogador->tempoTotal = 0.0;
  for (int i = 0; i < MAX_AREAS; i++) {
    jogador->tempoPorArea[i] = 0.0;
  }
  jogador->pontuacaoCentral = 0;
}

void Iniciar_Game(TipoDicionario p, Jogador *jogador) {
  if (*p == NULL) {
    return;
  }
  Iniciar_Game(&(*p)->Esq, jogador);
  Iniciar_Game(&(*p)->Dir, jogador);

  // -- (VISITA) em que PERCORRE UMA AREA -- :
  TipoGrafo *aux = (TipoGrafo *)malloc(sizeof(TipoGrafo));
  if (aux == NULL) {
    printf("Erro ao alocar memoria para o grafo auxiliar.\n");
    exit(1);
  }
  FGVazio(aux);
  *aux = (*p)->Reg.Chave.grafo;
  int salaAtual = aux->NumVertices - 4;
  int AuxPrint = salaAtual + 1;
  if (salaAtual == 0) {
    system("clear");
  }
  printf("\nVoce esta na area indicada pela seta\n");
  printf("\nA1->A2->A3->A4->A5->A6->A7(Area Central)\n");
  for (int i = 0; i < AuxPrint - 1; i++) {
    printf("    ");
  }
  printf("↑\n");
  printf("\nPressione 'Enter' para avancar\n");
  getchar();
  system("clear");
  printf("Tempo Total: %f", jogador->tempoTotal);
  if (aux->Adj[0].Primeiro->Prox->Item.peso == 0) {
    // Percorre uma área normal
    Tempo inicio = time(NULL); // Registra o tempo de início do percurso
    percurso(0, aux, jogador);
    Tempo fim = time(NULL); // Registra o tempo de fim do percurso
    jogador->tempoPorArea[salaAtual] += difftime(fim, inicio);
    // Calcula o tempo decorrido
    jogador->tempoTotal += difftime(fim, inicio);
  } else {
    // Percorre a Área Central
    Tempo inicioCentral =
        time(NULL); // Registra o tempo de início da Área Central
    percursoCentral(0, aux, jogador);
    Tempo fimCentral = time(NULL); // Registra o tempo de fim da Área Central
    jogador->tempoAreaCentral = (fimCentral - inicioCentral);
    // Calcula o tempo decorrido na Área Central
    jogador->tempoTotal += (fimCentral - inicioCentral);
  }

  free(aux);
  printf("========================AVANCOU DE AREA=========================\n");

  // Aqui deve ter a opcao de ver as areas percorridas. SALVAR em uma LISTA de
  // GRAFOS em que SERA possivel visualisa-lo.
}

void percursoCentral(TipoValorVertice verticeA, TipoGrafo *Grafo,
                     Jogador *jogador) {

  if (verticeA == Grafo->NumVertices - 1) {
    getchar();
    return;
  }
  system("clear");
  printf("\n ~~ C E N T R A L ~~ \n=== SALA ATUAL: [%d]       PONTUACAO ATUAL: "
         "[%d] ===\n\n",
         verticeA, jogador->pontuacaoCentral);
  int escolha;
  TipoApontador Aux = PrimeiroListaAdj(&verticeA, Grafo);
  printf("\n----------- Adjascentes: --------------\n");
  // --------- Verificando GAMEOVER, (nao tem pontos para andar)---------
  int ver = 1;
  while (Aux != NULL) {
    if (jogador->pontuacaoCentral + Aux->Item.peso >= 0) {
      ver = 0;
    }
    Aux = Aux->Prox;
  }
  if (ver == 1) {
    printf("\n<< GAMEOVER >>   << VOCE NAO TEM PONTOS PARA CAMINHAR!! >> << "
           "VOCE PERDEU TODOS SEUS PONTOS NA AREA CENTRAL >>\n");
    jogador->pontuacaoCentral = 0;
    return;
  }

  while (1) { // Para ver se ELE PODE IR PARA TAL VERTICE

    Aux = PrimeiroListaAdj(&verticeA, Grafo);
    while (1) {
      Aux = PrimeiroListaAdj(&verticeA, Grafo);
      printf("\nEscolha a SALA...\n");
      ImprimeLista(Grafo->Adj[verticeA]); // Imprime seus adjascentes

      scanf("%d", &escolha);

      while (Aux->Prox != NULL) {
        if (Aux->Item.Vertice == escolha)
          break;
        Aux = Aux->Prox;
      }
      if (Aux->Item.Vertice == escolha)
        break;
      printf(" -- Voce nao pode VISITAR esta SALA! -- \n\n");
      system("clear");
    }

    // Chama o percurso a partir daquele vertice.
    if (jogador->pontuacaoCentral + Aux->Item.peso >= 0) {
      break;
    } else {
      printf("PONTUACAO INSUFICIENTE!!\n");
      system("clear");
    }
  }

  jogador->pontuacaoCentral += Aux->Item.peso; // Somando a pontuacao
  percursoCentral(Aux->Item.Vertice, Grafo, jogador);
}
void percurso(TipoValorVertice verticeA, TipoGrafo *Grafo, Jogador *jogador) {
  system("clear");
  printf("\nNUMERO DE SALAS: [%d] e CONEXOES: [%d]\n", Grafo->NumVertices,
         Grafo->NumArestas);
  if (verticeA == Grafo->NumVertices - 1) {
    /*
        VENCE (chegou no N-ésimo Vértice)
        Incrementar VITORIAS em 3
    */

    printf("\n<< VITORIA >>   << VOCE CHEGOU A SAIDA!! >>\n");
    printf("\nAguarde 3 segundos...\n");
    getchar();
    system("clear");
    return;
  }

  printf("=== SALA ATUAL: [%d] ===\n\n", verticeA);
  int escolha;
  TipoApontador Aux = PrimeiroListaAdj(&verticeA, Grafo);

  // --------- Verificando GAMEOVER, (chegou numa sala sem adjascentes)---------
  if (Aux == NULL) {

    printf("\n<< GAMEOVER >>   << VOCE NAO TEM SAIDA!! >>\n\n");
    printf("\nAguarde 3 segundos....\n");
    sleep(3);
    return percurso(0, Grafo,
                    jogador); // Chama o percurso NOVAMENTE para vertice INICIAL
  }

  while (1) { // Para ver se ELE PODE IR PARA TAL VERTICE
    Aux = PrimeiroListaAdj(&verticeA, Grafo);
    printf("\nEscolha a SALA...\n");
    ImprimeLista(Grafo->Adj[verticeA]); // Imprime seus adjascentes

    scanf("%d", &escolha);

    while (Aux->Prox != NULL) {
      if (Aux->Item.Vertice == escolha)
        break;
      Aux = Aux->Prox;
    }

    if (Aux->Item.Vertice != escolha)
      printf(" -- Voce nao pode VISITAR esta SALA! -- \n\n");
    else
      break;
  }

  percurso(Aux->Item.Vertice, Grafo, jogador);
}

Jogador chamaDadosJogador(char *nomeBusca) {
  FILE *pont_arq;
  char nome[MAX_NOME];
  Jogador player1;
  criar_jogador(&player1, nomeBusca);
  // ----- Essa função verifica se um jogador existe no arquivo, se ele existir
  // puxo os dados, se não, crio o jogador. -------

  // Abrindo o arquivo em modo leitura
  pont_arq = fopen("Arquivos-Ranking/ranking.txt", "r");

  // Verificando se o arquivo foi aberto corretamente
  if (pont_arq == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return player1;
  }

  // Lendo linha por linha e comparando o nome buscado
  while (fgets(nome, MAX_NOME, pont_arq) != NULL) {
    // Removendo o caractere de nova linha
    nome[strlen(nome) - 1] = '\0';

    // Verificar se o nome buscado é igual ao nome lido do arquivo
    if (strcmp(nome, nomeBusca) == 0) {
      double tempoPorAREA[MAX_AREAS], tempTotal;
      int pontosNaCentral;
      // Ler os valores de vitórias, derrotas e pontos da linha
      sscanf(nome + strlen(nomeBusca) + 1, "%lf %lf %lf %lf %lf %lf %lf %d",
             &tempoPorAREA[0], &tempoPorAREA[1], &tempoPorAREA[2],
             &tempoPorAREA[3], &tempoPorAREA[4], &tempoPorAREA[5], &tempTotal,
             &pontosNaCentral);

      // Fechando o arquivo
      fclose(pont_arq);

      // Atribuir os valores lidos à estrutura do jogador
      strcpy(player1.nome, nomeBusca);
      for (int it = 0; it < MAX_AREAS; it++)
        player1.tempoPorArea[it] = tempoPorAREA[it];
      player1.tempoTotal = tempTotal;
      player1.pontuacaoCentral = pontosNaCentral;

      return player1;
    }
  }

  // Fechando o arquivo e retornando Jogador Criado.
  fclose(pont_arq);
  criar_jogador(&player1,
                nomeBusca); // Criar jogador se o nome não existir no arquivo
  return player1;
}

//----------------------------------------------------------------
//                    ORDENAÇÃO RANKING

#define MAX_RANKING 10
Jogador ranking[MAX_RANKING];
int numJogadores = 0;

// Função para adicionar um jogador ao ranking
void adicionarJogador(Jogador novoJogador) {
  ranking[numJogadores] = novoJogador;
  numJogadores++;
}

void adicionarJogador_Arquivo(Jogador novoJogador) {
  FILE *arquivo;
  arquivo = fopen("Arquivos-Ranking/ranking.txt", "a");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }
  fprintf(arquivo, "%s %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %d\n",
          novoJogador.nome, novoJogador.tempoTotal, novoJogador.tempoPorArea[0],
          novoJogador.tempoPorArea[1], novoJogador.tempoPorArea[2],
          novoJogador.tempoPorArea[3], novoJogador.tempoPorArea[4],
          novoJogador.pontuacaoCentral);
  fclose(arquivo);
}

// Função para ordenar o ranking pelo tempo total
void ordenarRanking_TempoTotal() {
  int i, j;
  Jogador chave;

  for (i = 1; i < numJogadores; i++) {
    chave = ranking[i];
    j = i - 1;

    // Invertendo a condição para ordenar do menor tempo para o maior
    while (j >= 0 && ranking[j].tempoTotal > chave.tempoTotal) {
      ranking[j + 1] = ranking[j];
      j = j - 1;
    }
    ranking[j + 1] = chave;
  }
}

void ordenarRanking_PontuacaoCentral() {
  int i, j;
  Jogador chave;

  for (i = 1; i < numJogadores; i++) {
    chave = ranking[i];
    j = i - 1;

    while (j >= 0 && ranking[j].pontuacaoCentral < chave.pontuacaoCentral) {
      ranking[j + 1] = ranking[j];
      j = j - 1;
    }
    ranking[j + 1] = chave;
  }
}

// Função para exibir os 10 melhores jogadores do ranking
void mostrarRanking() {
  printf("Ranking dos 10 Melhores Jogadores Na categoria especifica:\n");
  // Mostrando apenas os 10 melhores jogadores
  for (int i = 0; i < 10; i++) {
    printf("%d. Nome: %s, Tempo Total: %.2lf, Pontuacao Central: %d\n", i + 1,
           ranking[i].nome, ranking[i].tempoTotal, ranking[i].pontuacaoCentral);
  }
}

#define MAX_LINE_LENGTH 256

void InicializaRanking() {
  FILE *arquivo;
  char linha[MAX_LINE_LENGTH];

  arquivo = fopen("Arquivos-Ranking/ranking.txt", "r");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  } else {
    printf("Arquivo aberto com sucesso!\n");
  }

  while (fgets(linha, MAX_LINE_LENGTH, arquivo) != NULL) {
    Jogador novoJogador;
    sscanf(linha, "%s %lf %*lf %*lf %*lf %*lf %*lf %d", novoJogador.nome,
           &novoJogador.tempoTotal, &novoJogador.pontuacaoCentral);

    adicionarJogador(novoJogador);
  }

  fclose(arquivo);
}

// Função para apagar o ranking por completo
void apagarRanking() {
  FILE *arquivo = fopen("Arquivos-Ranking/ranking.txt", "w");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }
  fclose(arquivo);
  printf("Ranking apagado com sucesso.\n");
}

// Função para apagar um jogador específico do ranking
void apagarJogador(char *nomeJogador) {
  FILE *arquivoEntrada = fopen("Arquivos-Ranking/ranking.txt", "r");
  if (arquivoEntrada == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }

  FILE *arquivoSaida = fopen("Arquivos-Ranking/temp.txt", "w");
  if (arquivoSaida == NULL) {
    perror("Erro ao criar arquivo temporário");
    fclose(arquivoEntrada);
    return;
  }

  Jogador jogador;
  int jogadorEncontrado = 0;
  while (fscanf(arquivoEntrada, "%s %lf %lf %lf %lf %lf %lf %d", jogador.nome,
                &jogador.tempoTotal, &jogador.tempoPorArea[0],
                &jogador.tempoPorArea[1], &jogador.tempoPorArea[2],
                &jogador.tempoPorArea[3], &jogador.tempoAreaCentral,
                &jogador.pontuacaoCentral) == 8) {
    if (strcmp(jogador.nome, nomeJogador) != 0) {
      fprintf(arquivoSaida, "%s %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %d\n",
              jogador.nome, jogador.tempoTotal, jogador.tempoPorArea[0],
              jogador.tempoPorArea[1], jogador.tempoPorArea[2],
              jogador.tempoPorArea[3], jogador.tempoAreaCentral,
              jogador.pontuacaoCentral);
    } else {
      jogadorEncontrado = 1;
    }
  }

  fclose(arquivoEntrada);
  fclose(arquivoSaida);

  if (!jogadorEncontrado) {
    printf("Jogador não encontrado no ranking.\n");
    remove("Arquivos-Ranking/temp.txt");
    return;
  }

  if (remove("Arquivos-Ranking/ranking.txt") != 0) {
    perror("Erro ao remover arquivo original");
    return;
  }

  if (rename("Arquivos-Ranking/temp.txt", "Arquivos-Ranking/ranking.txt") !=
      0) {
    perror("Erro ao renomear arquivo temporário");
    return;
  }

  printf("Jogador removido com sucesso.\n");
}

//---------------------------------------------