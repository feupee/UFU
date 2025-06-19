public class Produto {
    private String nome;
    private float preco;
    private int quantidade;

    // Construtor padrão
    public Produto() {
        this.nome = "Produto Padrão";
        this.preco = 0.0f;
        this.quantidade = 0;
    }

    // Construtor com parâmetros
    public Produto(String nome, float preco, int quantidade) {
        this.nome = nome;
        this.preco = preco;
        this.quantidade = quantidade;
    }

    // Métodos getters
    public String getNome() {
        return nome;
    }

    public float getPreco() {
        return preco;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void alteraPreco(float porcentagem) {
        this.preco += this.preco * (porcentagem / 100);
    }

    public void imprimeProduto() {
        System.out.println("Nome: " + nome + ", Preço: R$" + preco + ", Quantidade: " + quantidade);
    }
}