#include <stdio.h>
#include <string.h>

int main(){

    int i,j,l,k;
    char string1[100];
    char string2[100];
    char caractere, caractere2;
    int count = 0;

    printf("Selecione um numero\n");
    printf(" 1 - Ler uma string S1 (tamanho maximo 20 caracteres)\n");
    printf(" 2 - Imprimir o tamanho da string S1\n");
    printf(" 3 - Comparar a string S1 com uma nova string S2 fornecida pelo usuario e imprimir o resultado da comparacao\n");
    printf(" 4 - Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da concatenacao\n");
    printf(" 5 - Imprimir a string S1 de forma reversa\n");
    printf(" 6 - Contar quantas vezes um dado caractere aparece na string S1. Esse caractere desse ser informado pelo usuario\n");
    printf(" 7 - Substituir a primeira ocorrencia do caractere C1 da string S1 pelo caractere C2. Os caracteres C1 e C2 serao lidos pelo usuario\n");
    printf(" 8 - Verificar se uma string S2 e substring de S1. A string S2 deve ser informada pelo usuario\n");
    printf(" 9 - Retornar uma substring da string S1. Para isso o usuario deve informar a partir de qual posicao deve ser criada a substring e qual e o tamanho da substring\n");

    printf("\nO que deseja fazer: ");
    scanf("%i", &k);

    if(k < 1 || k > 9){
        printf("Valor invalido");
        return 0;
    }

    switch(k){
        case 1 :
            setbuf(stdin,NULL);
            printf("\nDigite a string: ");
            fgets(string1, 100, stdin);
            if(strlen(string1) > 20){
                printf("Tamanho invalido");
                return 0;
            }
            printf("\nA string eh: %s", string1);
        break;
        case 2 :
            setbuf(stdin,NULL);
            printf("\nDigite a string: ");
            fgets(string1, 100, stdin);
            i = strlen(string1);
            printf("\nO tamanho de %s eh: %i", string1, i);
        break;
        case 3 :
            setbuf(stdin,NULL);
            printf("\nDigite a string 1: ");
            fgets(string1, 100, stdin);
            printf("\nDigite a string 2: ");
            fgets(string2, 100, stdin);
            printf("\n\nResultado: %d\n\n", strcmp(string1, string2));

        break;
        case 4 :
            setbuf(stdin,NULL);
            printf("\nDigite a string 1: ");
            fgets(string1, 100, stdin);
            printf("\nDigite a string 2: ");
            fgets(string2, 100, stdin);
            printf("\n\nResultado: %s\n\n", strcat(string1, string2));
        break;
        case 5 :
            setbuf(stdin,NULL);
            printf("\nDigite a string 1: ");
            fgets(string1, 100, stdin);
            j = strlen(string1);
            l = j;
            for(i = -1; i < j; i++){
                string2[i] = string1[l];
                l--;
            }
            printf("String invertida eh: ");
            for(i = 0; i < j; i++){
            printf("%c", string2[i]);
            }
        break;
        case 6 :
        
            setbuf(stdin,NULL);
            printf("\nDigite a string 1: ");
            fgets(string1, 100, stdin);
            printf("\nDigite o caractere: ");
            scanf("%c", &caractere);

            j = strlen(string1);

            for(i = 0; i < j; i++){
                if(string1[i] == caractere){
                    count++;
                }
            }

            printf("\nO caractere %c aparece %i vez(es) na string", caractere, count);
        break;
        case 7 :
            setbuf(stdin,NULL);
            printf("\nDigite a string 1: ");
            fgets(string1, 100, stdin);
            printf("\nDigite o caractere 1: ");
            scanf("%c", &caractere);
            printf("\nDigite o caractere 2: ");
            scanf(" %c", &caractere2);

            j = strlen(string1);

            for(i = 0; i < j; i++){
                if(string1[i] == caractere){
                    string1[i] = caractere2;
                    printf("A string ficara como: %s", string1);
                    return 0;
                }
            }
        break;
        case 8 :
            setbuf(stdin,NULL);
            printf("\nDigite a string(substring) 1: ");
            fgets(string1, 100, stdin);
            printf("\nDigite a string(string) 2: ");
            fgets(string1, 100, stdin);
            
            j = strlen(string1);
            k = strlen(string2);

            if(k < j){
                printf("%s nao eh substring de %s", string1, string2);
                return 0;
            }
            if(j == k){
                l = strcmp(string1,string2);
                if(l == 0){
                    printf("%s eh igual a %s",string1,string2);
                    return 0;
                }
            }
            if(j < k){
                for(i = 0; i < j; i++){
                    if(string1[i] != string2[i]){
                        printf("String1 nao eh substring de String2");
                        return 0;
                    }
                }
                printf("%s eh substring de %s",string1,string2);   
            }
        break;
        case 9 :
            setbuf(stdin, NULL);
            printf("Digite a string: ");
            fgets(string1, 100, stdin);
            l = strlen(string1) - 1;
            printf("A partir de qual posicao quer formar a substrig(0 - %i): ", l);
            scanf("%i", &k);
            printf("Substring serah: ");
            for(i = k; i <= l; i++){
                printf("%c", string1[i]);
            }

        break;
    
    }
    return 0;
} 