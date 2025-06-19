package Classes;

import ExceptionsAndInterfaces.ValorInvalidoException;

import java.io.Serializable;
import java.util.Calendar;
import java.util.Date;

public class Funcionario extends Pessoa{
    private String Nro_carteiradeTrabalho;
    private String RG;
    private String sexo;
    private String cargo_empresa;
    private String salario;
    private String ano_ingresso;

    private static final long serialVersionUID = 1L;

    public Funcionario(String CPF, String nome, String endereco_completo, String estado_civil, String escolaridade, Date data_nascimento, String nro_carteiradeTrabalho, String RG, String cargo_empresa, String salario, String ano_ingresso, String sexo) throws ValorInvalidoException {
        super(CPF, nome, endereco_completo, estado_civil, escolaridade, data_nascimento);
        this.Nro_carteiradeTrabalho = nro_carteiradeTrabalho;
        this.RG = RG;
        this.sexo = sexo;
        this.cargo_empresa = cargo_empresa;
        this.salario = salario;
        this.ano_ingresso = ano_ingresso;
    }

    public String getNro_carteiradeTrabalho() {
        return Nro_carteiradeTrabalho;
    }

    public void setNro_carteiradeTrabalho(String nro_carteiradeTrabalho) {
        Nro_carteiradeTrabalho = nro_carteiradeTrabalho;
    }

    public String getRG() {
        return RG;
    }

    public void setRG(String RG) {
        this.RG = RG;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }


    public String getCargo_empresa() {
        return cargo_empresa;
    }

    public void setCargo_empresa(String cargo_empresa) {
        this.cargo_empresa = cargo_empresa;
    }

    public String getSalario() {
        return salario;
    }

    public void setSalario(String salario) {
        this.salario = salario;
    }

    public String getAno_ingresso() {
        return ano_ingresso;
    }

    public void setAno_ingresso(String ano_ingresso) {
        this.ano_ingresso = ano_ingresso;
    }

    public double calcularSalario() {
        double salarioBase = Double.parseDouble(salario);  // Convertendo o salário de String para double

        // Obter o ano atual
        int anoAtual = Calendar.getInstance().get(Calendar.YEAR);
        // Calcular a diferença de anos entre o ano atual e o ano de ingresso
        int anosDeEmpresa = anoAtual - Integer.parseInt(ano_ingresso);
        // Se o funcionário tem mais de 15 anos de empresa, adiciona 10% ao salário
        if (anosDeEmpresa > 15) {
            salarioBase *= 1.10;  // Adiciona 10%
        }
        return salarioBase;  // Retorna o salário com o adicional, se aplicável
    }
}
