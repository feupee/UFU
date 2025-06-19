public class Empresa {
    public static void main(String [] args){
        // Instanciando os arrays de objetos
        Chefe[] arrayChefe = new Chefe[2];
        Horista[] arrayHorista = new Horista[2];
        Operarios[] arrayOperarios = new Operarios[2];
        Vendedor[] arrayVendedor = new Vendedor[2];

        // Inicializando os objetos dos arrays
        arrayChefe[0] = new Chefe(5000, "João", "10/01/1980");
        arrayChefe[1] = new Chefe(6000, "Maria", "15/05/1975");

        arrayHorista[0] = new Horista(15.0f, 160, "Carlos", "02/11/1990");
        arrayHorista[1] = new Horista(20.0f, 150, "Ana", "12/02/1985");

        arrayOperarios[0] = new Operarios(10.0f, 200, "José", "25/07/1992");
        arrayOperarios[1] = new Operarios(12.0f, 180, "Lucas", "09/09/1988");

        arrayVendedor[0] = new Vendedor(500.0f, 2000.0f, "Paulo", "07/06/1983");
        arrayVendedor[1] = new Vendedor(400.0f, 2500.0f, "Fernanda", "30/08/1995");
    }
}
