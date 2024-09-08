#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Faça um programa que:
a) Peça para o usuário entrar com o nome e a posição (coordenadas X e
Y) de N cidades e as armazene em um vetor de estruturas (N é
informado pelo usuário);
b) Crie uma matriz de distâncias entre cidades de tamanho N x N;
c) Calcule as distâncias entre cada duas cidades e armazene na matriz;
d) Exiba na tela a matriz de distancias obtida;
e) Quando o usuário digitar o número de duas cidades o programa
deverá retornar a distância entre elas.
*/

typedef struct cidades{
    float x, y;
}cidades;

int main(){
    int n, a, b;
    float **distancias;
    cidades *cidade;
    printf("Insira a quantidade de cidades: ");
    scanf("%d",&n);

    if((cidade = (cidades *)malloc(n*sizeof(cidades)))==NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    if((distancias = (float **)malloc(n*sizeof(float*)))==NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    for(int i=0; i<n; i++){
        
        if((distancias[i] = (float *)malloc(n*sizeof(float)))==NULL){
            printf("Erro de alocacao de memoria\n");
            exit(1);
        }
    }

    for(int i=0; i<n; i++){
        printf("Insira a coordenada x da cidade %d: ", i);
        scanf("%f", &cidade[i].x);
        printf("Insira a coordenada y da cidade %d: ", i);
        scanf("%f", &cidade[i].y);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            distancias[i][j] = sqrt(pow(cidade[j].x - cidade[i].x, 2) + pow(cidade[j].y - cidade[i].y, 2));
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%.2f ", distancias[i][j]);
        }
        printf("\n");
    }

    printf("Insira o numero de duas cidades: ");
    scanf("%d %d", &a, &b);
    if(a < 0 || a > n || b < 0 || b > n){
        printf("Cidades invalidas\n");
    }else printf("A distancia entre as cidades %d e %d eh de %.2f\n", a, b, distancias[a][b]);
    
    return 0;
}