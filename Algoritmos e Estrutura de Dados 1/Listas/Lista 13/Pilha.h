#define MAX 100

//Exercício C

typedef struct valor {
    char letra;
} Valor;

typedef struct pilha {
    int topo;
    Valor dados[MAX];
} Pilha;

Pilha *criar();

Pilha *criar();
void mostrar(Pilha *p);
int push(Pilha *p, Aluno it);
int pop(Pilha *p, Aluno *it);
