public class VIP extends Ingresso {
    private float valorAdicional;

    public VIP(float valor, float valorAdicional) {
        super(valor);
        this.valorAdicional = valorAdicional;
    }

    public float calcularValorVIP() {
        return getValor() + valorAdicional;
    }
}