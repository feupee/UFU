public class Ex03 {
    public static void main(String [] args){

        /*Definição: Composição é um tipo mais forte de agregação. Aqui, a parte não pode existir sem o todo, ou seja, se o objeto todo for destruído, as partes também serão destruídas.
        A relação é mais estreita e a parte é dependente do todo.*/

        class Casa {
            private Quarto array_quartos[N];
        }

        class Quarto {
            private String nome;

        }

        /*Uma Casa tem Quartos. Se a Casa for destruída, os Quartos também deixam de existir.*/
    }
}
