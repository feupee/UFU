public class Candidato {
    public String nome_completo;
    public String data_de_nascimento;
    public String genero;
    public String cargo_preterido;
    float total_de_bens;
    public boolean reeleicao;
    public int num_do_partido;

    public void mostrarInformacoes() {
        System.out.println("Nome Completo: " + nome_completo);
        System.out.println("Data de Nascimento: " + data_de_nascimento);
        System.out.println("Gênero: " + genero);
        System.out.println("Cargo Pretendido: " + cargo_preterido);
        System.out.println("Total de Bens: R$ " + total_de_bens);
        System.out.println("Reeleição: " + reeleicao);
        System.out.println("Número do Partido: " + num_do_partido);
    }
}