public class Servico implements Classificavel {
    private double preco;

    public Servico(double preco) {
        this.preco = preco;
    }

    public double getPreco() {
        return preco;
    }

    @Override
    public int comparar(Classificavel o) {
        Servico compara = (Servico) o;
        return Double.compare(this.preco, compara.preco);
    }

    @Override
    public String toString() {
        return "Preço do serviço = " + preco;
    }
}
