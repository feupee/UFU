package Persistencia.Conta;

import Classes.Agencia;
import Classes.Cliente;
import ExceptionsAndInterfaces.ValorInvalidoException;
import Persistencia.Cliente.CarregadorAgencias;
import Persistencia.Cliente.ClienteBinarioIO;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CarregadorClientes {
    public static List<Cliente> carregarTodosClientes(int quantidade) {
        List<Cliente> clientes = new ArrayList<>();
        List<Agencia> agencias = CarregadorAgencias.carregarTodasAgencias(quantidade);

        for (int i = 1; i <= quantidade; i++) {
            String nomeArquivo = String.format("dados/cliente_%04d.bin", i);
            try {
                Cliente cliente = ClienteBinarioIO.carregarCliente(nomeArquivo, agencias);
                clientes.add(cliente);
                System.out.println("Cliente carregado: " + cliente.getNome() + " - " + cliente.getCPF());
            } catch (IOException | ValorInvalidoException e) {
                System.err.println("Erro ao carregar " + nomeArquivo + ": " + e.getMessage());
            }
        }

        return clientes;
    }
}