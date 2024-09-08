#include "ListaDupla.h"

typedef struct no{
    Aluno valor;
    struct no *prox;
    struct no *ant;
}No;

typedef struct lista {
    No *inicio;
}Lista;

Lista *criar() {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l; // Corrigir o retorno para retornar o ponteiro para a lista.
}

void limpar(Lista *l) {
    while(listaVazia(l) != 0){
        removerInicio(l);
    }
        free(l);
        l = NULL;
}

int tamanho(Lista *l){
    if(l == NULL) return 2;
    No *no = l->inicio;
    int cont = 0;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int listaVazia(Lista *l) {
    if (l->inicio == NULL) {
        return 1; // Retorna 1 se a lista estiver vazia.
    } else {
        return 0; // Retorna 0 se a lista não estiver vazia.
    }
}

//Varia com o tamanho da sua lista
/*int listaCheia(Lista *l){
    return 1;
}
*/

int inserirInicio(Lista *l, Aluno it){
    if(l == NULL) return 2;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = l->inicio;
    no->ant = NULL;
    if(l->inicio != NULL){
        l->inicio->ant = no;
        l->inicio = no;
    }
    return 0;
}

int inserirFim(Lista *l, Aluno it){
    if(l == NULL) return 2;
    if(listaVazia(l) == 0)
        return inserirInicio(l, it);
    No *noLista = l->inicio;
    while(noLista->prox != NULL)
        noLista = noLista->prox;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = NULL;
    no->ant = noLista;
    noLista->prox = no;
    return 0;
}

int inserirPos(Lista *l, int pos, Aluno it){
    if(l == NULL) return 2;
    if((listaVazia(l) == 0) || (pos == 0)){
        return inserirInicio(l,it);
    }
        No *nl = l->inicio;
    while((nl->prox !=NULL) && (pos > 1)) {
        nl = nl->prox;
        pos--;
    } 
    No *n = (No*)malloc(sizeof(No));
    n->valor = it;
    n->ant = nl;
    n->prox = nl->prox;
    nl->prox = n;
    if (n->prox != NULL) n->prox->ant=n;
    return 0;
}

int removerInicio(Lista*l){
    if (l == NULL) return 2;
    if (listaVazia(l) == 0)return 1;
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    if (l->inicio != NULL)
    l->inicio->ant =NULL;
    free(noLista);
    return 0;
}

int removerFim(Lista *l){
    if (l == NULL) return 2;
    if (listaVazia(l) == 0)return 1;
    No *noLista = l->inicio;
    while (noLista->prox!=NULL)
    noLista = noLista->prox;
    if (noLista->ant ==NULL)
    l->inicio = NULL;
    else
    noLista->ant->prox=NULL;
    free(noLista);
return 0;
}

//Exercício A

//1
int cadastrarAluno(Lista *l) {
    if (l == NULL) return 2;

    No *n = (No*)malloc(sizeof(No));

    printf("Nome: ");
    fflush(stdin);
    fgets(n->valor.nome, sizeof(n->valor.nome), stdin);

    printf("Matricula: ");
    fflush(stdin);
    scanf("%d", &n->valor.mat);

    printf("Nota: ");
    fflush(stdin);
    scanf("%f", &n->valor.n1);

    if (listaVazia(l) == 1) { 
        n->ant = NULL;
        n->prox = NULL;
        l->inicio = n; 
    } else {
        No *nl = l->inicio;
        while (nl->prox != NULL) {
            nl = nl->prox;
        }
        nl->prox = n;
        n->ant = nl; 
        n->prox = NULL;
    }

    return 0; 
}

void mostrar(Lista *l){
    if (l == NULL) {
        printf("Lista invalida.\n");
        return;
    }

    if (listaVazia(l)) {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("Lista de Alunos:\n");
    No *noLista = l->inicio;
    
    while (noLista != NULL) {
    printf("\n"); 
    printf("Nome: %s", noLista->valor.nome);
    printf("Matricula: %d\n", noLista->valor.mat);
    printf("Nota: %.2f\n", noLista->valor.n1);
    printf("\n"); 
    noLista = noLista->prox;
    }
}


void RemoverAluno(Lista *l, int mat){
    if (l == NULL){ 
        printf("Lista Invalida"); 
        return;
    }
    if (listaVazia(l)){ 
        printf("Lista Vazia"); 
        return;
    }

    No *noLista = l->inicio;

    while (noLista != NULL) {
        if (noLista->valor.mat == mat) {
            
            if (noLista->ant != NULL) {
                noLista->ant->prox = noLista->prox;
            } else {
                l->inicio = noLista->prox;
            }
            
            if (noLista->prox != NULL) {
                noLista->prox->ant = noLista->ant;
            }
            
            free(noLista); 
            return; 
        }
        
        noLista = noLista->prox;
    }

    printf("Aluno nao encontrado\n");
    return;
    
}

void maiorNota(Lista *l){
    if (l == NULL){ 
        printf("Lista Invalida\n"); 
        return;
    }
    if (listaVazia(l)){ 
        printf("Lista Vazia\n"); 
        return;
    }
    No *noLista = (No *)malloc(sizeof(No));
    int maior = noLista->valor.n1;
    noLista = l->inicio;
    while(noLista != NULL){
        if(noLista->prox == NULL){
            break;
        }else{
            if(maior < noLista->valor.n1){
                maior = noLista->valor.n1;
            }
        }
        noLista = noLista->prox;
    }
    
    printf("Aluno com maior nota eh: ");
    printf("Nome: %s", noLista->valor.nome);
    printf("Matricula: %d\n", noLista->valor.mat);
    printf("Nota: %.2f\n", noLista->valor.n1);
    return;
}

void removerTodos(Lista *l){
    if (l == NULL){ 
        printf("Lista Invalida\n"); 
        return;
    }
    if (listaVazia(l)){ 
        printf("Lista Vazia\n"); 
        return;
    }
    No *noLista = l->inicio;
    
    while (noLista != NULL) {
        No *temp = noLista;
        noLista = noLista->prox;
        free(temp); // Libera a memória do nó atual.
    }
    
    l->inicio = NULL; // Define o início da lista como NULL, indicando que a lista está vazia.
}


//Fim Exercício A



//Exercício B

int trocarPosicoes(Lista *l, int pos1, int pos2) {
    if (l == NULL) return -1; // Código de erro para lista inválida.
    
    int tamanhoLista = tamanho(l);

    if (pos1 < 0 || pos1 >= tamanhoLista || pos2 < 0 || pos2 >= tamanhoLista) {
        return -2; // Código de erro para posições inválidas.
    }

    // Encontrar os nós correspondentes às posições pos1 e pos2.
    No *no1 = l->inicio;
    No *no2 = l->inicio;

    for (int i = 0; i < pos1; i++) {
        no1 = no1->prox;
    }

    for (int i = 0; i < pos2; i++) {
        no2 = no2->prox;
    }

    // Trocar os elementos dos nós.
    Aluno temp = no1->valor;
    no1->valor = no2->valor;
    no2->valor = temp;

    return 0; // Operação de troca bem-sucedida.
}


//Exercício C

// Função para verificar se duas listas têm os mesmos elementos em igual quantidade
int compararListas(Lista* lista1, Lista* lista2) {
    if (lista1 == NULL || lista2 == NULL) {
        return -1; // Código de erro para listas inválidas.
    }

    int tamanho1 = tamanho(lista1);
    int tamanho2 = tamanho(lista2);

    if (tamanho1 != tamanho2) {
        return 1; // As listas têm tamanhos diferentes, portanto não podem ser iguais.
    }

    // Verifique se os elementos das duas listas são os mesmos em ordem correspondente.
    No* noLista1 = lista1->inicio;
    No* noLista2 = lista2->inicio;

    while (noLista1 != NULL && noLista2 != NULL) {
        if (noLista1->valor.mat != noLista2->valor.mat) {
            return 1; // Encontrou diferença entre as listas.
        }

        noLista1 = noLista1->prox;
        noLista2 = noLista2->prox;
    }

    // Se chegou até aqui, as listas são iguais.
    return 0;
}

//Exercício D

void removerRepeticoes(Lista* l) {
    if (l == NULL) {
        printf("Lista Invalida\n");
        return;
    }
    if (listaVazia(l)) {
        printf("Lista Vazia\n");
        return;
    }

    No* noAtual = l->inicio;

    while (noAtual != NULL) {
        No* noComparacao = noAtual->prox;
        while (noComparacao != NULL) {
            if (noAtual->valor.mat == noComparacao->valor.mat) {
                // Elemento repetido encontrado, remova-o.
                No* temp = noComparacao;
                noComparacao = noComparacao->prox;

                if (temp->ant != NULL) {
                    temp->ant->prox = temp->prox;
                } else {
                    l->inicio = temp->prox;
                }

                if (temp->prox != NULL) {
                    temp->prox->ant = temp->ant;
                }

                free(temp);
            } else {
                noComparacao = noComparacao->prox;
            }
        }
        noAtual = noAtual->prox;
    }
}
