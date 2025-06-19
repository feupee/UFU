class Trabalho extends Contato {
    private String tipo;

    public Trabalho(String apelido, String nome, String email, String aniversario, String tipo) {
        super(apelido, nome, email, aniversario);
        this.tipo = tipo;
    }

    public void imprimirContato() {
        System.out.println(imprimirBasico() + ", Tipo: " + tipo);
    }

    public String getTipo() {
        return tipo;
    }
}