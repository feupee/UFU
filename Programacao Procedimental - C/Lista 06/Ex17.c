#include <stdio.h>

    struct eletro{
        char nome[15];
        float potencia;
        float tempoativo;
        int consumo;
    };

int main(){
    
    struct eletro c[5];
    int i, t;
    float soma = 0;
    float porcentagem;
    
    for(i = 0; i < 2; i++){
        printf("Digite o nome: ");
        setbuf(stdin, NULL);
        fgets(c[i].nome, 15, stdin);
        printf("Digite a potencia em kW: ");
        scanf("%f", &c[i].potencia);
        printf("Digite o tempo ativo em horas: ");
        scanf("%f", &c[i].tempoativo);

        c[i].consumo = (c[i].potencia * c[i].tempoativo);
    }

    printf("Digite um tempo t(dias): ");
    scanf("%d", &t);

    for(i = 0; i < 2; i++){
        c[i].consumo = c[i].consumo * t;
        soma += c[i].consumo;
        printf("O eletrodomestico: %s", c[i].nome);
        printf("Gasta em %i dia: %i", t, c[i].consumo);
        printf("\n");
    }
    for(i = 0; i < 2; i++){
        porcentagem = c[i].consumo/soma*100;
        printf("Em porcentagem o eletrodomestico %s gasta: %.2f por cento", c[i].nome, porcentagem);
        printf("\n");
    }

        



    return 0;
}