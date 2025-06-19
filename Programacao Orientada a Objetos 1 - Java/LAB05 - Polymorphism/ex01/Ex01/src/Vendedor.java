class Vendedor extends Funcionario {
    private double salarioFixo;
    private double comissao;
    private int vendas;

    public Vendedor(String nome, String dataNascimento, double salarioFixo, double comissao, int vendas) {
        super(nome, dataNascimento);
        this.salarioFixo = salarioFixo;
        this.comissao = comissao;
        this.vendas = vendas;
    }

    @Override
    public double calcularSalario() {
        return salarioFixo + (comissao * vendas);
    }
}