public class Candidato {
    protected String nome_completo;
    protected String data_nascimento;
    protected String genero;
    protected float total_bens;
    protected boolean releicao;
    protected int num_partido;

    public Candidato(String nome_completo, String data_nascimento, String genero,
                     float total_bens, boolean releicao, int num_partido){
        this.nome_completo = nome_completo;
        this.data_nascimento = data_nascimento;
        this.genero = genero;
        this.total_bens = total_bens;
        this.releicao = releicao;
        this.num_partido = num_partido;
    }

}
