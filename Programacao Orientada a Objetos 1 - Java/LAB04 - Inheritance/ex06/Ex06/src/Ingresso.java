public class Ingresso {
    protected float valor;

    public Ingresso(float valor) {
        this.valor = valor;
    }

    public void escreveValor() {
        System.out.println("Valor do ingresso: R$ " + valor);
    }

    public float getValor() {
        return valor;
    }
}