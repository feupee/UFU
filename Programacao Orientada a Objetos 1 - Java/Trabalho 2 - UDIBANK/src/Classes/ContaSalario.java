package Classes;

import ExceptionsAndInterfaces.Imprimivel;

import java.io.Serializable;
import java.util.Date;

public class ContaSalario extends ContaBancaria implements Imprimivel{
    private double limite_saque;
    private double limite_transferencia;

    public ContaSalario(String numeroConta, double saldoInicial, Date dataAbertura, double limite_saque, double limite_transferencia, String Senha, boolean status, Agencia agencia, Cliente cliente) {
        super(numeroConta, saldoInicial, dataAbertura, Senha, status, cliente, agencia);
        this.limite_saque = limite_saque;
        this.limite_transferencia = limite_transferencia;
    }

    public double getLimite_saque() {
        return limite_saque;
    }

    public void setLimite_saque(double limite_saque) {
        this.limite_saque = limite_saque;
    }

    public double getLimite_transferencia() {
        return limite_transferencia;
    }

    public void setLimite_transferencia(double limite_transferencia) {
        this.limite_transferencia = limite_transferencia;
    }
    @Override
    public void imprimirDados() {
        System.out.println("Conta Salário:");
        System.out.println("Número da Conta: " + getNumeroConta());
        System.out.printf("Saldo: R$ %.2f\n", getSaldo());
        System.out.println("Limite de Saque: R$ " + limite_saque);
        System.out.println("Limite de Transferência: R$ " + limite_transferencia);
    }
}
