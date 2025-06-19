public class EstudanteDoutorado extends EstudantePosGrad {
    String tituloTese;

    public EstudanteDoutorado(String nome, String endereco, String formacao,
                              String linhadDePesquisa, String tituloTese) {
        super(nome, endereco, formacao, linhadDePesquisa);
        this.tituloTese = tituloTese;
    }

    @Override
    public void print() {
        super.print();
        System.out.println("EstudanteDoutorado{" +
                "tituloTese='" + tituloTese + '\'' +
                '}');
        System.out.println();
    }

    @Override
    public void print(boolean mesmaLinha) {
        if (mesmaLinha) {
            System.out.print("Nome: " + getNome() + "; Endereço: " + getEndereco() +
                    "; Formação: " + getFormacao() + "; Linha de Pesquisa: " + getLinhaDePesquisa() +
                    "; Título Tese: " + tituloTese + "; ");
        } else {
            super.print(false); // Chama o método da classe pai para imprimir nome, endereço, formação e linha de pesquisa
            System.out.println("Título Tese: " + tituloTese);
        }
    }

    public String getTituloTese() {
        return tituloTese;
    }

    public void setTituloTese(String tituloTese) {
        this.tituloTese = tituloTese;
    }
}
