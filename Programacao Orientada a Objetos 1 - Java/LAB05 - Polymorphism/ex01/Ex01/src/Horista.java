class Horista extends Funcionario {
    private double valorPorHora;
    private int horasTrabalhadas;

    public Horista(String nome, String dataNascimento, double valorPorHora, int horasTrabalhadas) {
        super(nome, dataNascimento);
        this.valorPorHora = valorPorHora;
        this.horasTrabalhadas = horasTrabalhadas;
    }

    @Override
    public double calcularSalario() {
        return valorPorHora * horasTrabalhadas;
    }
}