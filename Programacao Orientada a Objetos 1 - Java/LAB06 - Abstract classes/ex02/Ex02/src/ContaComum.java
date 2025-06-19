public class ContaComum extends ContaCorrente{
    public ContaComum(float val, int num, int pwd) {
        super(val, num, pwd);
    }

    @Override
    public boolean debitaValor(float val, int pwd) {
        if (pwd != senha) return false;      // Valida senha
        if (estado != 1) return false;       // Conta deve estar ativa
        if (val <= 0) return false;          // Valor a debitar deve ser positivo
        if (val > saldo) return false;       // Saldo insuficiente

        saldo -= val;

        if (saldo == 0) estado = 2;          // Torna a conta inativa se saldo for zero
        return true;
    }
}
