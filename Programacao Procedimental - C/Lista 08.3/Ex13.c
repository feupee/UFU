#include<stdio.h>

void nota(float *n1, float *n2){
    printf("Insira a primeira nota: ");
    scanf("%f", n1);
    printf("Insira a segunda nota: ");
    scanf("%f", n2);
}

void media(float *ms, float *mp, float *n1, float *n2){
    *ms=(*n1+*n2)/2;
    *mp=(*n1+2* *n2)/3;
}

int main(){
    float n1, n2, ms, mp;
    nota(&n1, &n2);
    media(&ms, &mp, &n1, &n2);
    printf("A media simples eh %.1f e a media ponderada eh %.1f", ms, mp);
    return 0;
}