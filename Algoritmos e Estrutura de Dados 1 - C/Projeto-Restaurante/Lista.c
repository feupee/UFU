#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include "Lista.h"

typedef struct no
{
    Restaurantes Valor;
    struct no *prox;
}No;

typedef struct lista
{
    No *Inicio;
    char **Categoria;
    int Quantidade_Categorias;
}Lista;

Lista *Criar()
{
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->Inicio = NULL;
    l->Categoria = (char**) malloc (sizeof(char*));
    l->Quantidade_Categorias = 0;
    return l;
}

void Limpar(Lista *l);
//Funcao para Adicionar um restaurante a lista
int Adicionar_Restaurante (Lista *l)
{
    if (l == NULL) return 1;
    int Quantidade_Pratos1;
    int ver =0;
    Restaurantes A;
    CenterText_Aux("+-------------------------------------------+\n",0,18);
    CenterText_Aux("|                Menu de Login              |\n",0,0);
    CenterText_Aux("|                                           |\n",0,0);
    CenterText_Aux("| Nome do Restaurante:                      |\n",0,0);
    CenterText_Aux("| Categoria do Restaurante:                 |\n",0,0);
    CenterText_Aux("| Quantos pratos deseja adicionar:          |\n",0,0);
    CenterText_Aux("|                                           |\n",0,0);
    CenterText_Aux("+-------------------------------------------+\n",0,0);
    CenterText_Aux("",0,-5);
    fgets (A.Nome_Restaurante, 19, stdin);
    CenterText_Aux("",5,0);
    fgets (A.Categoria, 29, stdin);
    for (int i = 0 ; i < l->Quantidade_Categorias ; i++)
    {
        if(strcmp(l->Categoria[i], A.Categoria) == 0)
        {
            ver++;
            break;
        }

    }
    if(ver == 0)
    {
        l->Quantidade_Categorias++;
        l->Categoria = (char**) realloc(l->Categoria, sizeof(char*)*l->Quantidade_Categorias);
        l->Categoria[l->Quantidade_Categorias-1] = (char*) malloc (sizeof(char)*strlen(A.Categoria));
        strcpy(l->Categoria[l->Quantidade_Categorias-1], A.Categoria);
    }
    CenterText_Aux("",12,0);
    char Quantidade_Pratos2[50];
    coletarTexto(3, Quantidade_Pratos2);
    Quantidade_Pratos1 = atoi(Quantidade_Pratos2);
    A.Valor = (Pratos *) malloc (Quantidade_Pratos1*sizeof(Pratos));//Aloca um vetor de pratos de acordo com a quantidade desejada
    
    for (int i = 0; i < Quantidade_Pratos1; i++)
    {
        char valor[50];
        CenterText_Aux("",-23,0);
        CenterText_Aux("| Nome do prato  :                          |\n",0,0);
        CenterText_Aux("|                                           |\n",0,0);
        CenterText_Aux("+-------------------------------------------+\n",0,0);
        CenterText_Aux("",-7,-3);
        printf("%i", i+1);
        CenterText_Aux("",-4,0);
        fgets (A.Valor[i].Nome_Prato, 19, stdin);
        fflush(stdin);
        CenterText_Aux("",-23,0);
        
        CenterText_Aux("| Valor do prato  :                         |\n",0,0);
        CenterText_Aux("|                                           |\n",0,0);
        CenterText_Aux("+-------------------------------------------+\n",0,0);
        CenterText_Aux("",-6,-3);
        printf("%i", i+1);
        CenterText_Aux("",-3,0); 
        scanf ("%f", &((A.Valor)[i]).Valor_Monetario);
        fflush(stdin);
    }
    A.Quantidade_Pratos = Quantidade_Pratos1;
    Inserir_Inicio(l, A);

    CenterText_Aux("+-------------------------------------+\n",0,3);
    CenterText_Aux("| Restaurante cadastrado com sucesso! |\n",0,0);
    CenterText_Aux("+-------------------------------------+\n",0,0);
    CenterText_Aux("",0,0);
    Sleep(2000);
    return 0;
}

int Inserir_Inicio (Lista *l, Restaurantes A)
{
    if (l == NULL) return 1;
    No *no = (No*)malloc(sizeof(No));
    no->Valor = A;
    no->prox = l->Inicio;
    l->Inicio = no;
    return 0;
}

int Inserir_Fim(Lista *l, Restaurantes A)
{
    if (l == NULL) return 1;
    if (Lista_Vazia(l) == 0) return Inserir_Inicio(l,A);
    No *noLista = l->Inicio;
    while (noLista!= NULL)
        noLista = noLista->prox;
    No *no = (No*)malloc(sizeof(No));
    no->Valor = A;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int Remover_Restaurante(Lista *l, char Nome[20]);

int Lista_Vazia(Lista *l)
{
    if (l == NULL) return 2;
    if (l -> Inicio == NULL) return 0;
    return 1;
}

//Funcao auxiliar para mostrar cada restaurante da lista
void Mostrar_Restaurante(Restaurantes A)
{
    CenterText("Nome do Restaurante: "); printf("%s", A.Nome_Restaurante);
}

//Funcao para mostrar a Lista

void Mostrar_Categorias (Lista *l)
{

    for(int i = 0 ; i < l->Quantidade_Categorias ; i++)
    {
        CenterText_Aux("",0,0); printf("%s \n", l->Categoria[i]);
    }
}

int Mostrar_Por_Categoria (Lista *l, char categoria[])
{
    if (l == NULL) return 1;
    No* cl = l->Inicio;
    while(cl!=NULL)
    {
        if (strcmp(cl->Valor.Categoria, categoria) == 0){
            Mostrar_Restaurante(cl->Valor);
        }
        cl = cl->prox;
    }
    return 0;
}

void Mostrar_Pratos (Restaurantes A)
{
    for (int i = 0 ; i < A.Quantidade_Pratos ; i++)
    {
        CenterText_Aux("", 0, 0);
        CenterText("Nome: "); printf("%s", A.Valor[i].Nome_Prato);
        CenterText("Valor: "); printf("R$ %.2f\n", A.Valor[i].Valor_Monetario);
        printf("\n");
    }
}


void Mostrar_Por_Nome (Lista *l, char restaurante_digitado[])
{
    No* cl = l->Inicio;
    while(cl!=NULL)
    {
        if (strcmp(cl->Valor.Nome_Restaurante, restaurante_digitado) == 0){
            Mostrar_Pratos(cl->Valor);
            setbuf(stdin,NULL);
        }
        cl = cl->prox;
    }
    CenterText("\n");
}

float quantidade_pedidos(Lista *l, char restaurante_digitado[], char prato_digitado[])
{
    No* cl = l->Inicio;
    int i = 0, quantidade = 0;
        while(cl!=NULL)
        {
            if (strcmp(cl->Valor.Nome_Restaurante, restaurante_digitado ) == 0){
                for(i = 0; i < cl->Valor.Quantidade_Pratos; i++) {
                    if(strcmp((cl->Valor).Valor[i].Nome_Prato, prato_digitado) == 0) {
                        CenterText("Quantidade: ");
                        scanf("%d", &quantidade);
                        return quantidade*((cl->Valor).Valor[i].Valor_Monetario);
                    }
                }
            }
            cl = cl->prox;
        }
        CenterText("\n");
}

//funcao para finalizar pedido
int finalizador(int fim_compra)
{
            CenterText("Deseja finalizar seu pedido?\n");
            CenterText("1-Sim\n");
            CenterText("0-Nao\n");
            scanf("%d", &fim_compra);
    return fim_compra;
}

void mostrar_carrinho(float preco_total)
{
    CenterText("+----------+");
    CenterText("VALOR TOTAL: ");
    printf("R$ %.2f\n", preco_total);
    CenterText("+----------+");
}

Clientes bancoDeClientes[20]; //Vetor estatico de clientes criado previamente
int numClientes = 0;

// Funcao para cadastrar um novo cliente
void Cadastrar_Cliente() {
        int contador = 0;
        char aux[50];
        system("cls");
        CenterText_Aux("+-------------------------------------------+\n",0,18);
        CenterText_Aux("|              Menu de Cadastro             |\n",0,0);
        CenterText_Aux("|                                           |\n",0,0);
        CenterText_Aux("| Usuario:                                  |\n",0,0);
        CenterText_Aux("| Senha:                                    |\n",0,0);
        CenterText_Aux("| E-mail:                                   |\n",0,0);
        CenterText_Aux("| Nome Completo:                            |\n",0,0);
        CenterText_Aux("|                                           |\n",0,0);
        CenterText_Aux("+-------------------------------------------+\n",0,0);
        CenterText_Aux("",-12,-6);
        coletarTexto(32, bancoDeClientes[numClientes].usuario);
        CenterText_Aux("",-14,0);
        coletarTexto(34, bancoDeClientes[numClientes].password);
        CenterText_Aux("",-13,0);
        coletarTexto(33, bancoDeClientes[numClientes].email);
        CenterText_Aux("",-6,0);
        coletarTexto(26, bancoDeClientes[numClientes].nome);

        system("cls");
        for (int i = 0; i < numClientes; i++) {
            if (strcmp(bancoDeClientes[numClientes].usuario, bancoDeClientes[i].usuario) == 0) {
                CenterText_Aux("+------------------------------+\n",0,18);
                CenterText_Aux("|   Usuario ja foi escolhido!  |\n",0,0);
                CenterText_Aux("+------------------------------+\n",0,0);
                CenterText_Aux("",0,0);
                Sleep(2000);
                return;
            }
        }

        CenterText_Aux("+------------------------------+\n",0,18);
        CenterText_Aux("|      Cliente Cadastrado!     |\n",0,0);
        CenterText_Aux("+------------------------------+\n",0,0);
        CenterText_Aux("",0,0);
        numClientes++;
        Sleep(3000); // Pausa
}

// Função para fazer login de um cliente
int Fazer_Login() {
    int tentativas_restantes = 3;

    while (tentativas_restantes > 0) {
        char usuario[50];
        char senha[50];

        system("cls");
        CenterText_Aux("+-------------------------------------------+\n",0,18);
        CenterText_Aux("|                Menu de Login              |\n",0,0);
        CenterText_Aux("|                                           |\n",0,0);
        CenterText_Aux("| Usuario:                                  |\n",0,0);
        CenterText_Aux("| Senha:                                    |\n",0,0);
        CenterText_Aux("|                                           |\n",0,0);
        CenterText_Aux("+-------------------------------------------+\n",0,0);
        CenterText_Aux("",-12,-4);
        coletarTexto(32, usuario);
        CenterText_Aux("",-14,0);
        coletarTexto(34, senha);

        for (int i = 0; i < numClientes; i++) {
            if (strcmp(usuario, bancoDeClientes[i].usuario) == 0 && strcmp(senha, bancoDeClientes[i].password) == 0) {
                CenterText_Aux("Login bem-sucedido! Bem-vindo,",0,3);
                printf("%s.\n", bancoDeClientes[i].nome);
                CenterText_Aux("",0,0);
                Sleep(2000);
                return 0; // Login bem-sucedido
            }
        }

        CenterText_Aux("Usuario ou senha incorretos. Tente novamente. Tentativas restantes: ",0,3);
        printf("%d\n", tentativas_restantes - 1);
        CenterText_Aux("",0,0);
        Sleep(2000);

        tentativas_restantes--;
    }

    CenterText_Aux("Numero maximo de tentativas excedido.\n",0,1);
    Sleep(2000);
    return 1; // Login falhou
}


void Sobre()
{
    char choice;
    do{
    system("cls");
    fflush(stdin);
    CenterText_Aux("+------------------------------+\n",0,18);
    CenterText_Aux("|             SOBRE            |\n",0,0);
    CenterText_Aux("|                              |\n",0,0);
    CenterText_Aux("| Autores:  Andre Polimanti,   |\n",0,0);
    CenterText_Aux("|           Bernardo Tibaldi,  |\n",0,0);
    CenterText_Aux("|           Caio Henrique,     |\n",0,0);
    CenterText_Aux("|           Felipe Santos      |\n",0,0);
    CenterText_Aux("| [1] Sair                     |\n",0,0);
    CenterText_Aux("|                              |\n",0,0);
    CenterText_Aux("+------------------------------+\n",0,0);
    printf("\n");
    CenterText_Aux("Escolha uma opcao: ",0,0);
    scanf(" %c", &choice);
    fflush(stdin);
    }while(choice != '1');
}

//Funcao para centralizar o texto na tela
void CenterText(const char *text) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(console, &consoleInfo);
    int textLength = strlen(text);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
    int posX = (consoleWidth - textLength) / 2;
    int posY = consoleInfo.dwCursorPosition.Y;
    COORD newPos;
    newPos.X = posX;
    newPos.Y = posY;
    SetConsoleCursorPosition(console, newPos);
    printf("%s", text);
}

//Funcao para centralizar o texto na tela
void CenterText_Aux(const char *text, int offsetX, int offsetY) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(console, &consoleInfo);
    int textLength = strlen(text);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
    int posX = (consoleWidth - textLength) / 2 + offsetX;
    int posY = consoleInfo.dwCursorPosition.Y + offsetY; // Ajuste a posição vertical
    COORD newPos;
    newPos.X = posX;
    newPos.Y = posY;
    SetConsoleCursorPosition(console, newPos);
    printf("%s", text);
}

void Menu_Login(Lista *l, Restaurantes A)
{
    char escolha;
    int sucesso_compra = 1;
    do{
        system("cls");
        fflush(stdin);
        CenterText_Aux("::::    :::     :::        :::    :::  ::::::::  :::::::::      :::    \n",0,10);
        CenterText_Aux(":+:+:   :+:   :+: :+:      :+:    :+: :+:    :+: :+:    :+:   :+: :+:  \n",0,0);
        CenterText_Aux(":+:+:+  +:+  +:+   +:+     +:+    +:+ +:+    +:+ +:+    +:+  +:+   +:+ \n",0,0);
        CenterText_Aux("+#+ +:+ +#+ +#++:++#++:    +#++:++#++ +#+    +:+ +#++:++#:  +#++:++#++:\n",0,0);
        CenterText_Aux("+#+  +#+#+# +#+     +#+    +#+    +#+ +#+    +#+ +#+    +#+ +#+     +#+\n",0,0);
        CenterText_Aux("#+#   #+#+# #+#     #+#    #+#    #+# #+#    #+# #+#    #+# #+#     #+#\n",0,0);
        CenterText_Aux("###    #### ###     ###    ###    ###  ########  ###    ### ###     ###\n",0,0);
        printf("\n");
        CenterText_Aux("+------------------------------+\n",0,0);
        CenterText_Aux("|    Gerenciador de Pedidos    |\n",0,0);
        CenterText_Aux("|                              |\n",0,0);
        CenterText_Aux("| [1] Pesquisar por Culinaria  |\n",0,0);
        CenterText_Aux("| [2] Status do Pedido         |\n",0,0);
        CenterText_Aux("| [3] Sair                     |\n",0,0);
        CenterText_Aux("|                              |\n",0,0);
        CenterText_Aux("+------------------------------+\n",0,0);
        CenterText_Aux("Escolha uma opcao: ",0,1);
        scanf ("%c", &escolha);
        fflush(stdin);

        switch (escolha)
        {
        case '1':
            system("cls");
            Pesquisar_Restaurante(l, &sucesso_compra);
            break;
        case '2':
            system("cls");
            Status_Pedido(sucesso_compra);
            sucesso_compra = 1;
            break;
        case '3':
            break;
        default:
            CenterText("Opcao invalida! Tente novamente.");
            break;
        }
    }
    while(escolha != '3');

}


//Menu de pesquisa da culinária, que filtra e mostra os restaurantes e filtra de novo e mostra os pratos daquele restaurante.
void Pesquisar_Restaurante(Lista *l, int *sucesso_compra)
{
    char restaurante_digitado[20];
    char prato_digitado[20];
    char Tipo_Culinaria[30];
    float preco_total = 0, preco;
    int fim_compra = 0;

    CenterText_Aux("", 0, 10);
    CenterText_Aux("Digite o tipo de culinaria dentre as seguintes:\n",0,0);

    Mostrar_Categorias(l);

    CenterText(" ");
    fgets(Tipo_Culinaria, 30, stdin);
    fflush(stdin);

    system("cls");

    Mostrar_Por_Categoria (l, Tipo_Culinaria);

    CenterText("Selecione o restaurante: ");
    fgets(restaurante_digitado, 20, stdin);
    setbuf(stdin,NULL);

    system("cls");

    while(fim_compra != 1) {

    Mostrar_Por_Nome(l, restaurante_digitado);


    CenterText("Selecione o prato: ");
    fgets(prato_digitado, 20, stdin);
    setbuf(stdin, NULL);

    system ("cls");

    preco = quantidade_pedidos(l, restaurante_digitado, prato_digitado);


    preco_total = preco_total + preco;


    fim_compra = finalizador(fim_compra);
    }

    mostrar_carrinho(preco_total);
    *sucesso_compra = 0;
    Sleep(2000);
}

void Status_Pedido(int sucesso_compra) {
    int resposta, tempo = 5;
    if (sucesso_compra == 1) {
        CenterText_Aux("+------------------------------+\n",0,0);
        CenterText_Aux("|      Sem nenhum pedido!      |\n",0,0);
        CenterText_Aux("+------------------------------+\n",0,0);
    }
    
    if(sucesso_compra == 0) 
    {
        CenterText_Aux("+------------------------------+\n",0,0);
        CenterText_Aux("|      Pedido concluido!       |\n",0,0);
        CenterText_Aux("|    Entregador a caminho...   |\n",0,0);
        CenterText_Aux("+------------------------------+\n",0,0);
        Sleep(2000);

        do{
            system ("cls");
           CenterText_Aux("+------------------------------+\n",0,0);
            CenterText_Aux("Tempo Estimado:",-3,0);
            printf("0:0%d\n", tempo);
            CenterText_Aux("+------------------------------+\n",0,0);
            tempo--;
            Sleep(1000);
        } 
        while(tempo > 0);

        system ("cls");

        CenterText_Aux("+------------------------------+\n",0,0);
        CenterText_Aux("|   Seu pedido foi entregue?   |\n",0,0);
        CenterText_Aux("|            1- Sim            |\n",0,0);
        CenterText_Aux("|            2- Nao            |\n",0,0);
        CenterText_Aux("+------------------------------+\n",0,0);
        scanf("%d", &resposta);
        system ("cls");

        if(resposta == 1) 
        {
            CenterText_Aux("+------------------------------+\n",0,0);
            CenterText_Aux("|       Obrigado por pedir     |\n",0,0);
            CenterText_Aux("|            conosco!          |\n",0,0);
            CenterText_Aux("+------------------------------+\n",0,0);
        }
        if(resposta == 2) 
        {
            CenterText_Aux("+------------------------------+\n",0,0);
            CenterText_Aux("|          Tente entrar        |\n",0,0);
            CenterText_Aux("|           em contato:        |\n",0,0);
            CenterText_Aux("|         +55 XXXXX-XXXX       |\n",0,0);
            CenterText_Aux("+------------------------------+\n",0,0);
        }
    }
    Sleep(3000);
}


//Função para imprimir texto em ponto específico
void printTextAtPosition(int x, int y, const char *text) {
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("%s", text);
}

void coletarTexto(int limite, char *varDestino) {
    char aux[50];  // Uma string para armazenar a entrada do usu�rio
    int contador = 0;

    while (1) {
        char ch = getch();

        if (ch == 13) {
            // O usuário pressionou Enter, encerramos o loop
            aux[contador] = '\0';  // Terminamos a string
            break;
        } else if (ch == 8 && contador > 0) {
            // O usuário pressionou Backspace para apagar um caractere
            contador--;
            printf("\b \b"); // Apaga o caractere na tela
        } else if (contador < limite - 1 && isprint(ch)) {
            // Adiciona o caractere à string e o exibe na tela
            aux[contador] = ch;
            putchar(ch);
            contador++;
        }
    }
    printf("\n");

    // Copia o conte�do de 'aux' para a vari�vel de destino
    strcpy(varDestino, aux);
}