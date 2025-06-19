package Classes;

public class NotificacaoDeposito extends Notificacao {
    public NotificacaoDeposito(ContaBancaria contaBancaria, Transacao transacao) {
        super(contaBancaria, transacao);
    }

    @Override
    public void enviarNotificacao() {
        System.out.println("Notificação de depósito: Você depositou R$ " + transacao.getValor() + " na conta " + contaBancaria.getNumeroConta());

        // Se for uma Conta Poupanca, avisa sobre o rendimento mensal
        if (contaBancaria instanceof ContaPoupanca) {
            double rendimentoMensal = ((ContaPoupanca) contaBancaria).getRendimento_mesAtual();
            System.out.println("Aviso: Seu saldo agora está rendendo " + rendimentoMensal + "% de rendimento mensal.");
        }
    }
}