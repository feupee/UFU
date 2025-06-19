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

        System.out.println("Candidato a Prefeito:");
        System.out.println("Nome: " + prefeito.getNome_completo());
        System.out.println("Data de Nascimento: " + prefeito.getData_nascimento());
        System.out.println("Gênero: " + prefeito.getGenero());
        System.out.println("Total de Bens: " + prefeito.getTotal_bens());
        System.out.println("Reeleição: " + (prefeito.isReleicao() ? "Sim" : "Não"));
        System.out.println("Número do Partido: " + prefeito.getNum_partido());
        System.out.println("Nome do Vice: " + prefeito.getNome_vice());
        System.out.println("Partido do Vice: " + prefeito.getPartido_vice());

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

        // Usando os getters
        System.out.println("\nCandidato a Vereador:");
        System.out.println("Nome: " + vereador.getNome_completo());
        System.out.println("Data de Nascimento: " + vereador.getData_nascimento());
        System.out.println("Gênero: " + vereador.getGenero());
        System.out.println("Total de Bens: " + vereador.getTotal_bens());
        System.out.println("Reeleição: " + (vereador.isReleicao() ? "Sim" : "Não"));
        System.out.println("Número do Partido: " + vereador.getNum_partido());
        System.out.println("Três Dígitos: " + vereador.getTresdigitos());
        System.out.println("Bairro: " + vereador.getBairro());
    }
}
