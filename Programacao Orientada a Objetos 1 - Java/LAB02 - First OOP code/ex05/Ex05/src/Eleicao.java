public class Eleicao {
    String nome_municipio;
    int numero_votantes;
    Candidato[] candidatos_eleicao;

    public Eleicao(String nome_Municipio, int numero_Votantes, Candidato []candidatos){
        this.nome_municipio = nome_Municipio;
        this.numero_votantes = numero_Votantes;
        this.candidatos_eleicao = candidatos;
    }

    public void mostrarDados(){
        System.out.println("Nome Municipio: "+nome_municipio);
        System.out.println("Numero votantes: "+numero_votantes);
        System.out.println("Candidatos: ");
        for(Candidato candidato : candidatos_eleicao){
            candidato.mostrarInformacoes();
        }
    }
}



