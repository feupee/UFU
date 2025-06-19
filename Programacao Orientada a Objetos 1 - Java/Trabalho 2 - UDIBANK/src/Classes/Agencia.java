package Classes;

import java.io.Serializable;

public class Agencia{
    private String NmrAgencia;
    private String NmAgencia;
    private String endereco;
    private String cidade;
    private String estado;
    private String bairro;
    private Gerente gerente;
    private Funcionario[] funcionarios;

    public Agencia(String nmrAgencia, String nmAgencia, String endereco, String cidade, String estado, String bairro, Gerente gerente, Funcionario[] funcionarios) {
        NmrAgencia = nmrAgencia;
        NmAgencia = nmAgencia;
        this.endereco = endereco;
        this.cidade = cidade;
        this.estado = estado;
        this.bairro = bairro;
        this.funcionarios = funcionarios;
        if (gerente.getAgencia() != null) {
            throw new IllegalArgumentException("Este gerente já está associado a outra agência.");
        }
        // Cada agência possui um gerente,
        // que é um funcionário nomeado para tal tarefa. Cada gerente pode
        // gerenciar apenas uma agência.
        this.gerente = gerente;
        this.funcionarios = funcionarios;
    }

    public String getNmrAgencia() {
        return NmrAgencia;
    }

    public void setNmrAgencia(String nmrAgencia) {
        NmrAgencia = nmrAgencia;
    }

    public String getNmAgencia() {
        return NmAgencia;
    }

    public void setNmAgencia(String nmAgencia) {
        NmAgencia = nmAgencia;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public Funcionario[] getFuncionarios() {
        return funcionarios;
    }

    public void setFuncionarios(Funcionario[] funcionarios) {
        this.funcionarios = funcionarios;
    }

    public Gerente getGerente() {
        return gerente;
    }

    public void setGerente(Gerente gerente) {
        if (this.gerente != null) {
            throw new IllegalStateException("Esta agência já possui um gerente.");
        }
        this.gerente = gerente;
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public String getEstado() {
        return estado;
    }

    public void setEstado(String estado) {
        this.estado = estado;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

}
