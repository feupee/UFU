public class Empresa {
    public static void main(String[] args) {
        Funcionario[] funcionarios = new Funcionario[4];

        funcionarios[0] = new Chefe("Carlos Silva", "10/02/1975", 8000);
        funcionarios[1] = new Vendedor("Ana Souza", "05/06/1985", 2000, 100, 30);
        funcionarios[2] = new Operario("José Santos", "22/11/1990", 50, 200);
        funcionarios[3] = new Horista("Mariana Lima", "15/04/2000", 25, 160);

        FolhaPagamento.exibirFolha(funcionarios);
    }
}