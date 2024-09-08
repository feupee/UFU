#define MAX 100

// Define a estrutura Aluno
typedef struct aluno {
    int mat;
    char nome[50];
    float n1;
} Aluno;

// Definição da estrutura da lista
typedef struct lista Lista;

// Protótipos das funções
Lista* criar();
void limpar(Lista* l);
int inserirInicio(Lista* l, Aluno it);
int inserirFim(Lista* l, Aluno it);
int inserirPosicao(Lista* l, Aluno it, int pos);
int removerInicio(Lista* l);
int removerFim(Lista* l);
int removerPosicao(Lista* l, int pos);
int removerItem(Lista* l, int it);
int buscarItemChave(Lista* l, int chave, Aluno* retorno);
int buscarPosicao(Lista* l, int posicao, Aluno* retorno);
int listaVazia(Lista* l);
int listaCheia(Lista* l);
int tamanho(Lista* l);
void mostrar(Lista* l);


//Exercício B

void removerElementoCentral(Lista* l);