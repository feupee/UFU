#include <stdio.h>

    struct datanas{
        int dia, mes, ano;
    };

    struct empresa {
        char nome[50];
        int idade;
        char sexo;
        char cpf[15];
        char codigosetor[3];
        char cargo[30];
        int salario;
        struct datanas a;
    };


int main(){

    struct empresa c; 
        
        
        printf("Digite o nome do funcionario: ");
        fflush(stdin);
        fgets(c.nome, 50, stdin);
        printf("Digite a idade do funcionario: ");
        scanf("%d", &c.idade);
        fflush(stdin);
        printf("Digite o sexo do funcionario(F ou M): ");
        scanf("%c", &c.sexo);
        printf("Digite o cpf do funcionario: ");
        fflush(stdin);
        fgets(c.cpf, 15, stdin);
        printf("Digite o codigo do setor do funcionario: ");
        fflush(stdin);
        fgets(c.codigosetor, 3, stdin);
        printf("Digite o cargo do funcionario: ");
        fflush(stdin);
        fgets(c.cargo, 30, stdin);
        printf("Digite o salario do funcionario: ");
        scanf("%d", &c.salario);

        printf("Digite o dia do nascimento do funcionario: ");
        scanf("%d", &c.a.dia);
        printf("Digite o mes do nascimento do funcionario: ");
        scanf("%d", &c.a.mes);
        printf("Digite o ano do nascimento do funcionario: ");
        scanf("%d", &c.a.ano);

        printf("\nDados do funcionario --> ");
        printf("\nNome  : %s", c.nome);
        printf("Idade : %d", c.idade);
        printf("\nSexo  : %c", c.sexo);
        printf("\nCPF   : %s", c.cpf);
        printf("Codigo: %s", c.codigosetor);
        printf("\nCargo : %s", c.cargo);
        printf("Salario  : %i", c.salario);
        printf("\nData de nascimento: %d/%d/%d", c.a.dia, c.a.mes, c.a.ano);
        

    return 0;
}