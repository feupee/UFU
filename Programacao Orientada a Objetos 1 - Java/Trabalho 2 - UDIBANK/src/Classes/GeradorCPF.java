package Classes;

public class GeradorCPF {
    public static String gerarCPFValido() {
        while (true) {
            // Gerar 9 dígitos aleatórios
            StringBuilder cpf = new StringBuilder();
            for (int i = 0; i < 9; i++) {
                cpf.append((int) (Math.random() * 10));
            }

            // Calcular primeiro dígito verificador
            int soma1 = 0;
            for (int i = 0; i < 9; i++) {
                soma1 += Integer.parseInt(String.valueOf(cpf.charAt(i))) * (10 - i);
            }
            int digito1 = 11 - (soma1 % 11);
            if (digito1 >= 10) digito1 = 0;
            cpf.append(digito1);

            // Calcular segundo dígito verificador
            int soma2 = 0;
            for (int i = 0; i < 10; i++) {
                soma2 += Integer.parseInt(String.valueOf(cpf.charAt(i))) * (11 - i);
            }
            int digito2 = 11 - (soma2 % 11);
            if (digito2 >= 10) digito2 = 0;
            cpf.append(digito2);

            // Verificar se é válido (não é sequência repetida)
            String cpfStr = cpf.toString();
            if (ValidadorCPF.validarCPF(cpfStr)) {
                return formatarCPF(cpfStr);
            }
        }
    }

    private static String formatarCPF(String cpf) {
        return cpf.substring(0, 3) + "." + cpf.substring(3, 6) + "." +
                cpf.substring(6, 9) + "-" + cpf.substring(9);
    }
}