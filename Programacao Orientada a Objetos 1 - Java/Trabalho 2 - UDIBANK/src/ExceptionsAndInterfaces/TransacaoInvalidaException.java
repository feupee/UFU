package ExceptionsAndInterfaces;

public class TransacaoInvalidaException extends Exception {
    public TransacaoInvalidaException(String mensagem) {
        super(mensagem);
    }
}