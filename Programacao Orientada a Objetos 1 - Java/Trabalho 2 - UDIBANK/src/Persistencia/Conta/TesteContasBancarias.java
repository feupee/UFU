package Persistencia.Conta;

import Classes.*;
import ExceptionsAndInterfaces.ValorInvalidoException;
import Persistencia.Cliente.CarregadorAgencias;
import Persistencia.Conta.CarregadorClientes;
import Persistencia.Conta.ContaBancariaBinarioIO;
import Persistencia.Conta.GeradorContasBancarias;

import java.io.IOException;
import java.util.List;

public class TesteContasBancarias {
    public static void main(String[] args) {
        // 1. Carregar clientes e agências existentes
        List<Cliente> clientes = CarregadorClientes.carregarTodosClientes(5);
        List<Agencia> agencias = CarregadorAgencias.carregarTodasAgencias(5);

        if (clientes.isEmpty() || agencias.isEmpty()) {
            System.out.println("É necessário ter clientes e agências cadastrados primeiro.");
            return;
        }

        // 2. Gerar e salvar contas
        for (int i = 0; i < clientes.size(); i++) {
            Cliente cliente = clientes.get(i);
            Agencia agencia = agencias.get(i % agencias.size()); // Distribui pelas agências

            try {
                // Gerar conta aleatória
                ContaBancaria conta = GeradorContasBancarias.gerarContaAleatoria(cliente, agencia);

                // Nome do arquivo
                String nomeArquivo = String.format("dados/conta_%s_%04d.bin",
                        getTipoConta(conta), i+1);

                // Salvar conta
                ContaBancariaBinarioIO.salvarConta(conta, nomeArquivo);

                // Mostrar informações
                System.out.println("\n----------------------------------------");
                System.out.println("Conta gerada e salva: " + nomeArquivo);
                System.out.println("Tipo: " + getTipoConta(conta));
                System.out.println("Número: " + conta.getNumeroConta());
                System.out.println("Cliente: " + cliente.getNome());
                System.out.println("Agência: " + agencia.getNmrAgencia());
                System.out.printf("Saldo inicial: R$ %.2f%n", conta.getSaldo());

                // Mostrar atributos específicos
                if (conta instanceof ContaCorrente) {
                    ContaCorrente cc = (ContaCorrente) conta;
                    System.out.printf("Limite cheque especial: R$ %.2f%n", cc.getLimite_chequeEspecial());
                }
                else if (conta instanceof ContaPoupanca) {
                    ContaPoupanca cp = (ContaPoupanca) conta;
                    System.out.printf("Rendimento: %.2f%% ao mês%n", cp.getRendimento_mesAtual());
                }
                else if (conta instanceof ContaSalario) {
                    ContaSalario cs = (ContaSalario) conta;
                    System.out.printf("Limite saque: R$ %.2f%n", cs.getLimite_saque());
                }

            } catch (IOException e) {
                System.err.println("Erro ao gerar conta: " + e.getMessage());
            }
        }

        System.out.println("\n----------------------------------------");
        System.out.println("Operação concluída. Contas salvas em arquivos binários.");
    }

    private static String getTipoConta(ContaBancaria conta) {
        if (conta instanceof ContaCorrente) return "corrente";
        if (conta instanceof ContaPoupanca) return "poupanca";
        if (conta instanceof ContaSalario) return "salario";
        return "desconhecido";
    }
}