package Classes;

import ExceptionsAndInterfaces.Imprimivel;
import ExceptionsAndInterfaces.ValorInvalidoException;

import java.util.Calendar;
import java.util.Date;

public class Testar {
    public static void main(String[] args) throws ValorInvalidoException {

        Calendar dataNasc = Calendar.getInstance();
        dataNasc.set(1980, Calendar.MARCH, 15);
        Calendar dataIngressoGerencia = Calendar.getInstance();
        dataIngressoGerencia.set(2020, Calendar.JANUARY, 1);

        Gerente gerente = new Gerente(
                "15285426650", "Ana Paula", "Rua do Classes.Gerente, 123", "Casada", "Superior Completo",
                dataNasc.getTime(), "123456", "MG-12.345.678", "Classes.Gerente Geral", "12000.00", "2010", "Feminino",
                dataIngressoGerencia.getTime(), null, true
        );

        Agencia agencia = new Agencia(
                "001", "Centro", "Rua A", "Cidade", "Estado", "Bairro", gerente, new Funcionario[0]
        );
        Cliente cliente1 = new Cliente("15285426650", "João", "Rua 1", "Solteiro", "Superior", new Date(), agencia);
        gerente.setAgencia(agencia);
        ContaCorrente cc = new ContaCorrente("1001", 1500.0, new Date(), 500.0, 25.0, "1001", "senha", true, agencia, cliente1);
        ContaPoupanca cp = new ContaPoupanca("1002", 2000.0, new Date(), 0.02, "senha", true, agencia, cliente1);
        ContaSalario cs = new ContaSalario("1003", 1000.0, new Date(), 300.0, 200.0, "senha", true, agencia, cliente1);

        // Impressão genérica
        imprimirInformacoes(cliente1);
        imprimirInformacoes(cc);
        imprimirInformacoes(cp);
        imprimirInformacoes(cs);
    }

    public static void imprimirInformacoes(Imprimivel objeto) {
        objeto.imprimirDados();
        System.out.println(); // linha em branco
    }
}
