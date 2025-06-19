import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        // Criando um vetor de produtos
        Produto[] produtos = new Produto[4];

        // Inicializando produtos
        produtos[0] = new Produto("Caneta", 2.50f, 10);
        produtos[1] = new Produto("Caderno", 15.00f, 5);
        produtos[2] = new Produto("Borracha", 1.20f, 20);
        produtos[3] = new Produto("Lápis", 1.50f, 15);

        // Exibindo produtos antes da ordenação
        System.out.println("Produtos antes da ordenação:");
        for (Produto p : produtos) {
            p.imprimeProduto();
        }

        // Ordenando pelo nome usando Selection Sort
        ordenarPorNome(produtos);

        // Exibindo produtos após a ordenação
        System.out.println("\nProdutos após a ordenação:");
        for (Produto p : produtos) {
            p.imprimeProduto();
        }
    }

    // Método para ordenar o vetor pelo nome usando Selection Sort
    public static void ordenarPorNome(Produto[] produtos) {
        int n = produtos.length;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (produtos[j].getNome().compareTo(produtos[minIndex].getNome()) < 0) {
                    minIndex = j;
                }
            }
            // Troca os elementos
            Produto temp = produtos[i];
            produtos[i] = produtos[minIndex];
            produtos[minIndex] = temp;
        }
    }
}