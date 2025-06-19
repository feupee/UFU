public class Dueto {
    Musico[] musicos_titulares = new Musico[2];
    Musico substituto;
    private String nome_dueto;

    public Dueto(String nome_dueto, Musico substituto, Musico[] musicos_titulares) {
        this.nome_dueto = nome_dueto;
        this.substituto = substituto;
        this.musicos_titulares = musicos_titulares;
    }

    public Dueto(String nome_dueto, Musico[] musicos_titulares) {
        this.nome_dueto = nome_dueto;
        this.musicos_titulares = musicos_titulares;
    }

    public void mostrar_informacoes() {
        System.out.println("Nome: " + nome_dueto);
        System.out.println("Titular 1: ");
        musicos_titulares[0].mostrar_informacoes();
        System.out.println("Titular 2: ");
        musicos_titulares[1].mostrar_informacoes();
        if(substituto != null) {
            substituto.mostrar_informacoes();
        }
    }

    public float MediaRemuneracao() {
        float somaRemuneracao = 0;
        int contador = 2;

        somaRemuneracao += musicos_titulares[0].remuneracao_hora;
        somaRemuneracao += musicos_titulares[1].remuneracao_hora;

        if (substituto != null) {
            somaRemuneracao += substituto.remuneracao_hora;
            contador++;
        }

        return somaRemuneracao / contador;
    }
}
