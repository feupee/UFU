package Util;

import Ferramentas.Pesquisa;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.text.SimpleDateFormat;

public class Cliente extends Pessoa {
    private Date dataCadastro;
    private int numeroCompras;
    private boolean clienteVIP;
    private double descontoVIP;
    private String senha;
    private String email;
    private Date dataVip;
    private boolean ehFuncionario;
    private List<Pesquisa> pesquisas; // Lista de pesquisas feitas pelo cliente
    private List<Compras> compras; // Lista de compras feitas pelo cliente

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public boolean isEhFuncionario() {
        return ehFuncionario;
    }

    public void setEhFuncionario(boolean ehFuncionario) {
        this.ehFuncionario = ehFuncionario;
    }

    // Construtor
    public Cliente(String nome, String cpf, String enderecoCompleto, Date dataNascimento, String email, String senha, Date dataCadastro) {
        super(nome, null, enderecoCompleto, dataNascimento);
        this.setCpf(cpf);
        this.email = email;
        this.senha = senha;
        this.dataCadastro = dataCadastro;
        this.numeroCompras = 0;
        this.clienteVIP = false;
        this.descontoVIP = 0.0;
        this.dataVip = null;
        this.compras = new ArrayList<>();
        this.pesquisas = new ArrayList<>();
        this.ehFuncionario = false;
    }


    public Cliente() {
        super("Cliente Default", null, "Endereço Default", new Date()); // Não define o CPF aqui
        this.setCpf("15285426650");
        this.email = "cliente_default@example.com";
        this.senha = "123";
        this.dataCadastro = new Date();
        this.numeroCompras = 0;
        this.clienteVIP = false;
        this.descontoVIP = 0.0;
        this.dataVip = null;
        this.compras = new ArrayList<>();
        this.pesquisas = new ArrayList<>();
        this.ehFuncionario = false;
    }

    // Método para adicionar uma pesquisa feita pelo cliente
    public void adicionarPesquisa(Pesquisa pesquisa) {
        if (pesquisas == null) {
            pesquisas = new ArrayList<>();
        }
        pesquisas.add(pesquisa);
    }

    public boolean validarSenha(String senhaDigitada) {
        // Verificar se a senha tem pelo menos 8 caracteres
        if (senha.length() < 8) {
            return false;
        }

        // Verificar se a senha contém pelo menos um número
        boolean temNumero = false;
        for (char c : senha.toCharArray()) {
            if (Character.isDigit(c)) {
                temNumero = true;
                break;
            }
        }
        if (!temNumero) {
            return false;
        }

        // Verificar se a senha contém pelo menos uma letra minúscula
        boolean temMinuscula = false;
        for (char c : senha.toCharArray()) {
            if (Character.isLowerCase(c)) {
                temMinuscula = true;
                break;
            }
        }
        if (!temMinuscula) {
            return false;
        }

        // Verificar se a senha contém pelo menos uma letra maiúscula
        boolean temMaiuscula = false;
        for (char c : senha.toCharArray()) {
            if (Character.isUpperCase(c)) {
                temMaiuscula = true;
                break;
            }
        }
        if (!temMaiuscula) {
            return false;
        }

        // Verificar se a senha contém pelo menos um caractere especial
        String caracteresEspeciais = "!@#$%&*()_+-=[]|,./?><";
        boolean temEspecial = false;
        for (char c : senha.toCharArray()) {
            if (caracteresEspeciais.contains(String.valueOf(c))) {
                temEspecial = true;
                break;
            }
        }
        return temEspecial;

        // Se passou por todas as verificações, a senha é válida
    }

    public void mostrarDadosCliente() {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        System.out.println("Nome: " + getNome());
        System.out.println("CPF: " + getCpf());
        System.out.println("Endereço: " + getEnderecoCompleto());
        System.out.println("Data de Nascimento: " + sdf.format(getDataNascimento()));
        System.out.println("Email: " + email);
        System.out.println("Data de Cadastro: " + sdf.format(dataCadastro));
        System.out.println("Número de Util.Compras: " + numeroCompras);
        System.out.println("Util.Cliente VIP: " + (clienteVIP ? "Sim" : "Não"));
        if (clienteVIP) {
            System.out.println("Desconto VIP: " + descontoVIP);
            System.out.println("Data VIP: " + (dataVip != null ? sdf.format(dataVip) : "N/A"));
        }
        System.out.println("Pesquisas Realizadas: " + (pesquisas != null ? pesquisas.size() : 0));
        System.out.println("Util.Compras Realizadas: " + (compras != null ? compras.size() : 0));
        System.out.println("----------------------------------------");
    }

    // Métodos getters e setters específicos para a classe Util.Cliente
    public Date getDataCadastro() {
        return dataCadastro;
    }
    public void setDataCadastro(Date dataCadastro) {
        this.dataCadastro = dataCadastro;
    }
    public int getNumeroCompras() {
        return numeroCompras;
    }
    public void setNumeroCompras(int numeroCompras) {
        this.numeroCompras = numeroCompras;
    }
    public boolean isClienteVIP() {
        return clienteVIP;
    }
    public void setClienteVIP(boolean clienteVIP) {
        this.clienteVIP = clienteVIP;
    }
    public double getDescontoVIP() {
        return descontoVIP;
    }
    public void setDescontoVIP(double descontoVIP) {
        this.descontoVIP = descontoVIP;
    }
    public Date getDataVip() {
        return dataVip;
    }
    public void setDataVip(Date dataVip) {
        this.dataVip = dataVip;
    }
    public String getEmail() {
        return email;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public List<Pesquisa> getPesquisas() {
        return pesquisas;
    }
    public void setPesquisas(List<Pesquisa> pesquisas) {
        this.pesquisas = pesquisas;
    }
    public void setCompras(List<Compras> compras) {
        this.compras = compras;
    }
    public void adicionarCompra(Compras novaCompra) {
        compras.add(novaCompra);
    }
    public List<Compras> getCompras() {
        return compras;
    }
}