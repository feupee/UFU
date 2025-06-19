package Classes;

import java.util.Date;

public class Transacao {
    private double valor;
    private String tipo;  // Tipo da transacao: saque, depósito, consultar saldo, efetuar pagamento
    private ContaBancaria contaBancaria;
    private Date data;
    private String canal;

    //Em cada uma dessas transações é importante armazenar apenas o valor da transação??

    public Transacao(ContaBancaria contaBancaria, double valor, String tipo, String canal) {
        this.valor = valor;
        this.tipo = tipo;
        this.data = new Date();
        this.contaBancaria = contaBancaria;
    }

    public Transacao(ContaBancaria contaBancaria, Date data, String canal) {
        this.contaBancaria = contaBancaria;
        this.data = data;
    }

    public double getValor() {
        return valor;
    }

    public String getTipo() {
        return tipo;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    @Override
    public String toString() {
        return tipo + ": R$ " + valor;
    }
}