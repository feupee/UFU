public class Main {
    public static void main(String[] args) {
        Candidato candidatos[] = new Candidato[5];

        candidatos[0] = new Candidato();
        candidatos[1] = new Candidato();
        candidatos[2] = new Candidato();
        candidatos[3] = new Candidato();
        candidatos[4] = new Candidato();

        candidatos[0].nome_completo = "SALATIEL MAGALHÃES";
        candidatos[0].data_de_nascimento = "08/02/1984";
        candidatos[0].genero = "Masculino";
        candidatos[0].cargo_preterido = "Prefeito";
        candidatos[0].total_de_bens = 450000F;
        candidatos[0].reeleicao = false;
        candidatos[0].num_do_partido = 55;

        candidatos[1].nome_completo = "EVANDRO SILVA";
        candidatos[1].data_de_nascimento = "08/06/1985";
        candidatos[1].genero = "Masculino";
        candidatos[1].cargo_preterido = "Prefeito";
        candidatos[1].total_de_bens = 0F;
        candidatos[1].reeleicao = false;
        candidatos[1].num_do_partido = 55;

        candidatos[2].nome_completo = "MATHEUS FELIPE";
        candidatos[2].data_de_nascimento = "22/05/1986";
        candidatos[2].genero = "Masculino";
        candidatos[2].cargo_preterido = "Prefeito";
        candidatos[2].total_de_bens = 1000000F;
        candidatos[2].reeleicao = true;
        candidatos[2].num_do_partido = 13;

        candidatos[3].nome_completo = "JULIANA ALVES";
        candidatos[3].data_de_nascimento = "15/09/1980";
        candidatos[3].genero = "Feminino";
        candidatos[3].cargo_preterido = "Prefeito";
        candidatos[3].total_de_bens = 750000F;
        candidatos[3].reeleicao = true;
        candidatos[3].num_do_partido = 40;

        candidatos[4].nome_completo = "CARLOS EDUARDO";
        candidatos[4].data_de_nascimento = "03/11/1975";
        candidatos[4].genero = "Masculino";
        candidatos[4].cargo_preterido = "Prefeito";
        candidatos[4].total_de_bens = 300000F;
        candidatos[4].reeleicao = false;
        candidatos[4].num_do_partido = 25;

        Eleicao eleicao = new Eleicao("Minas Gerais", 450000, candidatos);

        Candidato CandidatoBens = new Candidato();
        CandidatoBens = eleicao.mostrarMaiorBens();

        eleicao.CompararCandidatosBens(CandidatoBens);
    }
}
