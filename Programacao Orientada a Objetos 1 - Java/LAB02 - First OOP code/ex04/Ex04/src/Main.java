public class Main {
        public static void main( String [] args){
            Candidato candidato1 = new Candidato(
                    "SALATIEL MAGALHÃES", "08/02/1984", "Masculino", "Prefeito", 450000F, false, 55
            );
            Candidato candidato2 = new Candidato(
                    "EVANDRO SILVA", "08/06/1985", "Masculino", "Prefeito", 0F, false, 55
            );
            Candidato candidato3 = new Candidato(
                    "MATHEUS FELIPE", "22/05/1986", "Masculino", "Prefeito", 1000000F, true, 13
            );

            candidato1.mostrarInformacoes();
            candidato2.mostrarInformacoes();
            candidato3.mostrarInformacoes();
        }
}

