class Funcionario {
    private String cpf;
    private String nome;
    private double salario;
    private double tetoSalarial = 40000.0; // Valor padrão do teto salarial

    public Funcionario(String cpf, String nome, double salario) {
        if (salario < 0) {
            throw new SalarioInvalidoException("Valor inválido de salário");
        } else if (salario > tetoSalarial) {
            throw new SalarioInvalidoException("Valor ultrapassa o teto");
        }
        this.cpf = cpf;
        this.nome = nome;
        setSalario(salario); // Garante que o salário inicial seja válido
    }

    // Getters e Setters
    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        if (salario < 0) {
            throw new SalarioInvalidoException("Valor inválido de salário");
        } else if (salario > tetoSalarial) {
            throw new SalarioInvalidoException("Valor ultrapassa o teto");
        }
        this.salario = salario;
    }

    public double getTetoSalarial() {
        return tetoSalarial;
    }

    public void setTetoSalarial(double tetoSalarial) {
        this.tetoSalarial = tetoSalarial;
    }

    // Método para aumentar o salário
    public void aumentarSalario(double percentual) {
        double novoSalario = this.salario * (1 + percentual / 100.0);
        setSalario(novoSalario);
    }

    public void mostrarSalario(){
        System.out.println(this.salario);
    }
}