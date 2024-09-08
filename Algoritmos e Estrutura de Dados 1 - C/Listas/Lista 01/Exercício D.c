#include <stdio.h>

int main()
{
    
    
int nota1, nota2, nota3, notafaltante;
    
float media;
    
    
printf("Digite nota1:");
    
scanf("%d", &nota1);
    
printf("Digite nota2:");
    
scanf("%d", &nota2);
    
printf("Digite nota3:");
    
scanf("%d", &nota3);
    
    
media = (nota1 + nota2 + nota3)/3;
    
    
if(media < 3 && media > 0){
        
printf("Aluno reprovado");
    
}
    
if(media < 7 && media > 3){
        
printf("Exame Final");
        
notafaltante = 6 - media;
        
printf("Faltante %d", notafaltante);
    
}
    
if(media < 10 && media > 7){
        
printf("Aluno aprovado");
    
}
    
    

return 0;


}