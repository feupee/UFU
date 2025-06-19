package Persistencia.Cliente;

import Classes.Agencia;
import Classes.Cliente;
import ExceptionsAndInterfaces.ValorInvalidoException;

import java.io.*;
import java.util.Date;
import java.util.List;

public class ClienteBinarioIO {

    public static void salvarCliente(Cliente cliente, String nomeArquivo) throws IOException {
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream(nomeArquivo))) {
            // Dados da Pessoa (superclasse)
            dos.writeUTF(cliente.getCPF());
            dos.writeUTF(cliente.getNome());
            dos.writeUTF(cliente.getEndereco_completo());
            dos.writeUTF(cliente.getEstado_civil());
            dos.writeUTF(cliente.getEscolaridade());
            dos.writeLong(cliente.getData_nascimento().getTime());

            // Dados específicos do Cliente
            dos.writeUTF(cliente.getAgencia().getNmrAgencia()); // Salva apenas o número para referência
        }
    }

    public static Cliente carregarCliente(String nomeArquivo, Agencia agencia) throws IOException, ValorInvalidoException {
        try (DataInputStream dis = new DataInputStream(new FileInputStream(nomeArquivo))) {
            // Dados da Pessoa
            String cpf = dis.readUTF();
            String nome = dis.readUTF();
            String endereco = dis.readUTF();
            String estadoCivil = dis.readUTF();
            String escolaridade = dis.readUTF();
            Date dataNascimento = new Date(dis.readLong());

            // Dados do Cliente
            String numeroAgencia = dis.readUTF(); // Pode ser usado para validação

            if (!agencia.getNmrAgencia().equals(numeroAgencia)) {
                throw new IOException("O cliente pertence a outra agência (esperada: " +
                        numeroAgencia + ", encontrada: " + agencia.getNmrAgencia() + ")");
            }

            return new Cliente(cpf, nome, endereco, estadoCivil, escolaridade, dataNascimento, agencia);
        }
    }

    // Modifique o método de carregar cliente para atualizar a agência
    public static Cliente carregarCliente(String nomeArquivo, List<Agencia> agencias) throws IOException, ValorInvalidoException {
        try (DataInputStream dis = new DataInputStream(new FileInputStream(nomeArquivo))) {
            // Dados da Pessoa
            String cpf = dis.readUTF();
            String nome = dis.readUTF();
            String endereco = dis.readUTF();
            String estadoCivil = dis.readUTF();
            String escolaridade = dis.readUTF();
            Date dataNascimento = new Date(dis.readLong());

            // Dados do Cliente
            String numeroAgencia = dis.readUTF();

            // Encontrar a agência correta
            Agencia agencia = agencias.stream()
                    .filter(a -> a.getNmrAgencia().equals(numeroAgencia))
                    .findFirst()
                    .orElseThrow(() -> new IOException("Agência " + numeroAgencia + " não encontrada"));

            Cliente cliente = new Cliente(cpf, nome, endereco, estadoCivil, escolaridade, dataNascimento, agencia);

            return cliente;
        }
    }
}