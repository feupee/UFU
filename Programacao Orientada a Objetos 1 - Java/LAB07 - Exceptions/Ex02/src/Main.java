public class Main {
    public static void main(String[] args) {
        Operacao operacao = new Operacao();

        // Testando casos válidos e inválidos
        operacao.iniciarOperacao(10, 2);  // Saída: Resultado: 5.0
        operacao.iniciarOperacao(5, 0);   // Saída: Exceção capturada: Erro: Divisão por zero não é permitida.
    }
}