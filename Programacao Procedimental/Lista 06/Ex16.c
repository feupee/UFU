#include <stdio.h>

    struct dados{
        char compromisso[60];
        struct data{
            int dia, mes, ano;
        };
    };

int main(){

    int M, A;
    struct dados c[5];
    int i;

    for(i = 0; i < 5; i++){
        printf("Digite o compromisso: ");
        setbuf(stdin, NULL);
        fgets(c[i].compromisso, 60, stdin);
        printf("Digite o dia: ");
        scanf("%d", &c[i].dia);
        printf("Digite o mes: ");
        scanf("%d", &c[i].mes);
        printf("Digite o ano: ");
        scanf("%d", &c[i].ano);
    }

    printf("\nDigite o ano para pesquisa: ");
    scanf("%d", &A);
    printf("Digite o mes para pesquisa: ");
    scanf("%d", &M);

    while(M != 0){

        for(i = 0; i < 5; i++){
            if(c[i].ano == A && c[i].mes == M){
                printf("O compromisso: %s", c[i].compromisso);
            }
        }

        printf("\nDigite o ano para pesquisa: ");
        scanf("%d", &A);
        printf("Digite o mes para pesquisa: ");
        scanf("%d", &M);
    }

    return 0;
}