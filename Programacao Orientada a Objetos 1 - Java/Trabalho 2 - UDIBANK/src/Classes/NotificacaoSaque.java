package Classes;

public class NotificacaoSaque extends Notificacao {
    public NotificacaoSaque(ContaBancaria contaBancaria, Transacao transacao) {
        super(contaBancaria, transacao);
    }

    @Override
    public void enviarNotificacao() {
        System.out.println("Notificação de saque: Você realizou um saque de R$ " + transacao.getValor() + " na conta " + contaBancaria.getNumeroConta());

        // Se for uma Conta Corrente, avisa sobre o limite do cheque especial
        if (contaBancaria instanceof ContaCorrente) {
            double limiteChequeEspecial = ((ContaCorrente) contaBancaria).getLimite_chequeEspecial();
            System.out.println("Aviso: Seu limite de cheque especial é R$ " + limiteChequeEspecial);
        }
    }
}