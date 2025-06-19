class Amigos extends Contato {
    private int grau;

    public Amigos(String apelido, String nome, String email, String aniversario, int grau) {
        super(apelido, nome, email, aniversario);
        this.grau = grau;
    }

    public void imprimirContato() {
        System.out.println(imprimirBasico() + ", Grau de amizade: " + grau);
    }

    public int getGrau() {
        return grau;
    }
}