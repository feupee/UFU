package Util;

public class Aeroporto {
    private String cidade;
    private String codigoIATA;

    //Construtor
    public Aeroporto(String cidade, String codigoIATA) {
        this.cidade = cidade;
        this.codigoIATA = codigoIATA;
    }

    //Getters And Setters
    public String getCidade() {
        return cidade;
    }

    public String getCodigoIATA() {
        return codigoIATA;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public void setCodigoIATA(String codigoIATA) {
        this.codigoIATA = codigoIATA;
    }
}