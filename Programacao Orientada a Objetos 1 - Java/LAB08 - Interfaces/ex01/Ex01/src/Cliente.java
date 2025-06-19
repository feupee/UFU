public class Cliente implements Classificavel {
    private String nome;

    public Cliente(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    @Override
    public boolean eMenorQue(Classificavel o) {
        Cliente compara = (Cliente) o;
        return this.nome.compareTo(compara.nome) < 0;
    }

    @Override
    public String toString() {
        return "Nome do(a) cliente = " + nome;
    }
}
