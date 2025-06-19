class Chefe extends Funcionario {
    public Chefe(String nome, String dataNascimento, double salarioFixo) {
        super(nome, dataNascimento);
        this.salario = salarioFixo;
    }

    @Override
    public double calcularSalario() {
        return salario;
    }
}