public class Vendedor extends Funcionario{
    float salario_vendedor;

    public Vendedor(float comissao, float valor_fixo, String nome, String dataNascimento) {
        super(nome, dataNascimento);
        this.salario_vendedor = valor_fixo + comissao;
    }
}
