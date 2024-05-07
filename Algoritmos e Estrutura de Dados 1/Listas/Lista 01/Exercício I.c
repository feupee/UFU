#include <stdio.h>

typedef struct {
    char titulo[50];
    int anoedi;
    int paginas;
    int preco;
} Livro;

int main(){

    Livro p[5];

    int media = 0;

    for(int i = 0; i < 5; i++){
        fflush(stdin);
        printf("Digite o titulo: ");
        fgets(p[i]. titulo, 50, stdin);
        fflush(stdin);
        printf("Digite o ano de edicao: ");
        scanf("%d", &p[i].anoedi);
        fflush(stdin);
        printf("Digite o numero de paginas: ");
        scanf("%d", &p[i].paginas);
        fflush(stdin);
        printf("Digite o preco: ");
        scanf("%d", &p[i].preco);
        fflush(stdin);

        media += p[i].paginas;
    }

    media /= 5;

    printf("\nA media do numero de paginas do livros eh: %d", media); 

    return 0;
}