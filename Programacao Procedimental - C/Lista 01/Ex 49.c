#include <stdio.h>
#include <stdlib.h>

int main() { 

	printf("Primeira formatacao -->");

	printf("\n");

    int Se, Mi ,Hr, Dr;


    printf("O valor do relogio inicial em segundos: ");
    scanf("%i",&Se);
	if(Se < 0 || Se > 59) {
		exit(0);
	}

	printf("O valor do relogio inicial em minutos: ");
    scanf("%i",&Mi);
	if(Mi < 0 || Mi > 59) {
		exit(0);
	}

	printf("O valor do relogio inicial em horas: ");
    scanf("%i",&Hr);
	if(Hr < 0 || Hr > 23) {
		exit(0);
	}
    printf("\n");

	printf("O valor do relogio inicial eh: %i:%i:%i", Hr, Mi, Se);

	printf("\n");
	printf("\n");

	printf("Digite o valor da duracao em segundos: ");
    scanf("%i",&Dr);

	int horas, minutos, segundos;

   	horas = Dr / 3600;
   	minutos = (Dr-(horas*3600))/60;
   	segundos = Dr - (horas*3600)-(minutos*60);

   	int Hf, Mf, Sf, Dia = 0;

   	Hf= Hr + horas;
   	Mf= Mi + minutos;
   	Sf= Se + segundos;

	while(Hf > 24) {
		Hf = Hf - 24;
		Dia++;
	}

	while(Mf >= 60) {
		Mf = Mf - 60;
		Hf++;
	}

	while(Sf >= 60) {
		Sf = Sf - 60;
		Mf++;
	}

   	printf("\nA experiencia terminara em: %i dia(s) as %i:%i:%i ", Dia, Hf, Mf, Sf );

	printf("\n");

	

/*----------------------------------------------------------------------------------------------------------*/	

    int Hr2, Mi2, Se2, h2, m2, s2, h3, m3, s3, DUR2, temp;

	printf("\n");

	printf("Segunda formatacao: -->");

	printf("\n");

    printf("Insira as horas de inicio:");
    scanf("%i", &Hr2);

	printf("\n");

	printf("Insira os minutos de inicio:");
    scanf("%i", &Mi2);

	printf("\n");

	printf("Insira os segundos de inicio:");
    scanf("%i", &Se2);


	printf("\n");

	printf("O horario de inicio foi %i:%i:%i", Hr2, Mi2, Se2);

	printf("\n");

    printf("Digite a duracao do experimento em segundos:");
    scanf("%i", &DUR2);
    
    temp=DUR2%3600; 
    h2=DUR2/3600; 
    m2=temp/60; 
    s2=temp%60; 

    s3=(s2+Se2)%60;
    m3=(m2+Mi2+(s2+Se2)/60)%60;
    

    h3=(h2+Hr2+(m2+Mi2+(s2+Se2)/60)/60)%24;
   

    printf("Esse experimento acabou as %i:%i:%i, %i dia(s) depois", h3, m3, s3, (h2+Hr2+(m2+Mi2+(s2+Se2)/60)/60)/24);
}
