#include <stdio.h>


int main()
{
    
    
int opcao, num1, num2;
float resultado;
    
printf("Digite num1: ");
    
scanf("%d", &num1);
    
printf("Digite num2: ");
    
scanf("%d", &num2);
    
printf("Digite \n1 para soma\n2 para subtracao\n3 para multiplicacao\n4 para divisao");
    
printf("Opcao: ");
    
scanf("%d", &opcao);
    
    
if(opcao < 0 || opcao > 4){
        
printf("Opcao invalida");
        
scanf("%d", &opcao);
    }
    
    
switch(opcao){
        
case 1 : 
        
resultado = num1 + num2;
        
break;
        
case 2 :
        
resultado = num1 - num2;
        
break;
       
case 3 :
       
resultado = num1 * num2;
        
break;
        
case 4 :
        
resultado = num1 / num2;
    
}
    
    

printf("O resultado eh: %f", resultado);

return 0;



}