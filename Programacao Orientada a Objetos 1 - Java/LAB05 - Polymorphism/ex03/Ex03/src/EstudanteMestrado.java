public class EstudanteMestrado extends EstudantePosGrad {
    private String tipo; // tipo pode ser acadêmico ou profisional
    private String tituloDissertacao;

    public EstudanteMestrado(String nome, String endereco, String formacao,
                             String linhadDePesquisa, String tipo, String tituloDissertacao) {
        super(nome, endereco, formacao, linhadDePesquisa);
        this.tipo = tipo;
        this.tituloDissertacao = tituloDissertacao;
    }

    @Override
    public void print() {
        super.print();
        System.out.println("EstudanteMestrado{" +
                "tipo='" + tipo + '\'' +
                ", tituloDissertacao='" + tituloDissertacao + '\'' +
                '}');
        System.out.println();
    }

    @Override
    public void print(boolean mesmaLinha) {
        if (mesmaLinha) {
            System.out.print("Nome: " + getNome() + "; Endereço: " + getEndereco() +
                    "; Formação: " + getFormacao() + "; Linha de Pesquisa: " + getLinhaDePesquisa() +
                    "; Tipo: " + tipo + "; Título Dissertação: " + tituloDissertacao + "; ");
        } else {
            super.print(false); // Chama o método da classe pai para imprimir nome, endereço, formação e linha de pesquisa
            System.out.println("Tipo: " + tipo);
            System.out.println("Título Dissertação: " + tituloDissertacao);
        }
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getTituloDissertacao() {
        return tituloDissertacao;
    }

    public void setTituloDissertacao(String tituloDissertacao) {
        this.tituloDissertacao = tituloDissertacao;
    }
}
