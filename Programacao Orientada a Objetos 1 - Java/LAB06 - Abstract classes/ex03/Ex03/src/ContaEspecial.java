public class ContaEspecial extends ContaCorrente{
    private float limite;
    public ContaEspecial(float val, int num, int pwd, float limite) {
        super(val, num, pwd);

        // Se o limite for zero, cria uma ContaComum
        if (limite == 0) {
            System.out.println("Criando ContaComum (limite == 0).");
            new ContaComum(val, num, pwd);
        } else {
            this.limite = limite;
        }
    }
    @Override
    public boolean debitaValor(float val, int pwd) {
        if (pwd != senha) return false;      // Valida senha
        if (estado != 1) return false;       // Conta deve estar ativa
        if (val <= 0) return false;          // Valor a debitar deve ser positivo
        if (val > (saldo + limite)) return false; // Saldo + limite insuficiente

        saldo -= val;

        return true;
    }

    public void setLimite(float novoLimite) {
        this.limite = novoLimite;

        // Se o novo limite for zero e o saldo for zero, torna ContaComum
        if (novoLimite == 0 && saldo == 0) {
            new ContaComum(saldo, numConta, senha);
        }
    }
}
