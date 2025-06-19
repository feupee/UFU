public class Main {
    public static void main(String[]args){
        CandidatoPrefeito prefeito = new CandidatoPrefeito(
                "João Silva",
                "01/01/1980",
                "Masculino",
                500000.00f,
                true,
                45,
                "Maria Oliveira",
                "Partido XYZ"
        );



        CandidatoVereador vereador = new CandidatoVereador(
                "Ana Souza",
                "15/06/1985",
                "Feminino",
                200000.00f,
                false,
                12,
                "123",
                "Centro"
        );

        prefeito.mostrar_informacoes();
        vereador.mostrar_informacoes();
    }
}
