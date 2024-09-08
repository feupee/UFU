#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar informações de um cliente
struct Cliente {
    char cpf[12];
    char estadoCivil[20];
    char **filhos;
    int numFilhos;
};

int main() {
    int tamanhoVetor;
    
    printf("Digite o tamanho do vetor de clientes: ");
    scanf("%d", &tamanhoVetor);

    // Alocando espaço para o vetor de clientes
    struct Cliente *vetorClientes = (struct Cliente *)malloc(tamanhoVetor * sizeof(struct Cliente));
    if (vetorClientes == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    int opcao;
    int numClientes = 0;

    do {
        printf("\nOpções:\n");
        printf("1. Inserir cliente\n");
        printf("2. Remover cliente\n");
        printf("3. Mostrar CPFs dos clientes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Inserir cliente
                if (numClientes < tamanhoVetor) {
                    struct Cliente novoCliente;

                    printf("CPF: ");
                    scanf("%s", novoCliente.cpf);
                    printf("Estado civil: ");
                    scanf("%s", novoCliente.estadoCivil);

                    printf("Quantidade de filhos: ");
                    scanf("%d", &novoCliente.numFilhos);

                    novoCliente.filhos = (char **)malloc(novoCliente.numFilhos * sizeof(char *));
                    for (int i = 0; i < novoCliente.numFilhos; i++) {
                        novoCliente.filhos[i] = (char *)malloc(50 * sizeof(char));
                        printf("Nome do filho %d: ", i + 1);
                        scanf("%s", novoCliente.filhos[i]);
                    }

                    vetorClientes[numClientes] = novoCliente;
                    numClientes++;
                } else {
                    printf("O vetor de clientes está cheio.\n");
                }
                break;

            case 2: // Remover cliente
                if (numClientes > 0) {
                    int posicao;
                    printf("Digite a posição do cliente a ser removido: ");
                    scanf("%d", &posicao);

                    if (posicao >= 0 && posicao < numClientes) {
                        for (int i = posicao; i < numClientes - 1; i++) {
                            vetorClientes[i] = vetorClientes[i + 1];
                        }
                        numClientes--;

                        // Liberando memória alocada para os filhos do cliente removido
                        for (int i = 0; i < vetorClientes[posicao].numFilhos; i++) {
                            free(vetorClientes[posicao].filhos[i]);
                        }
                        free(vetorClientes[posicao].filhos);
                    } else {
                        printf("Posição inválida.\n");
                    }
                } else {
                    printf("Não há clientes para remover.\n");
                }
                break;

            case 3: // Mostrar CPFs dos clientes
                printf("CPFs dos clientes:\n");
                for (int i = 0; i < numClientes; i++) {
                    printf("%s\n", vetorClientes[i].cpf);
                }
                break;

            case 0: // Sair
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    // Liberando memória alocada para os filhos dos clientes
    for (int i = 0; i < numClientes; i++) {
        for (int j = 0; j < vetorClientes[i].numFilhos; j++) {
            free(vetorClientes[i].filhos[j]);
        }
        free(vetorClientes[i].filhos);
    }

    // Liberando memória alocada para o vetor de clientes
    free(vetorClientes);

    return 0;
}