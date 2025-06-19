public class Main {
    public static void main(String[] args) {
        Ingresso ingressoNormal = new Normal(100);
        VIP ingressoVIP = new VIP(100, 50);
        CamaroteInferior camaroteInferior = new CamaroteInferior(100, 50, "Camarote Inferior - Setor A");
        CamaroteSuperior camaroteSuperior = new CamaroteSuperior(100, 100);

        ingressoNormal.escreveValor();
        ((Normal) ingressoNormal).imprimeTipoIngresso();

        ingressoVIP.escreveValor();
        System.out.println("Valor do ingresso VIP: R$ " + ingressoVIP.calcularValorVIP());

        camaroteInferior.escreveValor();
        camaroteInferior.imprimeLocalizacao();

        camaroteSuperior.escreveValor();
        System.out.println("Valor do ingresso Camarote Superior: R$ " + camaroteSuperior.calcularValorVIP());
    }
}