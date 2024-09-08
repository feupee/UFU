#include "Lista.h"
#include "Lista.c"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    char Escolha;
    int Login;
    Lista *l;
    Restaurantes A;

    l = Criar();

    do
    {
        system("cls");
        CenterText_Aux("::::    :::     :::        :::    :::  ::::::::  :::::::::      :::    \n",0,10);
        CenterText_Aux(":+:+:   :+:   :+: :+:      :+:    :+: :+:    :+: :+:    :+:   :+: :+:  \n",0,0);
        CenterText_Aux(":+:+:+  +:+  +:+   +:+     +:+    +:+ +:+    +:+ +:+    +:+  +:+   +:+ \n",0,0);
        CenterText_Aux("+#+ +:+ +#+ +#++:++#++:    +#++:++#++ +#+    +:+ +#++:++#:  +#++:++#++:\n",0,0);
        CenterText_Aux("+#+  +#+#+# +#+     +#+    +#+    +#+ +#+    +#+ +#+    +#+ +#+     +#+\n",0,0);
        CenterText_Aux("#+#   #+#+# #+#     #+#    #+#    #+# #+#    #+# #+#    #+# #+#     #+#\n",0,0);
        CenterText_Aux("###    #### ###     ###    ###    ###  ########  ###    ### ###     ###\n",0,0);
        printf("\n");
        CenterText_Aux("+------------------------------+\n",0,0);
        CenterText_Aux("|          Bem-Vindo!          |\n",0,0);
        CenterText_Aux("|                              |\n",0,0);
        CenterText_Aux("| [1] Entrar                   |\n",0,0);
        CenterText_Aux("| [2] Cadastar Cliente         |\n",0,0);
        CenterText_Aux("| [3] Cadastrar Restaurante    |\n",0,0);
        CenterText_Aux("| [4] Sobre                    |\n",0,0);
        CenterText_Aux("| [5] Sair                     |\n",0,0);
        CenterText_Aux("|                              |\n",0,0);
        CenterText_Aux("+------------------------------+\n",0,0);
        CenterText_Aux("Escolha uma opcao: ",0,1);
        scanf("%c", &Escolha);
        fflush(stdin);

        switch (Escolha)
        {
        case '1':
            system("cls");
            Login = Fazer_Login();
            if (Login == 0)
                Menu_Login(l, A);
                break;
        case '2':
            system("cls");
            Cadastrar_Cliente();
            break;
        case '3':
            system("cls");
            Adicionar_Restaurante(l);
            break;
        case '4':
            system("cls");
            Sobre();
            break;
        case '5':
            system("cls");
            CenterText("Saindo...\n");
            Sleep(2000);
            exit(1);
        default:
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    }
    while (Escolha != '5');

    return 0;
}
