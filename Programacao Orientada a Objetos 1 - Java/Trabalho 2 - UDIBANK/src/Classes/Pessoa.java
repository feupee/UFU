package Classes;

import ExceptionsAndInterfaces.Imprimivel;
import ExceptionsAndInterfaces.ValorInvalidoException;

import java.io.Serializable;
import java.util.Date;

public abstract class Pessoa{
    private String CPF;
    private String nome;
    private String endereco_completo;
    private String estado_civil;
    private String escolaridade;
    private Date data_nascimento;

    public Pessoa(String CPF, String nome, String endereco_completo, String estado_civil, String escolaridade, Date data_nascimento) throws ValorInvalidoException {
        if (!ValidadorCPF.validarCPF(CPF)) {
            throw new ValorInvalidoException("CPF Invalido");
        }
        this.CPF = CPF;
        this.nome = nome;
        this.endereco_completo = endereco_completo;
        this.estado_civil = estado_civil;
        this.escolaridade = escolaridade;
        this.data_nascimento = data_nascimento;
    }
    public Pessoa(){

    }

    public Pessoa(String CPF, String nome) throws ValorInvalidoException {
        if (!ValidadorCPF.validarCPF(CPF)) {
            throw new ValorInvalidoException("CPF Invalido");
        }
        this.CPF = CPF;
        this.nome = nome;
    }

    public String getCPF() {
        return CPF;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEndereco_completo() {
        return endereco_completo;
    }

    public void setEndereco_completo(String endereco_completo) {
        this.endereco_completo = endereco_completo;
    }

    public String getEstado_civil() {
        return estado_civil;
    }

    public void setEstado_civil(String estado_civil) {
        this.estado_civil = estado_civil;
    }

    public String getEscolaridade() {
        return escolaridade;
    }

    public void setEscolaridade(String escolaridade) {
        this.escolaridade = escolaridade;
    }

    public Date getData_nascimento() {
        return data_nascimento;
    }

    public void setData_nascimento(Date data_nascimento) {
        this.data_nascimento = data_nascimento;
    }
}
