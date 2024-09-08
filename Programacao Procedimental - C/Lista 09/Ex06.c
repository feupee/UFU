#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que simule a memória de um computador: o usuário
irá especificar o tamanho da memória, ou seja, quantos bytes serão
alocados do tipo inteiro. Para tanto, a memória solicitada deve ser um
valor múltiplo do tamanho do tipo inteiro. Em seguida, o usuário terá 2
opções: inserir um valor em uma determinada posição ou consultar o
valor contido em uma determinada posição. A memória deve iniciar com
todos os dados zerados.*/

int main(){

    int N, *vetor, opcao, posicao, novo_valor;

    printf("Digite um valor de memoria inteiro: ");
    scanf("%d",&N);

    if(N % 4 != 0){
        printf("Valor de memoria errado\nDigite novamente: ");
        scanf("%d",&N);
    }

    for (int i = 0; i < N; i++)
    {
        *(vetor+i) = 0;
    }

    do{
    printf("O que deseja fazer?\n0 - Inserir um valor em uma determinada posicao\n1 - consultar o valor contido em uma determina posicao\n2 - Sair");
    scanf("%d", opcao);

    if(opcao != 1 && opcao != 2 && opcao != 0){
        printf("opcao invalida\nDigite novamente: ");
        scanf("%d", &opcao);
    }

    if (opcao == 1)
        {
            printf("Digite o valor que sera atribuido: ");
            scanf("%d", &novo_valor);
            printf("Digite a posicao desse valor: ");
            scanf("%d", &posicao);

            *(vetor+posicao) = novo_valor;
        }
        else if (opcao == 2)
        {
            printf("Digite a posicao que deseja checar: ");
            scanf("%d", &posicao);

            printf("%d", *(vetor+posicao));
        }
        else if (opcao == 0)
        {
            break;
        }

    }while(opcao != 0);
    
    free(vetor);
    return 0;
}