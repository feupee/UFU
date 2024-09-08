#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"

// --------------   Implementaçoes do JOGADOR    ---------------

void criar_jogador(Jogador *jogador, char *nomeJogador) {
    strcpy(jogador->nome, nomeJogador);
    jogador->tempoTotal = 0.0;
    for (int i = 0; i < MAX_AREAS; i++) {
        jogador->tempoPorArea[i] = 0.0;
    }
    jogador->pontuacaoCentral = 0;
}

Jogador chamaDadosJogador(char *nomeBusca) {
    FILE *pont_arq;
    char nome[MAX_NOME];
    Jogador player1;
    criar_jogador(&player1, nomeBusca);
    // ----- Essa função verifica se um jogador existe no arquivo, se ele existir puxo os dados, se não, crio o jogador. -------

    // Abrindo o arquivo em modo leitura
    pont_arq = fopen("ranking.txt", "r");
    
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
            sscanf(nome + strlen(nomeBusca) + 1, "%lf %lf %lf %lf %lf %lf %lf %d", &tempoPorAREA[0],&tempoPorAREA[1],&tempoPorAREA[2],&tempoPorAREA[3],&tempoPorAREA[4],&tempoPorAREA[5],&tempTotal, &pontosNaCentral);

            // Fechando o arquivo
            fclose(pont_arq);

            // Atribuir os valores lidos à estrutura do jogador
            strcpy(player1.nome, nomeBusca);
            for(int it = 0; it<MAX_AREAS;it++)
                player1.tempoPorArea[it] = tempoPorAREA[it];
            player1.tempoTotal = tempTotal;
            player1.pontuacaoCentral = pontosNaCentral;

            return player1;
        }
    }

    // Fechando o arquivo e retornando Jogador Criado.
    fclose(pont_arq);
    criar_jogador(&player1, nomeBusca); // Criar jogador se o nome não existir no arquivo
    return player1;
}

void MostraDadosJogador(Jogador* jogador) {
    printf("Nome do jogador: %s\n", jogador->nome);
    printf("Tempo total de jogo: %.2lf segundos\n", jogador->tempoTotal);
    printf("Tempo gasto em cada area:\n");
    for (int i = 0; i < MAX_AREAS; i++) {
        printf("Area %d: %.2lf segundos\n", i + 1, jogador->tempoPorArea[i]);
    }
    printf("Pontuacao na Area Central: %d\n", jogador->pontuacaoCentral);
}

// --------------   Implementaçoes do MAPA/ARVORE   ---------------
void Iniciar_Game(Apontador *p, Jogador *jogador) {
  if (*p == NULL)
    return;
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
    int salaAtual = aux->NumVertices-3;

    if(aux->Adj[0].Primeiro->Prox->Item.peso == 0){
      // Percorre uma área normal
        Tempo inicio = time(NULL); // Registra o tempo de início do percurso
        percurso(0, aux, jogador);
        Tempo fim = time(NULL); // Registra o tempo de fim do percurso
        jogador->tempoPorArea[salaAtual] += difftime(fim, inicio);
        // Calcula o tempo decorrido
        jogador->tempoTotal += difftime(fim, inicio);
    } else {
        // Percorre a Área Central
        Tempo inicioCentral = time(NULL); // Registra o tempo de início da Área Central
        percursoCentral(0, aux, jogador);
        Tempo fimCentral = time(NULL); // Registra o tempo de fim da Área Central
        // Calcula o tempo decorrido na Área Central
        jogador->tempoTotal += (fimCentral - inicioCentral);
    }  

    free(aux);
    printf("========================AVANCOU AREA=========================\n");
    // Aqui deve ter a opcao de ver as areas percorridas. SALVAR em uma LISTA de GRAFOS em que SERA possivel visualisa-lo.

}

void percursoPosFixado(Apontador *raiz) { //essa função printa a arvore binaria usando POS_FIXADO
    if (*raiz != NULL) {
        percursoPosFixado(&(*raiz)->Esq);
        percursoPosFixado(&(*raiz)->Dir);
        printf("GRAFO: V=[%d], A=[%d], P=[%d]\n", (*raiz)->Reg.Chave.grafo.NumVertices, (*raiz)->Reg.Chave.grafo.NumArestas, (*raiz)->Reg.Chave.grafo.Adj[1].Primeiro->Prox->Item.peso);
    }
}

void Inicializa_binaria(Apontador *Dicionario) { *Dicionario = NULL; }

int Vazio_binaria(Apontador *Dicionario) { return (Dicionario == NULL); }

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

void Retira_binaria(Registro x, Apontador *p) {
  Apontador Aux;
  if (*p == NULL) {
    printf("Erro: Registro nao esta na arvore \n");
    return;
  }
  if (x.Chave.grafo.NumVertices < (*p)->Reg.Chave.grafo.NumVertices) {
    Retira_binaria(x, &(*p)->Esq);
    return;
  }
  if (x.Chave.grafo.NumVertices > (*p)->Reg.Chave.grafo.NumVertices) {
    Retira_binaria(x, &(*p)->Dir);
    return;
  }
  if ((*p)->Esq != NULL) {
    Antecessor_binaria(*p, &(*p)->Esq);
    return;
  }
  Aux = *p;
  *p = (*p)->Dir;
  free(Aux);
}


// ---------------------   Implementaçoes da AREA/GRAFO   -------------------------------------

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

short Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

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

void InsereAresta(TipoValorVertice V1, TipoValorVertice V2,
                  TipoPeso Peso, TipoGrafo *Grafo) {
    TipoItem x;
    x.Vertice = V2;
    x.peso = Peso;
    Insere(&x, &Grafo->Adj[V1]);
}

short ExisteAresta(TipoValorVertice Vertice1,
                   TipoValorVertice Vertice2, TipoGrafo *Grafo) {
    TipoApontador Aux;
    short EncontrouAresta = FALSE;
    Aux = Grafo->Adj[Vertice1].Primeiro->Prox;
    while (Aux != NULL && EncontrouAresta == FALSE) {
        if (Vertice2 == Aux->Item.Vertice) EncontrouAresta = TRUE;
        Aux = Aux->Prox;
    }
    return EncontrouAresta;
}

/* Operadores para obter a lista de adjacentes */
short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo) {
    return (Grafo->Adj[*Vertice].Primeiro == Grafo->Adj[*Vertice].Ultimo);
}

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice,
                               TipoGrafo *Grafo) {
    return (Grafo->Adj[*Vertice].Primeiro->Prox);
}

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo,
             TipoValorVertice *Adj, TipoPeso *peso,
             TipoApontador *Prox, short *FimListaAdj) {
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

void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2,
                  TipoPeso *peso, TipoGrafo *Grafo) {
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
    for (i = 0; i < Grafo->NumVertices; i++) {
        Aux = Grafo->Adj[i].Primeiro->Prox;
        free(Grafo->Adj[i].Primeiro);   /*Libera celula cabeca*/
        Grafo->Adj[i].Primeiro=NULL;
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

void percursoCentral(TipoValorVertice verticeA, TipoGrafo *Grafo, Jogador* jogador)
{
    
    if (verticeA == Grafo->NumVertices - 1)
    {
        /*
            VENCE (chegou no N-ésimo Vértice)
        */
        return;
    }
    printf("\n ~~ C E N T R A L ~~ \n=== SALA ATUAL: [%d]       PONTUACAO ATUAL: [%d] ===\n\n", verticeA, jogador->pontuacaoCentral);
    int escolha;
    TipoApontador Aux = PrimeiroListaAdj(&verticeA, Grafo);
    ImprimeGrafo(Grafo); //para debugar
    printf("\n----------- Adjascentes: --------------\n");
    ImprimeLista(Grafo->Adj[verticeA]); //para debugar
    // --------- Verificando GAMEOVER, (nao tem pontos para andar)---------
    int ver = 1;
    while (Aux != NULL)
    {
        if (jogador->pontuacaoCentral + Aux->Item.peso >= 0)
        {
            ver = 0;
        }
        Aux = Aux->Prox;
    }
    if (ver == 1)
    {
        printf("\n<< GAMEOVER >>   << VOCE NAO TEM PONTOS PARA CAMINHAR!! >> << VOCE PERDEU TODOS SEUS PONTOS NA AREA CENTRAL >>\n");
        jogador->pontuacaoCentral = 0;
        return;
    }

    while (1)
    { // Para ver se ELE PODE IR PARA TAL VERTICE

        Aux = PrimeiroListaAdj(&verticeA, Grafo);
        while (1)
        {
            Aux = PrimeiroListaAdj(&verticeA, Grafo);
            printf("\nEscolha a SALA...\n");
            ImprimeLista(Grafo->Adj[verticeA]); // Imprime seus adjascentes

            scanf("%d", &escolha);
            
            while (Aux->Prox != NULL)
            {
                if (Aux->Item.Vertice == escolha)
                    break;
                Aux = Aux->Prox;
            }
            if (Aux->Item.Vertice == escolha)
                break;
            printf(" -- Voce nao pode VISITAR esta SALA! -- \n\n");
        }

        // Chama o percurso a partir daquele vertice.
        if (jogador->pontuacaoCentral + Aux->Item.peso >= 0)
        {
            break;
        }
        else
        {
            printf("PONTUACAO INSUFICIENTE!!\n");
        }
    }

    jogador->pontuacaoCentral += Aux->Item.peso; // Somando a pontuacao
    percursoCentral(Aux->Item.Vertice, Grafo, jogador);
}

void percurso(TipoValorVertice verticeA, TipoGrafo *Grafo, Jogador* jogador)
{
    ImprimeGrafo(Grafo);
    printf("\nNUMERO DE SALAS: [%d] e CONEXOES: [%d]\n", Grafo->NumVertices,Grafo->NumArestas);
    if (verticeA == Grafo->NumVertices - 1)
    {
        /*
            VENCE (chegou no N-ésimo Vértice)
            Incrementar VITORIAS em 3
        */
        
        printf("\n<< VITORIA >>   << VOCE CHEGOU A SAIDA!! >>\n");
        return;
    }

    printf("=== SALA ATUAL: [%d] ===\n\n", verticeA);
    int escolha;
    TipoApontador Aux = PrimeiroListaAdj(&verticeA, Grafo);

    // --------- Verificando GAMEOVER, (chegou numa sala sem adjascentes)---------
    if (Aux == NULL)
    {
        

        printf("\n<< GAMEOVER >>   << VOCE NAO TEM SAIDA!! >>\n\n");
        system("pause");
        return percurso(0,Grafo, jogador); //Chama o percurso NOVAMENTE para vertice INICIAL
       
    }

    while (1)
    { // Para ver se ELE PODE IR PARA TAL VERTICE
            Aux = PrimeiroListaAdj(&verticeA, Grafo);
            printf("\nEscolha a SALA...\n");
            ImprimeLista(Grafo->Adj[verticeA]); // Imprime seus adjascentes

            scanf("%d", &escolha);
            
            while (Aux->Prox != NULL)
            {
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
    for (int i = 0; i < grafo.NumArestas; i++)
    {
        int V1, V2;
        TipoPeso p;
        fscanf(arquivo, "%d %d %d", &V1, &V2, &p);
        InsereAresta(V1, V2, p, &grafo);
    }
    
    // Fecha o arquivo
    fclose(arquivo);

    return grafo;
}
