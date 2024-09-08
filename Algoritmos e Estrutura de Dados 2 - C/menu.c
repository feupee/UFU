// Breno Oliveira Cavalcante - 12221BCC011.
// Felipe Santos Silva - 12221BCC042.
// Marcos Gabriel Moreira Fonseca - 12221BCC043.

#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  int opcao;
  TipoDicionario Dicionario;
  int pressionado;
  int opcao2;
  char nome_player_remocao[30];
  InicializaRanking();
  do {
  inicio:
    system("clear"); // Limpar a tela (para sistemas Unix/Linux)
    printf("Dica: Digite o número da opção do menu e pressione Enter!\n");
    printf("1 - JOGAR\n");
    printf("2 - RANKING\n");
    printf("3 - COMO JOGAR\n");
    printf("4 - SOBRE\n");
    printf("5 - SAIR\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      // -------------------   Criação do MAPA --------------------------

      Inicializa_binaria(&Dicionario);
      char nome_arquivo[20];
      Registro registro;
      // Le area central
      registro.Chave.grafo = LerGrafoDoArquivo("AreasGame/AreaCentral.txt");
      Insere_binaria(registro, &Dicionario);
      // Le todas as AREAS e insere no MAPA
      for (int i = MAX_AREAS; i >= 1; i--) {
        sprintf(nome_arquivo, "AreasGame/Area%d.txt", i);
        registro.Chave.grafo = LerGrafoDoArquivo(nome_arquivo);
        Insere_binaria(registro, &Dicionario);
      }
      setbuf(stdin, NULL); // Limpa o buffer de entrada

      char nome_player[30];
      printf("Digite seu nome: ");
      fgets(nome_player, sizeof(nome_player), stdin);

      // Remover o caractere de nova linha, se existir
      size_t len = strlen(nome_player); // Obter o comprimento da string lida
      if (len > 0 && nome_player[len - 1] == '\n') {
        nome_player[len - 1] = '\0'; // Substituir o '\n' por '\0'
      }
      // ----- CHAMA A FUNÇÃO PARA JOGAR O LABIRINTO -----
      Jogador jogador = chamaDadosJogador(nome_player);
      Iniciar_Game(&Dicionario, &jogador); // Começa na area 1
      printf(" --- Fim de game! --- \n");
      MostraDadosJogador(&jogador);
      adicionarJogador(jogador);
      adicionarJogador_Arquivo(jogador);
      setbuf(stdin, NULL);
      printf("\n\nPressione Enter para sair...");
      getchar();
      goto inicio;
      break;
    case 2:
      printf("\nEscolha uma opcao para ordenar o ranking: \n");
      printf("1 - TEMPO TOTAL\n");
      printf("2 - PONTUACAO DA AREA CENTRAL\n");
      printf("3 - APAGAR REGISTRO INDIVIDUAL\n");
      printf("4 - RESETAR RANKING\n");
      scanf("%d", &opcao2);
      switch (opcao2) {
      case 1: 
        system("clear");
        ordenarRanking_TempoTotal();
        mostrarRanking();
        setbuf(stdin, NULL);
        printf("\n\nPressione Enter para sair...");
        getchar();
        break;
      case 2:
        system("clear");
        ordenarRanking_PontuacaoCentral();
        mostrarRanking();
        setbuf(stdin, NULL);
        printf("\n\nPressione Enter para sair...");
        getchar();
        break;
      case 3:
        setbuf(stdin, NULL);
        printf("Digite o nome para remocao: ");
        fgets(nome_player_remocao, sizeof(nome_player_remocao), stdin);
        size_t length = strlen(nome_player_remocao);
        if (nome_player_remocao[length - 1] == '\n') {
          nome_player_remocao[length - 1] = '\0';
        }
        apagarJogador(nome_player_remocao);
        InicializaRanking();
        break;
      case 4:
        apagarRanking();
        InicializaRanking();
        break;
      }
      break;
    case 3:
      como_jogar();
      setbuf(stdin, NULL);
      printf("\n\nPressione Enter para sair...");
      getchar();
      break;
    case 4:
      printf("\nJogo Feito por: \n\nBreno Oliveira Cavalcante - Felipe Santos "
             "Silva - "
             "Marcos Gabriel Moreira Fonseca");
      setbuf(stdin, NULL);
      printf("\n\nPressione Enter para sair...");
      getchar();

      break;
    case 5:
      system("clear");
      exit(0);
      break;
    }
  } while (opcao !=
           5); // Sai do loop principal quando a opção selecionada for "SAIR"
  return 0;
}