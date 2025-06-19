public class CamaroteInferior extends VIP {
    private String localizacao;

    public CamaroteInferior(float valor, float valorAdicional, String localizacao) {
        super(valor, valorAdicional);
        this.localizacao = localizacao;
    }

    public String getLocalizacao() {
        return localizacao;
    }

    public void imprimeLocalizacao() {
        System.out.println("Localização do ingresso: " + localizacao);
    }
}