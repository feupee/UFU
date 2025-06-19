public class UsaBanco {
    public static void main(String[] args) {
        ContaCorrente conta1 = new ContaEspecial(2000, 12345, 1111, 500);
        System.out.println("Saldo inicial: " + conta1.getSaldo(1111));

        conta1.debitaValor(1500, 1111);
        System.out.println("Saldo após débito de 1500: " + conta1.getSaldo(1111));

        conta1.debitaValor(700, 1111);
        System.out.println("Saldo após débito de 700: " + conta1.getSaldo(1111));

        conta1.debitaValor(1000, 1111);
        System.out.println("Saldo após débito de 1000: " + conta1.getSaldo(1111));

        System.out.println();

        ContaCorrente conta2 = new ContaEspecial(1500, 54321, 2222, 0);
        System.out.println("Saldo inicial: " + conta2.getSaldo(2222));

        conta2.debitaValor(1500, 2222);
        System.out.println("Saldo após débito de 1500: " + conta2.getSaldo(2222));

        conta2.debitaValor(1, 2222);
        System.out.println("Saldo após débito de 1: " + conta2.getSaldo(2222));
    }
}
