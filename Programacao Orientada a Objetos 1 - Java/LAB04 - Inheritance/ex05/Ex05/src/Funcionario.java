public class Funcionario {
    private String nome, dataNascimento;
    private float salario_fixo;

    public Funcionario(float salario_fixo, String nome, String dataNascimento) {
        this.nome = nome;
        this.dataNascimento = dataNascimento;
        this.salario_fixo = salario_fixo;
    }
    public Funcionario(String nome, String dataNascimento){
        this.nome = nome;
        this.dataNascimento = dataNascimento;
    }
}
