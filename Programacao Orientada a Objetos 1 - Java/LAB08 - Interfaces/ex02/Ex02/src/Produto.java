public class Produto implements Classificavel {
    private int codigo;

    public Produto(int codigo) {
        this.codigo = codigo;
    }

    public int getCodigo() {
        return codigo;
    }

    @Override
    public int comparar(Classificavel o) {
        Produto compara = (Produto) o;
        return this.codigo - compara.codigo;
    }

    @Override
    public String toString() {
        return "Código do produto = " + codigo;
    }
}
