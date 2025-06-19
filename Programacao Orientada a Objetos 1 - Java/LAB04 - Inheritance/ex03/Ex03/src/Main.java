public class Main {
    public static void main(String [] args){
        Candidato candidato = new Candidato(
                "João Silva",
                "01/01/1980",
                "Masculino",
                500000.00f,
                true,
                45
        );
        CandidatoVereador candidatoVereador = new CandidatoVereador(candidato, "123",
                "Centro");

        candidatoVereador.mostrar_informacoes();
    }
}
