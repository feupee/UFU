public class Horista extends Funcionario{
    private float salario_horista;

    public Horista(float valor_hora, float horas_trabalhadas,String nome, String dataNascimento) {
        super(nome, dataNascimento);
        this.salario_horista = valor_hora*horas_trabalhadas;
    }
}
