#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct lista Lista;

typedef struct clientes
{
    char usuario[50];
    char password[50];
    char nome[50];
    char email[50];
    
}Clientes;

typedef struct pratos
{
    float Valor_Monetario;
    char Nome_Prato[20];
}Pratos;

typedef struct restaurantes
{
    Pratos *Valor;
    int Quantidade_Pratos;
    char Categoria[30];
    char Nome_Restaurante[20];
}Restaurantes;

Lista *Criar();
void Limpar(Lista *l);
void Mostrar_Restaurante(Restaurantes A);
int Inserir_Inicio(Lista *l, Restaurantes A);
int Inserir_Fim(Lista *l, Restaurantes A);
int Inserir_Posicao(Lista *l, Restaurantes A,int pos);
int Remover_Inicio(Lista *l);
int Remover_Fim(Lista *l);
int Remover_Posicao(Lista *l, int pos);
int Remover_Item(Lista *l, Restaurantes A);
int Lista_Vazia (Lista *l);
int Adicionar_Restaurante (Lista *l);
int Adicionar_Cliente (Lista *l);
void Cadastrar_Cliente();
int Fazer_Login();
void Sobre();
void CenterText(const char *text);
void Menu_Login(Lista *l, Restaurantes A);
void Pesquisar_Restaurante(Lista *l, int *sucesso_compra);
void Mostrar_Categorias (Lista *l);
int Mostrar_Por_Categoria (Lista *l, char categoria[]);
void Mostrar_Por_Nome(Lista *l, char restaurante_digitado[]);
float quantidade_pedidos( Lista *l, char restaurante_digitado[], char prato_digitado[]);
int finalizador(int fim_compra);
void mostrar_carrinho(float preco_total);
void CenterText_Aux(const char *text, int offsetX, int offsetY);
void printTextAtPosition(int x, int y, const char *text);
void coletarTexto(int limite, char *varDestino);
void Status_Pedido(int sucesso_compra);
#endif // LISTA_H_INCLUDED