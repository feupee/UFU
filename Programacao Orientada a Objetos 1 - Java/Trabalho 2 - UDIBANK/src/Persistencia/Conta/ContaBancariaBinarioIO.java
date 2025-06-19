package Persistencia.Conta;

import Classes.*;
import ExceptionsAndInterfaces.ValorInvalidoException;

import java.io.*;
import java.util.Date;
import java.util.List;

public class ContaBancariaBinarioIO {

    public static void salvarConta(ContaBancaria conta, String nomeArquivo) throws IOException {
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream(nomeArquivo))) {
            // Dados básicos da conta
            dos.writeUTF(conta.getNumeroConta());
            dos.writeDouble(conta.getSaldo());
            dos.writeLong(conta.getDataAbertura().getTime());
            dos.writeUTF(conta.getSenha());
            dos.writeBoolean(conta.isEstado());

            // Dados do cliente (apenas CPF como referência)
            dos.writeUTF(conta.getClientes()[0].getCPF());

            // Dados da agência (apenas número como referência)
            dos.writeUTF(conta.getAgencia().getNmrAgencia());

            // Tipo específico da conta e atributos
            if (conta instanceof ContaCorrente) {
                dos.writeUTF("CORRENTE");
                ContaCorrente cc = (ContaCorrente) conta;
                dos.writeDouble(cc.getLimite_chequeEspecial());
                dos.writeDouble(cc.getValor_taxaAdministrativa());
                dos.writeUTF(cc.getNrmConta());
            }
            else if (conta instanceof ContaPoupanca) {
                dos.writeUTF("POUPANCA");
                ContaPoupanca cp = (ContaPoupanca) conta;
                dos.writeDouble(cp.getRendimento_mesAtual());
            }
            else if (conta instanceof ContaSalario) {
                dos.writeUTF("SALARIO");
                ContaSalario cs = (ContaSalario) conta;
                dos.writeDouble(cs.getLimite_saque());
                dos.writeDouble(cs.getLimite_transferencia());
            }
        }
    }

    public static ContaBancaria carregarConta(String nomeArquivo, List<Cliente> clientes, List<Agencia> agencias)
            throws IOException, ValorInvalidoException {

        try (DataInputStream dis = new DataInputStream(new FileInputStream(nomeArquivo))) {
            // Dados básicos
            String numeroConta = dis.readUTF();
            double saldo = dis.readDouble();
            Date dataAbertura = new Date(dis.readLong());
            String senha = dis.readUTF();
            boolean estado = dis.readBoolean();

            // Referências
            String cpfCliente = dis.readUTF();
            String numeroAgencia = dis.readUTF();

            // Encontrar cliente e agência
            Cliente cliente = clientes.stream()
                    .filter(c -> c.getCPF().equals(cpfCliente))
                    .findFirst()
                    .orElseThrow(() -> new IOException("Cliente não encontrado: " + cpfCliente));

            Agencia agencia = agencias.stream()
                    .filter(a -> a.getNmrAgencia().equals(numeroAgencia))
                    .findFirst()
                    .orElseThrow(() -> new IOException("Agência não encontrada: " + numeroAgencia));

            // Tipo específico
            String tipoConta = dis.readUTF();

            switch(tipoConta) {
                case "CORRENTE":
                    return new ContaCorrente(
                            numeroConta, saldo, dataAbertura,
                            dis.readDouble(), // limite cheque especial
                            dis.readDouble(), // taxa administrativa
                            dis.readUTF(),    // número conta
                            senha, estado, agencia, cliente
                    );

                case "POUPANCA":
                    return new ContaPoupanca(
                            numeroConta, saldo, dataAbertura,
                            dis.readDouble(), // rendimento
                            senha, estado, agencia, cliente
                    );

                case "SALARIO":
                    return new ContaSalario(
                            numeroConta, saldo, dataAbertura,
                            dis.readDouble(), // limite saque
                            dis.readDouble(), // limite transferência
                            senha, estado, agencia, cliente
                    );

                default:
                    throw new IOException("Tipo de conta desconhecido: " + tipoConta);
            }
        }
    }
}
