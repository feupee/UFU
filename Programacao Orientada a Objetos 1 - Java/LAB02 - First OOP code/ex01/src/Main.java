public class Main {
        public static void main( String [] args){
            Candidato candidato3 = new Candidato();
            Candidato candidato2 = new Candidato();
            Candidato candidato1 = new Candidato();

            candidato1.nome_completo = "SALATIEL MAGALHÃES";
            candidato1.data_de_nascimento = "08/02/1984";
            candidato1.genero = "Masculino";
            candidato1.cargo_preterido = "Prefeito";
            candidato1.total_de_bens = 450000F;
            candidato1.reeleicao = false;
            candidato1.num_do_partido = 55;

            candidato2.nome_completo = "EVANDRO SILVA";
            candidato2.data_de_nascimento = "08/06/1985";
            candidato2.genero = "Masculino";
            candidato2.cargo_preterido = "Prefeito";
            candidato2.total_de_bens = 0F;
            candidato2.reeleicao = false;
            candidato2.num_do_partido = 55;

            candidato3.nome_completo = "MATHEUS FELIPE";
            candidato3.data_de_nascimento = "22/05/1986";
            candidato3.genero = "Masculino";
            candidato3.cargo_preterido = "Prefeito";
            candidato3.total_de_bens = 1000000F;
            candidato3.reeleicao = true;
            candidato3.num_do_partido = 13;
        }
}

