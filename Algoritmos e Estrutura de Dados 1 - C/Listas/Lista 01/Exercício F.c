#include <stdio.h>

#include <stdlib.h>


int main()
{
    
    
int base, altura;
    
float area;
    
    
printf("Digite base: ");
    
scanf("%d", &base); 
    
if(base <= 0){
        
printf("Valor invalido");
        
exit(0);
    }
    
printf("Digite altura");
    
scanf("%d", &altura);
    
if(altura <= 0){
        
printf("Valor invalido");
        
exit(0);
    }
    
   
area = (base * altura)/2;
    
    
printf("Area: %f", area);
    
   
return 0;
    

}