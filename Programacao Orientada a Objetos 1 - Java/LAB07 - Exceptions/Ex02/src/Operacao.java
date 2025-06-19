public class Operacao {

    public void iniciarOperacao(int numerador, int denominador) {
        try {
            calcular(numerador, denominador);
            System.out.println("Divisão realizada com sucesso!");
        } catch (DivisaoPorZeroException e) {
            System.out.println("Exceção capturada: " + e.getMessage());
        }
    }

    public void calcular(int numerador, int denominador) throws DivisaoPorZeroException {
        dividir(numerador, denominador);
    }

    public void dividir(int numerador, int denominador) throws DivisaoPorZeroException {
        if (denominador == 0) {
            throw new DivisaoPorZeroException();
        }
        System.out.println("Resultado: " + (double) numerador / denominador);

    }

}
