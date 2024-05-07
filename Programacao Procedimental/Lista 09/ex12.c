#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*.Considere um cadastro de produtos de um estoque, com as seguintes
informações para cada produto:
 Código de identificação do produto: representado por um valor
inteiro
 Nome do produto: com até 50 caracteres
 Quantidade disponível no estoque: representado por um número
inteiro
 Preço de venda: representado por um valor real
a) Defina uma estrutura, denominada produto, que tenha os campos
apropriados para guardar as informações de um produto;
b) Crie um conjunto de N produtos (N é um valor fornecido pelo usuário)
e peca ao usuário para entrar com as informações de cada produto;
c) Encontre o produto com o maior preço de venda;
d) Encontre o produto com a maior quantidade disponível no estoque.*/

typedef struct produtos{
    int id, qtdEstoque;
    char nome[50];
    float precoVenda;
}produtos;

int main(){
    int n, idMaiorPreco, idMaiorQtd, maiorQtd;
    char nomeMaiorPreco[50], nomeMaiorQtd[50];
    float maiorPreco;
    produtos *produto;
    

    printf("Insira a quantidade de produtos a adicionar: ");
    scanf("%d",&n);

    produto = (produtos*)malloc(n * sizeof(produto));
    for(int i = 0; i < n; i++){
        printf("\n");
        printf("- Produto %d\n", i+1);
        printf("ID: ");
        scanf("%d", &produto[i].id);
        printf("Nome: ");
        setbuf(stdin, NULL);
        fgets(produto[i].nome,50,stdin);
        printf("Qtd no estoque: ");
        scanf("%d", &produto[i].qtdEstoque);
        printf("Preco de venda: ");
        scanf("%f", &produto[i].precoVenda);

        if(i == 0){
            idMaiorPreco = produto[i].id;
            idMaiorQtd = produto[i].qtdEstoque;
            strcpy(nomeMaiorPreco, produto[i].nome);
            strcpy(nomeMaiorQtd, produto[i].nome);
            maiorQtd = produto[i].qtdEstoque;
            maiorPreco = produto[i].precoVenda;
        }if(produto[i].precoVenda > maiorPreco){
            idMaiorPreco = produto[i].id;
            strcpy(nomeMaiorPreco, produto[i].nome);
        }if(produto[i].qtdEstoque > maiorQtd){
            idMaiorQtd = produto[i].id;
            strcpy(nomeMaiorQtd, produto[i].nome);
        }
    }

    printf("\n");
    printf("- Produto com maior quantidade disponivel -\n");
    printf("ID: %d\n", idMaiorQtd);
    printf("Nome: %s\n", nomeMaiorQtd);
    printf("\n");
    printf("- Produto com maior preco de venda -\n");
    printf("ID: %d\n", idMaiorPreco);
    printf("Nome: %s\n", nomeMaiorPreco);

    return 0;
}