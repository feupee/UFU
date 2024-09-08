#define MAX 100

typedef struct aluno {
    int mat;
    char nome[30];
    float n1;
} Aluno;

typedef struct lista Lista;
Lista *criar();
void limpar(Lista *l);
int inserirInicio(Lista *l, Aluno it);
int inserirFim(Lista *l, Aluno it);
int removerInicio(Lista *l);
int removerFim(Lista *l);
int buscarItemChave(Lista *l, int chave, Aluno *retorno);
int listaVazia(Lista *l);
int listaCheia(Lista *l);
int tamanho(Lista *l);
void mostrar(Lista *l);

//Exercício A

int inserirPosicao(Lista *l, Aluno it, int pos);
int removerPosicao(Lista *l, int pos);
int removerItem(Lista *l, Aluno it);
int buscarPosicao(Lista *l, int posicao, Aluno *it);

//Exercício B

int ContemItem(Lista *l, Aluno it);
Lista *Reversa(Lista *l);
int contaItem(Lista *l, Aluno it);

//Exercício C

Lista *criar2(int capacidadeInicial);
int inserirInicio2(Lista *l, Aluno it);

//Exercício D

typedef struct lista2 { 
    int total;
    int capacidade;
    Aluno *valores;
} Lista2;

Lista2 *cria2(); 
static int redimensionar(Lista2 *l); 
int inserirFim2(Lista2 *l, Aluno it); 