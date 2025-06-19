package Classes;

public abstract class Notificacao {
    protected ContaBancaria contaBancaria;
    protected Transacao transacao;

    public Notificacao(ContaBancaria contaBancaria, Transacao transacao) {
        this.contaBancaria = contaBancaria;
        this.transacao = transacao;
    }

    // Metodo abstrato a ser implementado nas subclasses
    public abstract void enviarNotificacao();
}