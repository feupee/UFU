#include <stdio.h>

int main()
{
    
    
int count, quant, num, soma;
    
    
printf("Digite a quantidade de numeros a ser lidos: ");
    
scanf("%d", &quant);
    
    
for(int i = 0; i < quant; i++){
        
printf("Digite numero: ");
        
scanf("%d", &num);
        
if(num > 10){
            
soma += num;
        
}
        
if(num < 10){
            
count++;
        
}
        
if(num == 10){
            
return 0;
        
}
    
}
    
    
printf("Soma eh: %d", soma);
    printf("\nCount eh: %d", count);
    



return 0;
}