package Classes;

import ExceptionsAndInterfaces.Imprimivel;
import ExceptionsAndInterfaces.ValorInvalidoException;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public abstract class ContaBancaria {
    protected String numeroConta;
    protected double saldo;
    protected Date dataAbertura;
    protected Date dataUltimaMovimentacao;
    protected List<Transacao> transacoes;
    protected String senha;
    protected boolean estado;
    protected Cliente[] clientes = new Cliente[2]; //É possível ter dois clientes associados à mesma conta. Um mesmo cliente pode ter diferentes contas bancárias.
    protected Agencia agencia;


    public ContaBancaria(String numeroConta, double saldoInicial, Date dataAbertura, String Senha, boolean status, Cliente cliente, Agencia agencia) {
        this.numeroConta = numeroConta;
        this.saldo = saldoInicial;
        this.dataAbertura = dataAbertura;
        this.dataUltimaMovimentacao = dataAbertura;
        this.transacoes = new ArrayList<>();
        this.senha = Senha;
        this.estado = status;
        this.clientes[0] = cliente;
        this.agencia = agencia;
    }

    public void adicionarCliente(Cliente cliente) {
        if (clientes[0].equals(cliente)) {
            System.out.println("Classes.Cliente já está associado como titular.");
            return;
        }

        if (clientes[1] != null) {
            if (clientes[1].equals(cliente)) {
                System.out.println("Classes.Cliente já está associado como conjunto.");
            } else {
                throw new IllegalStateException("A conta já possui dois clientes.");
            }
        } else {
            clientes[1] = cliente;
        }
    }

    public void removerCliente(Cliente cliente) {
        if (clientes[0] != null && clientes[0].equals(cliente)) {
            // Se for o titular (posição 0), vamos remover e reorganizar
            clientes[0] = clientes[1]; // Se existir um conjunto, ele vira titular
            clientes[1] = null;
            System.out.println("Titular removido. Classes.Cliente conjunto promovido a titular.");
        } else if (clientes[1] != null && clientes[1].equals(cliente)) {
            clientes[1] = null;
            System.out.println("Classes.Cliente conjunto removido.");
        } else {
            System.out.println("Classes.Cliente não está associado a esta conta.");
        }
    }

    // Metodo para sacar
    public void sacar(double valor, String canal) throws ValorInvalidoException {
        if (valor > saldo) {
            throw new ValorInvalidoException("Saldo insuficiente para saque!");
        }
        Transacao transacao = new Transacao(this, valor, "saque", canal);
        saldo -= valor;
        atualizarDataUltimaMovimentacao();
        transacoes.add(transacao);
        enviarNotificacao(transacao);  // Envia a notificação após o saque
    }

    // Metodo para depositar
    public void depositar(double valor, String canal) {
        Transacao transacao = new Transacao(this, valor, "depósito", canal);
        saldo += valor;
        atualizarDataUltimaMovimentacao();
        transacoes.add(transacao);
        enviarNotificacao(transacao);
    }

    // Metodo para consultar saldo
    public void consultarSaldo(String canal) {
        Transacao transacao = new Transacao(this,0, "consultar saldo", canal);
        transacoes.add(transacao);
        System.out.printf("Saldo atual: R$ %.2f\n", getSaldo());
    }

    // Metodo para efetuar pagamento
    public void efetuarPagamento(double valor, ContaBancaria contaBancariadestino, String canal) throws ValorInvalidoException {
        if (valor > saldo) {
            throw new ValorInvalidoException("Saldo insuficiente para transferencia!");
        }
        Transacao transacao = new Transacao(this, valor, "efetuar pagamento", canal);
        saldo -= valor;
        atualizarDataUltimaMovimentacao();
        transacoes.add(transacao);
        contaBancariadestino.depositar(valor, canal);
        enviarNotificacao(transacao);
    }

    private void atualizarDataUltimaMovimentacao() {
        this.dataUltimaMovimentacao = new Date();
    }

    // Exibir historico de transacoes
    public void exibirTransacoes() {
        System.out.println("\n=== HISTÓRICO DE TRANSAÇÕES - CONTA " + numeroConta + " ===");
        for (Transacao t : transacoes) {
            System.out.println(t);
        }
    }

    public String getNumeroConta() {
        return numeroConta;
    }

    public void setNumeroConta(String numeroConta) {
        this.numeroConta = numeroConta;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public Date getDataAbertura() {
        return dataAbertura;
    }

    public void setDataAbertura(Date dataAbertura) {
        this.dataAbertura = dataAbertura;
    }

    public Date getDataUltimaMovimentacao() {
        return dataUltimaMovimentacao;
    }

    public void setDataUltimaMovimentacao(Date dataUltimaMovimentacao) {
        this.dataUltimaMovimentacao = dataUltimaMovimentacao;
    }

    public List<Transacao> getTransacoes() {
        return transacoes;
    }

    public void setTransacoes(List<Transacao> transacoes) {
        this.transacoes = transacoes;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public boolean isEstado() {
        return estado;
    }

    public void setEstado(boolean estado) {
        this.estado = estado;
    }

    public Cliente[] getClientes() {
        return clientes;
    }

    public void setClientes(Cliente[] clientes) {
        this.clientes = clientes;
    }

    public Agencia getAgencia() {
        return agencia;
    }

    public void setAgencia(Agencia agencia) {
        this.agencia = agencia;
    }

    // Metodo para enviar notificacoes apos a transacao
    private void enviarNotificacao(Transacao transacao) {
        Notificacao notificacao = switch (transacao.getTipo()) {
            case "saque" -> new NotificacaoSaque(this, transacao);
            case "depósito" -> new NotificacaoDeposito(this, transacao);
            case "efetuar pagamento" -> new NotificacaoPagamento(this, transacao);
            default -> throw new IllegalArgumentException("Tipo de transação desconhecido");
        };
        notificacao.enviarNotificacao();
    }
}