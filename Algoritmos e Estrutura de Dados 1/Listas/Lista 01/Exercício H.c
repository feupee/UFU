#include <stdio.h>

#include <stdlib.h>

#include <string.h>


int main()
{
    
int i = 0, j = 0, count, k;
char string[100];
   
   
printf("Digite string: ");
   
fgets(string, 100, stdin);
   
   
k = strlen(string);
    
    
for(i = 0; i < k-1; i++){
        
for(j = 0; j < k-1; j++){
            
if(i != j){
            
if(string[i] == string[j]){
                
count++;
            
}
            
}
        
}
    
} 
    
    
printf("Quantidade de letras repetidas eh: %d", count);
    
    
return 0;
    


}