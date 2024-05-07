package Util;
import java.util.Date; // Importe a classe Date para usar na data de nascimento


// Classe Util.Pessoa
public class Pessoa {
    private String nome;
    private String cpf;
    private Date dataNascimento;
    private String enderecoCompleto;

    // Construtor
    public Pessoa(String nome, String cpf, String enderecoCompleto, Date dataNascimento) {
        this.nome = nome;
        this.dataNascimento = dataNascimento;
        this.enderecoCompleto = enderecoCompleto;
    }

    // Getters and Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public Date getDataNascimento() {
        return dataNascimento;
    }

    public void setDataNascimento(Date dataNascimento) {
        this.dataNascimento = dataNascimento;
    }

    public String getEnderecoCompleto() {
        return enderecoCompleto;
    }

    public void setEnderecoCompleto(String enderecoCompleto) {
        this.enderecoCompleto = enderecoCompleto;
    }
}



