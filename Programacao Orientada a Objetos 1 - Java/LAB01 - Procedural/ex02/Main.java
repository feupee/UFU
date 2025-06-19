package ex02;
import java.util.Scanner;

public class Main {
    // Função alteraPreco
    // Desc: modifica o preço de um produto
    // Entrada:
    //    preco: preço do produto (array para simular passagem por referência)
    //    porcentagem: valor percentual a ser alterado, podendo
    //    ser negativo para diminuir valores
    // Retorno:
    //    true - sucesso
    //    false - erro
    public static boolean alteraPreco(float[] preco, int index, float porcentagem) {
        if (porcentagem > -100) {
            float temp = 1 + porcentagem / 100;
            preco[index] *= temp;
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] nome = new String[4];
        float[] preco = new float[4];
        int[] qtdEstoque = new int[4];

        for (int i = 0; i < 4; i++) {
            System.out.println("\nInforme o nome, o preço e a quantidade em estoque do produto:");
            nome[i] = scanner.next();
            preco[i] = scanner.nextFloat();
            qtdEstoque[i] = scanner.nextInt();
        }

        System.out.println("\nAumentando o preço em 10% do produto 1 e 3");
        if (!alteraPreco(preco, 0, -110)) {
            System.out.println("\nErro: preço do produto 1 não alterado. Porcentagem inválida");
        }
        alteraPreco(preco, 2, 10);

        System.out.println("\nReduzindo o preço em 5% do produto 2");
        if (!alteraPreco(preco, 1, -5)) {
            System.out.println("\nErro: preço não alterado. Porcentagem inválida");
        } else {
            System.out.println("\nPreço alterado com sucesso");
        }

        System.out.println("\nAlterando o preço do produto 3");
        if (!alteraPreco(preco, 3, -110)) {
            System.out.println("\nErro: preço não alterado. Porcentagem inválida");
        }

        System.out.println("\nProdutos Cadastrados:");
        for (int i = 0; i < 4; i++) {
            System.out.printf("\nProduto: %s\nPreço: %.2f\nEstoque: %d\n", nome[i], preco[i], qtdEstoque[i]);
        }

        scanner.close();
    }
}
