public class CandidatoPrefeito extends Candidato{
    private String nome_vice;
    private String partido_vice;

    public CandidatoPrefeito(String nome_completo,
                             String data_nascimento,
                             String genero,
                             float total_bens,
                             boolean releicao,
                             int num_partido,
                             String nome_vice,
                             String partido_vice) {
        super(nome_completo, data_nascimento, genero, total_bens, releicao, num_partido);
        this.nome_vice = nome_vice;
        this.partido_vice = partido_vice;
    }

    public String getNome_vice() {
        return nome_vice;
    }

    public void setNome_vice(String nome_vice) {
        this.nome_vice = nome_vice;
    }

    public String getPartido_vice() {
        return partido_vice;
    }

    public void setPartido_vice(String partido_vice) {
        this.partido_vice = partido_vice;
    }

    public void mostrar_informacoes(){
        super.mostrar_informacoes();
        System.out.println("Nome do Vice: " + nome_vice);
        System.out.println("Partido do Vice: " + partido_vice);
    }
}
