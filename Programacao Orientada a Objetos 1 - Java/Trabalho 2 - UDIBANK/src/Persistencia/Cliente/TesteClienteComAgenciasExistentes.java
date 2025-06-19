package Persistencia.Cliente;

import Classes.Agencia;
import Classes.Cliente;
import ExceptionsAndInterfaces.ValorInvalidoException;
import Persistencia.BancoDados;

import java.io.IOException;
import java.util.List;

public class TesteClienteComAgenciasExistentes {
    public static void main(String[] args) {
        List<Agencia> agencias = CarregadorAgencias.carregarTodasAgencias(5);

        if (agencias.isEmpty()) {
            System.out.println("Nenhuma agência encontrada. Gere as agências primeiro.");
            return;
        }

        // 2. Gerar e salvar 5 clientes distribuídos pelas agências
        for (int i = 1; i <= 5; i++) {
            try {
                Agencia agencia = agencias.get((i-1) % agencias.size());

                Cliente cliente = GeradorClientes.gerarClienteFicticio(agencia);

                String nomeArquivo = String.format("dados/cliente_%04d.bin", i);

                ClienteBinarioIO.salvarCliente(cliente, nomeArquivo);

                System.out.println("\n----------------------------------------");
                System.out.println("Cliente gerado e salvo: " + nomeArquivo);
                System.out.println("CPF: " + cliente.getCPF());
                System.out.println("Nome: " + cliente.getNome());
                System.out.println("Agência: " + agencia.getNmrAgencia() + " - " + agencia.getNmAgencia());
                System.out.println("Cidade: " + agencia.getCidade() + "/" + agencia.getEstado());
                System.out.println("Idade: " + (2023 - cliente.getData_nascimento().getYear() - 1900) + " anos");

            } catch (ValorInvalidoException | IOException e) {
                System.err.println("Erro ao gerar ou salvar cliente: " + e.getMessage());
            }
        }

        System.out.println("\n----------------------------------------");
        System.out.println("Operação concluída. 5 clientes foram salvos em arquivos binários.");
        System.out.println("Distribuição por agência:");

    }
}