package Persistencia.Conta;

import Classes.*;

import java.util.Date;
import java.util.Random;

public class GeradorContasBancarias {
    private static final Random random = new Random();

    public static ContaBancaria gerarContaAleatoria(Cliente cliente, Agencia agencia) {
        String numeroConta = gerarNumeroConta();
        double saldoInicial = random.nextDouble() * 10000;
        Date dataAbertura = new Date();
        String senha = String.format("%04d", random.nextInt(10000));
        boolean status = true;

        int tipoConta = random.nextInt(3); // 0=Corrente, 1=Poupança, 2=Salário

        switch(tipoConta) {
            case 0:
                return new ContaCorrente(
                        numeroConta, saldoInicial, dataAbertura,
                        random.nextDouble() * 5000, // limite cheque especial
                        30.00, // taxa administrativa
                        "CC" + numeroConta.substring(2),
                        senha, status, agencia, cliente
                );

            case 1:
                return new ContaPoupanca(
                        numeroConta, saldoInicial, dataAbertura,
                        random.nextDouble() * 0.5 + 0.1, // rendimento entre 0.1% e 0.6%
                        senha, status, agencia, cliente
                );

            case 2:
                return new ContaSalario(
                        numeroConta, saldoInicial, dataAbertura,
                        2000.00, // limite saque
                        5000.00, // limite transferência
                        senha, status, agencia, cliente
                );

            default:
                return new ContaCorrente(
                        numeroConta, saldoInicial, dataAbertura,
                        random.nextDouble() * 5000,
                        30.00,
                        "CC" + numeroConta.substring(2),
                        senha, status, agencia, cliente
                );
        }
    }

    public static String gerarNumeroConta() {
        return String.format("%04d%06d",
                random.nextInt(10000), // agência (4 dígitos)
                random.nextInt(1000000) // conta (6 dígitos)
        );
    }
}