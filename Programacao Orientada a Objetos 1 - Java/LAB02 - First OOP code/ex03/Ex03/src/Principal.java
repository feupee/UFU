public class Principal {
    public static void main(String[] args){

        Candidato[] array = new Candidato[3];

        array[0] = new Candidato();
        array[0].setNome_completo("Maria Silva");
        array[0].setData_de_Nascimento("1985-03-22");
        array[0].setGenero("Feminino");
        array[0].setCargo_pretendido("Deputada Federal");
        array[0].setTotal_de_bens(500000.50f);
        array[0].setReeleicao(false);
        array[0].setNúmero_do_partido(45);

        array[1] = new Candidato();
        array[1].setNome_completo("Carlos Eduardo Pereira");
        array[1].setData_de_Nascimento("1978-07-10");
        array[1].setGenero("Masculino");
        array[1].setCargo_pretendido("Senador");
        array[1].setTotal_de_bens(1500000.75f);
        array[1].setReeleicao(true);
        array[1].setNúmero_do_partido(13);

        array[2] = new Candidato();
        array[2].setNome_completo("Ana Carolina Costa");
        array[2].setData_de_Nascimento("1992-11-05");
        array[2].setGenero("Feminino");
        array[2].setCargo_pretendido("Governadora");
        array[2].setTotal_de_bens(250000.00f);
        array[2].setReeleicao(false);
        array[2].setNúmero_do_partido(22);

        // for each loop
        for (Candidato candidato: array) {
            candidato.mostrarInformacoes();
        }
    }
}
