class FolhaPagamento {
    public static void exibirFolha(Funcionario[] funcionarios) {
        System.out.println("===== Folha de Pagamento =====");
        for (Funcionario f : funcionarios) {
            System.out.println(f.getNome() + " - " + f.getClass().getSimpleName() + " - Salário: R$ " + f.calcularSalario());
        }
    }
}