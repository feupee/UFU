public class CandidatoVereador extends Candidato{
    private String tresdigitos;
    private String bairro;


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
        System.out.println("Candidato a Prefeito:");
        System.out.println("Nome: " + super.nome_completo);
        System.out.println("Data de Nascimento: " + super.data_nascimento);
        System.out.println("Gênero: " + super.genero);
        System.out.println("Total de Bens: " + super.total_bens);
        System.out.println("Reeleição: " + (super.releicao ? "Sim" : "Não"));
        System.out.println("Número do Partido: " + super.num_partido);
        System.out.println("Três Digitos: " + tresdigitos);
        System.out.println("Bairro: " + bairro);
    }
}
