public class Ex01 {
    public static void main(String [] args){
        /*Definição: A associação é um relacionamento entre duas ou mais classes, onde uma classe conhece a outra, mas sem uma dependência forte. Ou seja,
        uma classe pode ter referências para objetos de outra classe.*/

        class Cliente {
            private String nome;
        }

        class Pedido {
            private Cliente cliente;
        }

        /*Neste caso existe uma associação de pedido com cliente onde cada pedido está associado a um cliente, porém o cliente pode existir independemente dos pedidos */
    }
}
