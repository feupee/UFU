package Util;

import Util.Funcionario;

import java.util.Date;

class FuncionarioParcerias extends Funcionario {
    private int numeroHoteisResponsavel;
    private static final double porcentagemBonusPorHotel = 0.1;

    // Construtor
    public FuncionarioParcerias(String nome, String cpf, String enderecoCompleto, String numeroCarteiraTrabalho, Date dataNascimento, double salarioFixo) {
        super(nome, cpf, enderecoCompleto, numeroCarteiraTrabalho, dataNascimento, salarioFixo);
        this.numeroHoteisResponsavel = 0;
    }

    // Método para adicionar um novo hotel ao total de hotéis responsáveis pelo funcionário
    public void adicionarHotelResponsavel() {
        this.numeroHoteisResponsavel++;
    }

    // Método para calcular o salário atualizado com base no número de hotéis responsáveis
    public double getSalarioFixo() {
        // Calcula o bônus com base no número de hotéis responsáveis multiplicado pela porcentagem de bônus por hotel
        double bonus = this.numeroHoteisResponsavel * (getSalarioFixo() * (porcentagemBonusPorHotel / 100.0));
        // Retorna o salário fixo mais o bônus
        return super.getSalarioFixo() + bonus;
    }

    // Getter para o número de hotéis responsáveis
    public int getNumeroHoteisResponsavel() {
        return numeroHoteisResponsavel;
    }

    public void setNumeroHoteisResponsavel(int numeroHoteisResponsavel) {
        this.numeroHoteisResponsavel = numeroHoteisResponsavel;
    }
}