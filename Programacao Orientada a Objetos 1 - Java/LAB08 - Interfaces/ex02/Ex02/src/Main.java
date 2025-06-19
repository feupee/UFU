public class Main {
    public static void main(String[] args) {
        Classificador classificador = new Classificador();

        Produto[] produtos = {
                new Produto(102),
                new Produto(55),
                new Produto(230)
        };

        Cliente[] clientes = {
                new Cliente("Joana"),
                new Cliente("Carlos"),
                new Cliente("Beatriz")
        };

        Servico[] servicos = {
                new Servico(89.99),
                new Servico(29.99),
                new Servico(55.50)
        };

        classificador.ordena(produtos);
        System.out.println("Produtos ordenados por código:");
        for (Produto p : produtos) System.out.println(p);

        classificador.ordena(clientes);
        System.out.println("\nClientes ordenados por nome:");
        for (Cliente c : clientes) System.out.println(c);

        classificador.ordena(servicos);
        System.out.println("\nServiços ordenados por preço:");
        for (Servico s : servicos) System.out.println(s);
    }
}
