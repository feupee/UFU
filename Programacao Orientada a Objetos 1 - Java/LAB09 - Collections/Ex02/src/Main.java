import java.util.Deque;
import java.util.ArrayDeque;
import java.util.NoSuchElementException;

public class Main {
    public static void main(String[] args) {
        Deque<Estudante> fila = new ArrayDeque<>();

        fila.addFirst(new Estudante("Ana", "Rua 1"));
        fila.addLast(new Estudante("Bruno", "Rua 2"));

        boolean sucesso = fila.offerFirst(new Estudante("Carlos", "Rua 3"));
        System.out.println("OfferFirst foi bem-sucedido? " + sucesso);

        Estudante primeiro = fila.peekFirst();
        System.out.println("Primeiro da fila (peekFirst): " + (primeiro != null ? primeiro.getNome() : "null"));

        Estudante ultimo = fila.peekLast();
        System.out.println("Último da fila (peekLast): " + (ultimo != null ? ultimo.getNome() : "null"));

        Estudante removidoComPoll = fila.pollFirst();
        System.out.println("Removido com pollFirst: " + (removidoComPoll != null ? removidoComPoll.getNome() : "null"));

        fila.clear();

        try {
            Estudante erro = fila.removeFirst();
        } catch (NoSuchElementException e) {
            System.out.println("Exceção capturada: tentativa de remover de deque vazio -> " + e.getClass().getSimpleName());
        }

        Estudante vazio = fila.pollLast();
        if (vazio == null) {
            System.out.println("Deque vazio, pollLast retornou null.");
        }
    }
}
