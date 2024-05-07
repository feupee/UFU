//Exercício B

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int resposta, *vet = NULL, n, count, i;

    do {
        printf("Deseja criar um novo vetor? (1 para continuar)\n");
        scanf("%d", &resposta);
        count = 0;
        if (resposta == 1) {
            vet = (int *)malloc(1 * sizeof(int));
            do {
                printf("Digite o valor para adicionar ao vetor (digite -1 para encerrar): ");
                scanf("%d", &n);
                if (n != -1) {
                    count++;
                    vet = (int *)realloc(vet, count * sizeof(int)); // Realoca memória uma vez

                    if (vet == NULL) {
                        printf("Erro ao alocar memória.\n");
                        return 1;
                    }

                    *(vet + count - 1) = n;
                }
            } while (n != -1);
        }
    
    //Verificar numeros repetidos e retirálos
        for(i = 0; i < count; i++){
            if(*(vet + i) == *(vet + i+1)){
             for(int j = i; j < count; j++){
            *(vet + j) = *(vet + j+2);
        }
        i--;
        count -= 2;
            }
        }

    // Realocar memória uma vez após a remoção dos números repetidos
        vet = (int *)realloc(vet, count * sizeof(int));

    //Imprimir Vetor
        for(i = 0; i < count; i++){
         printf("%d ", *(vet + i));
        }
        printf("\n");
        free(vet);
    }
    while(resposta == 1);
    

    

    return 0;
}
