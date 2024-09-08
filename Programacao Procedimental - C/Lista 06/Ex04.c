#include <stdio.h>

    struct aluno{
        char nome[50];
        char matricula[10];
        int nota[3];
    };

int main(){

    int i, j, maior1 = 0, media = 0, mediamaior = 0, nota1;
    struct aluno c[5];
    
    // a)
    for(i = 0; i < 5; i++){
        
        
        printf("\nDigite o nome do aluno %i: ", (i+1));
        fflush(stdin);
        fgets(c[i].nome, 50, stdin);

        printf("Digite a matricula: ");
        fflush(stdin);
        fgets(c[i].matricula, 10, stdin);
    
        for(j = 0; j < 3; j++){
            fflush(stdin);
            printf("Digite a nota da prova %i: ", (j+1));
            scanf("%d", &c[i].nota[j]);
        }
         

    }

    // b)
    for(i = 0; i < 5; i++){
        
        if(c[i].nota[1] > maior1){
            nota1 = c[i].nota[i];
            maior1 = i;
        }
        
    }
    printf("\nO aluno com maior nota na prova 1 eh: Aluno %i", maior1);
    printf("\nNota: %i", nota1); 

    // c)
    for(i = 0; i < 5; i++){
        media = 0;
        for(j = 0; j < 3; j++){
            media += c[i].nota[j];
        }
        media = media/3;
        if(media > mediamaior){
            mediamaior = media;
            maior1 = i;
        }
    }
    printf("\nO Aluno com maior media eh: Aluno %i", maior1);
    printf("\nMedia: %i", mediamaior);

    // d)
    for(i = 0; i < 5; i++){
        media = 0;
        for(j = 0; j < 3; j++){
            media += c[i].nota[j];
        }
        media = media/3;
        if(media < mediamaior){
            mediamaior = media;
            maior1 = i;
        }
    }
    printf("\nO Aluno com menor media eh: Aluno %i", maior1);
    printf("\nMedia: %i", mediamaior);

    // e)
    for(i = 0; i < 5; i++){
        media = 0;
        for(j = 0; j < 3; j++){
            media += c[i].nota[j];
        }
        media = media/3;
        if(media >= 6){
           printf("\nO aluno %i passou", i);
        }else{
           printf("\nO aluno %i reprovou", i); 
        }
    }
    


    return 0;
}