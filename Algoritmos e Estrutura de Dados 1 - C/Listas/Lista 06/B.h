typedef struct {
    int *elementos;
    int tamanho;
} Conjunto;

Conjunto criarConjunto();
int pertenceConjunto(const Conjunto *conjunto, int elemento);
void inserirElemento(Conjunto *conjunto, int elemento);
void removerElemento(Conjunto *conjunto, int elemento);
Conjunto uniaoConjuntos(const Conjunto *conjunto1, const Conjunto *conjunto2);
Conjunto intersecaoConjuntos(const Conjunto *conjunto1, const Conjunto *conjunto2);
Conjunto diferencaConjuntos(const Conjunto *conjunto1, const Conjunto *conjunto2);
void liberarConjunto(Conjunto *conjunto);
void exibirConjunto(const Conjunto *conjunto);