public class Operarios extends Funcionario{
    float salario_Operarios;

    public Operarios(float valor_producao, float quantidade_produzida, String nome, String dataNascimento) {
        super(nome, dataNascimento);
        this. salario_Operarios = valor_producao * quantidade_produzida;
    }
}
