package Classes;

import ExceptionsAndInterfaces.Imprimivel;

import java.io.Serializable;
import java.util.Date;

public class ContaPoupanca extends ContaBancaria implements Imprimivel{
    private double rendimento_mesAtual;

    public ContaPoupanca(String numeroConta, double saldoInicial, Date dataAbertura, double rendimento_mesAtual, String Senha, boolean status, Agencia agencia, Cliente cliente) {
        super(numeroConta, saldoInicial, dataAbertura, Senha, status, cliente, agencia);
        this.rendimento_mesAtual = rendimento_mesAtual;
    }

    public double getRendimento_mesAtual() {
        return rendimento_mesAtual;
    }

    public void setRendimento_mesAtual(double rendimento_mesAtual) {
        this.rendimento_mesAtual = rendimento_mesAtual;
    }
    @Override
    public void imprimirDados() {
        System.out.println("Conta Poupança:");
        System.out.println("Número da Conta: " + getNumeroConta());
        System.out.printf("Saldo: R$ %.2f\n", getSaldo());
        System.out.println("Rendimento do Mês Atual: R$ " + rendimento_mesAtual);
    }
}
