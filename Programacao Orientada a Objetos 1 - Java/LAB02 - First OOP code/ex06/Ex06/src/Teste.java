public class Teste {
        public static void main( String [] args){
            Candidato candidatos1[] = new Candidato[3];
            Candidato candidatos2[] = new Candidato[3];

            candidatos1[0] = new Candidato();
            candidatos1[1] = new Candidato();
            candidatos1[2] = new Candidato();

            candidatos2[0] = new Candidato();
            candidatos2[1] = new Candidato();
            candidatos2[2] = new Candidato();

            candidatos1[0].nome_completo = "SALATIEL MAGALHÃES";
            candidatos1[0].data_de_nascimento = "08/02/1984";
            candidatos1[0].genero = "Masculino";
            candidatos1[0].cargo_preterido = "Prefeito";
            candidatos1[0].total_de_bens = 450000F;
            candidatos1[0].reeleicao = false;
            candidatos1[0].num_do_partido = 55;

            candidatos1[1].nome_completo = "EVANDRO SILVA";
            candidatos1[1].data_de_nascimento = "08/06/1985";
            candidatos1[1].genero = "Masculino";
            candidatos1[1].cargo_preterido = "Prefeito";
            candidatos1[1].total_de_bens = 0F;
            candidatos1[1].reeleicao = false;
            candidatos1[1].num_do_partido = 55;

            candidatos1[2].nome_completo = "MATHEUS FELIPE";
            candidatos1[2].data_de_nascimento = "22/05/1986";
            candidatos1[2].genero = "Masculino";
            candidatos1[2].cargo_preterido = "Prefeito";
            candidatos1[2].total_de_bens = 1000000F;
            candidatos1[2].reeleicao = true;
            candidatos1[2].num_do_partido = 13;

            candidatos2[0].nome_completo = "JULIANA ALVES";
            candidatos2[0].data_de_nascimento = "15/09/1980";
            candidatos2[0].genero = "Feminino";
            candidatos2[0].cargo_preterido = "Prefeito";
            candidatos2[0].total_de_bens = 750000F;
            candidatos2[0].reeleicao = true;
            candidatos2[0].num_do_partido = 40;

            candidatos2[1].nome_completo = "CARLOS EDUARDO";
            candidatos2[1].data_de_nascimento = "03/11/1975";
            candidatos2[1].genero = "Masculino";
            candidatos2[1].cargo_preterido = "Prefeito";
            candidatos2[1].total_de_bens = 300000F;
            candidatos2[1].reeleicao = false;
            candidatos2[1].num_do_partido = 25;

            candidatos2[2].nome_completo = "FERNANDA LIMA";
            candidatos2[2].data_de_nascimento = "29/07/1990";
            candidatos2[2].genero = "Feminino";
            candidatos2[2].cargo_preterido = "Prefeito";
            candidatos2[2].total_de_bens = 1200000F;
            candidatos2[2].reeleicao = true;
            candidatos2[2].num_do_partido = 45;

            Eleicao eleicao1 = new Eleicao("Minas Gerais", 250000, candidatos1);
            Eleicao eleicao2 = new Eleicao("São Paulo", 300000, candidatos2);

            eleicao1.mostrarDados();
            eleicao2.mostrarDados();

        }
}

