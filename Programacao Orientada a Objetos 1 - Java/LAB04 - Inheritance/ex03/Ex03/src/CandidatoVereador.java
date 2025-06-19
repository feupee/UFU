public class CandidatoVereador extends Candidato{
    private String tresdigitos;
    private String bairro;

    public CandidatoVereador(Candidato candidato, String tresdigitos, String bairro){
        super(candidato.getNome_completo(), candidato.getData_nascimento(), candidato.getGenero(),
                candidato.getTotal_bens(), candidato.isReleicao(), candidato.getNum_partido());
        this.tresdigitos = tresdigitos;
        this.bairro = bairro;
    }

    public CandidatoVereador(String nome_completo,
                             String data_nascimento,
                             String genero,
                             float total_bens,
                             boolean releicao,
                             int num_partido,
                             String tresdigitos,
                             String bairro) {
        super(nome_completo, data_nascimento, genero, total_bens, releicao, num_partido);
        this.tresdigitos = tresdigitos;
        this.bairro = bairro;
    }

    public String getTresdigitos() {
        return tresdigitos;
    }

    public void setTresdigitos(String tresdigitos) {
        this.tresdigitos = tresdigitos;
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public void mostrar_informacoes(){
        super.mostrar_informacoes();
        System.out.println("Três Digitos: " + tresdigitos);
        System.out.println("Bairro: " + bairro);
    }
}
