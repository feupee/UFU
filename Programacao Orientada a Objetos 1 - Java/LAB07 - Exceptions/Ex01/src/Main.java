public class Main {
    public static void main(String[] args) {

        Funcionario []funcionarios = new Funcionario[3];
        funcionarios[0] = new Funcionario("123456789", "João", 1500);
        funcionarios[1] = new Funcionario("987654321", "Zé", -1200); //Valor Invalido de Salario
        funcionarios[2] = new Funcionario("654321978", "Maria", 50000); //Valor ultrapassa o teto

        funcionarios[0].mostrarSalario();
        funcionarios[1].mostrarSalario();
        funcionarios[2].mostrarSalario();

    }
}