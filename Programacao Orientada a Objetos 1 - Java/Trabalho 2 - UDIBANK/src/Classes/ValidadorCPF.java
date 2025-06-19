package Classes;

public abstract class ValidadorCPF {

    // Funcao para remover caracteres nao numericos
    private static String removerCaracteresNaoNumericos(String cpf) {
        return cpf.replaceAll("[^0-9]", "");
    }

    // Função para validar CPF
    public static boolean validarCPF(String cpf) {
        // Remover caracteres nao numericos
        cpf = removerCaracteresNaoNumericos(cpf);

        // Verificar se o CPF tem 11 dígitos
        if (cpf.length() != 11) {
            return false;
        }

        // Verificar se todos os numeros sao iguais (ex: 111.111.111-11)
        if (cpf.equals("00000000000") || cpf.equals("11111111111") || cpf.equals("22222222222") ||
                cpf.equals("33333333333") || cpf.equals("44444444444") || cpf.equals("55555555555") ||
                cpf.equals("66666666666") || cpf.equals("77777777777") || cpf.equals("88888888888") ||
                cpf.equals("99999999999")) {
            return false;
        }

        // Calculo do primeiro digito verificador
        int soma1 = 0;
        for (int i = 0; i < 9; i++) {
            soma1 += Integer.parseInt(String.valueOf(cpf.charAt(i))) * (10 - i);
        }
        int digito1 = 11 - (soma1 % 11);
        if (digito1 == 10 || digito1 == 11) {
            digito1 = 0;
        }

        // Calculo do segundo dígito verificador
        int soma2 = 0;
        for (int i = 0; i < 10; i++) {
            soma2 += Integer.parseInt(String.valueOf(cpf.charAt(i))) * (11 - i);
        }
        int digito2 = 11 - (soma2 % 11);
        if (digito2 == 10 || digito2 == 11) {
            digito2 = 0;
        }

        // Verificar se os digitos verificadores estao corretos
        return cpf.charAt(9) == (char) (digito1 + '0') && cpf.charAt(10) == (char) (digito2 + '0');
    }
}