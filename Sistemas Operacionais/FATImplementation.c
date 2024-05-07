#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numeroCluster;
    unsigned char* dados;
} Cluster;

typedef struct {
    Cluster* clusters;
    int clustersLivres;
    int totalClusters;
} AreaDados;

typedef struct {
    int* tabela;
    int clustersLivres;
    int totalClusters;
} TabelaFAT;

typedef struct {
    char* nomeArquivo;
    int clusterInicial;
} EntradaDiretorio;

typedef struct {
    EntradaDiretorio* entradas;
    int numEntradas;
} Diretorio;

typedef struct {
    TabelaFAT tabelaFAT;
    AreaDados areaDados;
    Diretorio diretorio;
} Disco;

void inicializarAreaDados(AreaDados* areaDados, int numClusters, int tamanhoCluster) {
    areaDados->clusters = malloc(numClusters * sizeof(Cluster));
    areaDados->clustersLivres = numClusters;
    areaDados->totalClusters = numClusters;

    for (int i = 0; i < numClusters; i++) {
        areaDados->clusters[i].numeroCluster = i;
        areaDados->clusters[i].dados = NULL;
    }
}

void inicializarTabelaFAT(TabelaFAT* tabelaFAT, int numClusters) {
    tabelaFAT->tabela = malloc(numClusters * sizeof(int));
    tabelaFAT->clustersLivres = numClusters;
    tabelaFAT->totalClusters = numClusters;

    for (int i = 0; i < numClusters; i++) {
        tabelaFAT->tabela[i] = -1;
    }
}

void inicializarDiretorio(Diretorio* diretorio) {
    diretorio->entradas = NULL;
    diretorio->numEntradas = 0;
}

void inicializarDisco(Disco* disco, int numClusters, int tamanhoCluster) {
    inicializarAreaDados(&disco->areaDados, numClusters, tamanhoCluster);
    inicializarTabelaFAT(&disco->tabelaFAT, numClusters);
    inicializarDiretorio(&disco->diretorio);
}

int encontrarProximoClusterLivre(TabelaFAT* tabelaFAT) {
    for (int i = 0; i < tabelaFAT->totalClusters; i++) {
        if (tabelaFAT->tabela[i] == -1) {
            return i;
        }
    }
    return -1;
}

void adicionarEntradaAoDiretorio(Diretorio* diretorio, char* nomeArquivo, int clusterInicial) {
    diretorio->entradas = realloc(diretorio->entradas, (diretorio->numEntradas + 1) * sizeof(EntradaDiretorio));
    diretorio->entradas[diretorio->numEntradas].nomeArquivo = malloc(strlen(nomeArquivo) + 1);
    strcpy(diretorio->entradas[diretorio->numEntradas].nomeArquivo, nomeArquivo);
    diretorio->entradas[diretorio->numEntradas].clusterInicial = clusterInicial;
    diretorio->numEntradas++;
}

void removerEntradaDoDiretorio(Diretorio* diretorio, char* nomeArquivo) {
    // Percorrer entradas do diretorio 
    for (int i = 0; i < diretorio->numEntradas; i++) {
        if (strcmp(diretorio->entradas[i].nomeArquivo, nomeArquivo) == 0) {
            free(diretorio->entradas[i].nomeArquivo);
            for (int j = i; j < diretorio->numEntradas - 1; j++) {
                diretorio->entradas[j] = diretorio->entradas[j + 1];
            }
            diretorio->numEntradas--;
            diretorio->entradas = realloc(diretorio->entradas, diretorio->numEntradas * sizeof(EntradaDiretorio));
            break;
        }
    }
}

void escreverDadosNoCluster(Cluster* cluster, unsigned char* dados, int tamanho) {
    cluster->dados = malloc(tamanho);
    memcpy(cluster->dados, dados, tamanho);
}

void limparCluster(Cluster* cluster) {
    free(cluster->dados);
    cluster->dados = NULL;
}

void adicionarDadosAoDisco(Disco* disco, char* nomeArquivo, unsigned char* dados, int tamanho) {
    int numClusters = tamanho / disco->areaDados.totalClusters + 1;
    int* clusters = malloc(numClusters * sizeof(int));

    for (int i = 0; i < numClusters; i++) {
        int numeroCluster = encontrarProximoClusterLivre(&disco->tabelaFAT);
        clusters[i] = numeroCluster;
        int tamanhoDados = (i == numClusters - 1) ? tamanho % disco->areaDados.totalClusters : disco->areaDados.totalClusters;
        escreverDadosNoCluster(&disco->areaDados.clusters[numeroCluster], dados + i * disco->areaDados.totalClusters, tamanhoDados);
        disco->tabelaFAT.tabela[numeroCluster] = (i == numClusters - 1) ? -1 : encontrarProximoClusterLivre(&disco->tabelaFAT);
        disco->tabelaFAT.clustersLivres--;
        disco->areaDados.clustersLivres--;
    }

    adicionarEntradaAoDiretorio(&disco->diretorio, nomeArquivo, clusters[0]);
    free(clusters);
}

unsigned char* lerDadosDoDisco(Disco* disco, char* nomeArquivo, int* tamanho) {
    for (int i = 0; i < disco->diretorio.numEntradas; i++) {
        if (strcmp(disco->diretorio.entradas[i].nomeArquivo, nomeArquivo) == 0) {
            int clusterInicial = disco->diretorio.entradas[i].clusterInicial;
            int numeroCluster = clusterInicial;
            int tamanhoDados = 0;
            unsigned char* dados = NULL;

            while (numeroCluster != -1) {
                Cluster cluster = disco->areaDados.clusters[numeroCluster];
                int tamanhoCluster = strlen((char*)cluster.dados);
                dados = realloc(dados, tamanhoDados + tamanhoCluster);
                memcpy(dados + tamanhoDados, cluster.dados, tamanhoCluster);
                tamanhoDados += tamanhoCluster;
                numeroCluster = disco->tabelaFAT.tabela[numeroCluster];
            }

            if (tamanho != NULL)
                *tamanho = tamanhoDados;

            return dados;
        }
    }
    return NULL;
}

void removerDadosDoDisco(Disco* disco, char* nomeArquivo) {
    for (int i = 0; i < disco->diretorio.numEntradas; i++) {
        if (strcmp(disco->diretorio.entradas[i].nomeArquivo, nomeArquivo) == 0) {
                        int clusterInicial = disco->diretorio.entradas[i].clusterInicial;
            int numeroCluster = clusterInicial;

            while (numeroCluster != -1) {
                Cluster cluster = disco->areaDados.clusters[numeroCluster];
                limparCluster(&cluster);
                disco->tabelaFAT.tabela[numeroCluster] = -1;
                disco->tabelaFAT.clustersLivres++;
                disco->areaDados.clustersLivres++;
                numeroCluster = disco->tabelaFAT.tabela[numeroCluster];
            }

            removerEntradaDoDiretorio(&disco->diretorio, nomeArquivo);
            break;
        }
    }
}

int main() {
    Disco disco;
    inicializarDisco(&disco, 200, 4);

    char* nomeArquivo1 = "Teste.txt";
    unsigned char dados1[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x6D, 0x75, 0x6E, 0x64, 0x6F};
    int tamanhoDados1 = sizeof(dados1);
    adicionarDadosAoDisco(&disco, nomeArquivo1, dados1, tamanhoDados1);
    printf("%s\n", lerDadosDoDisco(&disco, nomeArquivo1, NULL));

    char* nomeArquivo2 = "Teste2.txt";
    unsigned char dados2[] = {0x43, 0x6F, 0x6D, 0x6F, 0x20, 0x65, 0x73, 0x74, 0x61, 0x20, 0x74, 0x75, 0x64, 0x6F, 0x3F};
    int tamanhoDados2 = sizeof(dados2);
    adicionarDadosAoDisco(&disco, nomeArquivo2, dados2, tamanhoDados2);
    printf("%s\n", lerDadosDoDisco(&disco, nomeArquivo2, NULL));

    removerDadosDoDisco(&disco, nomeArquivo1);

    char* nomeArquivo3 = "Teste3.txt";
    unsigned char dados3[] = {0x4F, 0x6C, 0x61, 0x20, 0x6D, 0x75, 0x6E, 0x64, 0x6F, 0x20, 0x65, 0x6D, 0x20, 0x65, 0x73, 0x70, 0x61, 0x6E, 0x6F, 0x6C};
    int tamanhoDados3 = sizeof(dados3);
    adicionarDadosAoDisco(&disco, nomeArquivo3, dados3, tamanhoDados3);
    printf("%s\n", lerDadosDoDisco(&disco, nomeArquivo3, NULL));

    removerDadosDoDisco(&disco, nomeArquivo2);

    char* nomeArquivo4 = "Teste4.txt";
    unsigned char dados4[] = {0x45, 0x78, 0x65, 0x6D, 0x70, 0x6C, 0x6F, 0x20, 0x64, 0x65, 0x20, 0x61, 0x72, 0x71, 0x75, 0x69, 0x76, 0x6F, 0x20, 0x65, 0x6D, 0x20, 0x62, 0x79, 0x74, 0x65, 0x73};
    int tamanhoDados4 = sizeof(dados4);
    adicionarDadosAoDisco(&disco, nomeArquivo4, dados4, tamanhoDados4);
    printf("%s\n", lerDadosDoDisco(&disco, nomeArquivo4, NULL));

    return 0;
}

