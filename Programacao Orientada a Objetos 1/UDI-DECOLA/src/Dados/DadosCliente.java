package Dados;

import Util.Cliente;
import Ferramentas.ValidaCPF;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class DadosCliente {
    private static List<Cliente> clientes = new ArrayList<>();

    private static String cpfUsuarioLogado; // Variável para armazenar o CPF do usuário logado
    public static void setCpfUsuarioLogado(String cpf) {
        cpfUsuarioLogado = cpf;
    }
    public static String getCpfUsuarioLogado() {
        return cpfUsuarioLogado;
    }
    public void cadastrarCliente(Cliente novoCliente) {
        clientes.add(novoCliente);
    }

    public static void listar() {
        for (Cliente cliente : clientes) {
            cliente.mostrarDadosCliente();
        }
    }
    public static Cliente buscar(String cpf) {
        Cliente clienteEncontrado = null;
        for (Cliente cliente : clientes) {
            if (cliente.getCpf().equals(cpf)) {
                clienteEncontrado = cliente;
                break;
            }
        }
        if (clienteEncontrado == null) {
            System.out.println("Cliente não encontrado para o CPF: " + cpf); // Debug: imprimir se o cliente não foi encontrado
        }
        return clienteEncontrado;
    }

    public String buscarSenhaPorCPF(String cpf) {
        String senhaEncontrada = null;
        for (Cliente cliente : clientes) {
            if (cliente.getCpf().equals(cpf)) {
                senhaEncontrada = cliente.getSenha();
                break;
            }
        }
        if (senhaEncontrada == null) {
            System.out.println("Senha não encontrada para o CPF: " + cpf); // Debug: imprimir se a senha não foi encontrada
        }
        return senhaEncontrada;
    }

    public boolean excluir(String cpf) {
        Cliente cliente = buscar(cpf);
        if (cliente != null) {
            clientes.remove(cliente);
            return true;
        } else {
            return false;
        }
    }

    public static boolean validarCPF(String cpf) {
        return ValidaCPF.isCPF(cpf);
    }
    public static void cadastrarCliente(String nome, String cpf, String endereco, Date dataNascimento, String email, String senha) {
        // Criar um novo cliente e adicionar à lista
        Cliente novoCliente = new Cliente(nome, cpf, endereco, dataNascimento, email, senha, new Date());
        clientes.add(novoCliente);
        listar();
    }
}