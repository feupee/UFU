#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main()
{
    Fila *f = criar();
    int op;
    do{

        printf("\n--Menu--\n\n");
        printf("(1) Cadastrar.\n");
        printf("(2) Mostrar senha.\n");
        printf("(0) Sair.\n");
        printf("Digite opcao: ");
        scanf("%d" , &op);

        switch(op){
            case 1:{
                int valor;
                char str[30];
                printf("Digite seu nome completo: ");
                fflush(stdin);
                fgets(str, 100, stdin);
                valor = tamanho(f) +1;
                printf("Sua senha eh: %d\n" , valor);
                inserir(f, valor);
                break;
            }
            case 2:{
                int valor;
                remover2(f, &valor);
                printf("Senha: [%d]\n" , valor);
                break;
            }
            case 0:
                printf("Saindo...");
                break;
            default:
                printf("[ERRO]: opcao invalida!\n");
        }
    }while(op != 0);
    return 0;
}
