#include<stdio.h>

void min_max(int *V, int *min, int *max, int l){
    int i;
    *min=*V;
    *max=*V;
    for(i=1; i<l; i++){
        if(*(V+i)>*max){
            *max=*(V+i);
        } else if(*(V+i)<*min){
            *min=*(V+i);
        }
    }
}

int main(){
    int a[10], min, max, i;

    for(i=0; i<10; i++){
        printf("Insira o %d%c valor: ", i+1, 167);
        scanf("%d", a+i);
    }
    min_max(a, &min, &max, 10);
    printf("O maior numero eh %d e o menor eh %d", max, min);
    return 0;
}