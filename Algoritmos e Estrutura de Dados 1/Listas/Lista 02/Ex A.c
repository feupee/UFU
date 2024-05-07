#include <stdio.h>
#include <string.h>

int main(){
    
    char nome[] = "Carla Faria";
    char *p1 = nome;
    int i;

    double vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    while (*p1 != '\0') {
        printf("%c", *p1);
        p1++;
    }

    printf("\n");

    double *p2 = vet;

    for(i = 0; i < 10; i++){
        printf("%.2f\n", *p2);
        p2++;
    }
    
    return 0;
}