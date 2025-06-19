package Classes;

import ExceptionsAndInterfaces.Imprimivel;

import java.io.Serializable;
import java.util.Date;

public class ContaCorrente extends ContaBancaria implements Imprimivel{
    private double limite_chequeEspecial;
    private double valor_taxaAdministrativa;
    private String NrmConta;


    public ContaCorrente(String numeroConta, double saldoInicial, Date dataAbertura, double limite_chequeEspecial, double valor_taxaAdministrativa, String NrmConta, String Senha, boolean status, Agencia agencia, Cliente cliente) {
        super(numeroConta, saldoInicial, dataAbertura, Senha, status, cliente, agencia);
        this.limite_chequeEspecial = limite_chequeEspecial;
        this.valor_taxaAdministrativa = valor_taxaAdministrativa;
        this.NrmConta = NrmConta;
    }

    public double getLimite_chequeEspecial() {
        return limite_chequeEspecial;
    }

    public void setLimite_chequeEspecial(double limite_chequeEspecial) {
        this.limite_chequeEspecial = limite_chequeEspecial;
    }

    public double getValor_taxaAdministrativa() {
        return valor_taxaAdministrativa;
    }

    public void setValor_taxaAdministrativa(double valor_taxaAdministrativa) {
        this.valor_taxaAdministrativa = valor_taxaAdministrativa;
    }

    public String getNrmConta() {
        return NrmConta;
    }

    public void setNrmConta(String nrmConta) {
        NrmConta = nrmConta;
    }

    @Override
    public void imprimirDados() {
        System.out.println("Conta Corrente:");
        System.out.println("Número da Conta: " + getNumeroConta());
        System.out.printf("Saldo: R$ %.2f\n", getSaldo());
        System.out.println("Limite Cheque Especial: R$ " + limite_chequeEspecial);
        System.out.println("Taxa Administrativa: R$ " + valor_taxaAdministrativa);
    }
}
