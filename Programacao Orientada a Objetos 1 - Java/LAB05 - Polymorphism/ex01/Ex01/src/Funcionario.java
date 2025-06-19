public class Funcionario {
    private String nome;
    private String dataNascimento;
    protected double salario;

    public Funcionario(String nome, String dataNascimento) {
        this.nome = nome;
        this.dataNascimento = dataNascimento;
    }

    public double calcularSalario() {
        return salario;
    }

    public String getNome() {
        return nome;
    }

    public String getDataNascimento() {
        return dataNascimento;
    }

    public double getSalario() {
        return calcularSalario();
    }
}