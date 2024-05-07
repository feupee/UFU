#include <stdio.h>
#include <math.h>

    struct polar {
        int r;
        float raio;
    };
    

int main(){

    float x, y;
    struct polar c;
        
        printf("Digite a coordenada polar(r): ");
        scanf("%d", &c.r);

        printf("Digite a coordenada polar(raio): ");
        scanf("%f", &c.raio);

        x = c.r * cos(c.raio);
        y = c.r * sin(c.raio);

        printf("Coordenadas x e y transformadas: %.2f e %.2f", x, y);
    
    return 0;
}