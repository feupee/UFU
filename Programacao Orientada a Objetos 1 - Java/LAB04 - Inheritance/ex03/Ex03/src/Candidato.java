public class Candidato {
    private String nome_completo;
    private String data_nascimento;
    private String genero;
    private float total_bens;
    private boolean releicao;
    private int num_partido;

    public Candidato(String nome_completo, String data_nascimento, String genero,
                     float total_bens, boolean releicao, int num_partido){
        this.nome_completo = nome_completo;
        this.data_nascimento = data_nascimento;
        this.genero = genero;
        this.total_bens = total_bens;
        this.releicao = releicao;
        this.num_partido = num_partido;
    }

    public void mostrar_informacoes(){
        System.out.println("Informações do Candidato:");
        System.out.println("Nome Completo: " + nome_completo);
        System.out.println("Data de Nascimento: " + data_nascimento);
        System.out.println("Gênero: " + genero);
        System.out.println("Total de Bens: R$ " + total_bens);
        System.out.println("Reeleição: " + (releicao ? "Sim" : "Não"));
        System.out.println("Número do Partido: " + num_partido);
    }

    public String getNome_completo() {
        return nome_completo;
    }

    public void setNome_completo(String nome_completo) {
        this.nome_completo = nome_completo;
    }

    public String getData_nascimento() {
        return data_nascimento;
    }

    public void setData_nascimento(String data_nascimento) {
        this.data_nascimento = data_nascimento;
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public float getTotal_bens() {
        return total_bens;
    }

    public void setTotal_bens(float total_bens) {
        this.total_bens = total_bens;
    }

    public boolean isReleicao() {
        return releicao;
    }

    public void setReleicao(boolean releicao) {
        this.releicao = releicao;
    }

    public int getNum_partido() {
        return num_partido;
    }

    public void setNum_partido(int num_partido) {
        this.num_partido = num_partido;
    }
}
