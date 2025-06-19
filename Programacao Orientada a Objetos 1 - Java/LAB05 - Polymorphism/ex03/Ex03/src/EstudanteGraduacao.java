public class EstudanteGraduacao extends Estudante {
    private String tituloTCC;

    public EstudanteGraduacao(String nome, String endereco, String tituloTCC) {
        super(nome, endereco);
        this.tituloTCC = tituloTCC;
    }

    public void print() {
        super.print();
        System.out.println("EstudanteGraduacao{" +
                "tituloTCC='" + tituloTCC + '\'' +
                '}');
        System.out.println();
    }

    @Override
    public void print(boolean mesmaLinha) {
        if (mesmaLinha) {
            System.out.print("Nome: " + getNome() + "; Endereço: " + getEndereco() + "; Título TCC: " + tituloTCC + "; ");
        } else {
            super.print(false); // Chama o método da classe pai para imprimir nome e endereço
            System.out.println("Título TCC: " + tituloTCC);
        }
    }

    public String getTituloTCC() {
        return tituloTCC;
    }

    public void setTituloTCC(String tituloTCC) {
        this.tituloTCC = tituloTCC;
    }
}
