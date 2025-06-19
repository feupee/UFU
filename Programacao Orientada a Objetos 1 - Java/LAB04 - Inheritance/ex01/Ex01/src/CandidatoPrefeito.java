public class CandidatoPrefeito {
    private String nome_completo;
    private String data_nascimento;
    private String genero;
    private float total_bens;
    private boolean releicao;
    private int num_partido;
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
        this.nome_completo = nome_completo;
        this.data_nascimento = data_nascimento;
        this.genero = genero;
        this.total_bens = total_bens;
        this.releicao = releicao;
        this.num_partido = num_partido;
        this.nome_vice = nome_vice;
        this.partido_vice = partido_vice;
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
}
