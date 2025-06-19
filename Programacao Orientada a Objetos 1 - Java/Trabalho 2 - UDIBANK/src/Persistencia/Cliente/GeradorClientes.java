package Persistencia.Cliente;

import Classes.Agencia;
import Classes.Cliente;
import ExceptionsAndInterfaces.ValorInvalidoException;

import java.util.Date;
import java.util.Random;

public class GeradorClientes {
    private static final Random random = new Random();

    private static final String[] NOMES = {
            "João", "Maria", "Pedro", "Ana", "Carlos", "Lucia", "Marcos", "Julia"
    };

    private static final String[] SOBRENOMES = {
            "Silva", "Santos", "Oliveira", "Souza", "Pereira", "Costa", "Rodrigues", "Almeida"
    };

    private static final String[] ESTADOS_CIVIS = {
            "Solteiro(a)", "Casado(a)", "Divorciado(a)", "Viúvo(a)"
    };

    private static final String[] ESCOLARIDADES = {
            "Fundamental", "Médio", "Superior", "Pós-graduação", "Mestrado", "Doutorado"
    };

    public static Cliente gerarClienteFicticio(Agencia agencia) throws ValorInvalidoException {
        String cpf = gerarCPF();
        String nomeCompleto = gerarNomeCompleto();
        String endereco = gerarEndereco();
        String estadoCivil = ESTADOS_CIVIS[random.nextInt(ESTADOS_CIVIS.length)];
        String escolaridade = ESCOLARIDADES[random.nextInt(ESCOLARIDADES.length)];
        Date dataNascimento = gerarDataNascimento(18, 80);

        return new Cliente(cpf, nomeCompleto, endereco, estadoCivil, escolaridade, dataNascimento, agencia);
    }

    private static String gerarNomeCompleto() {
        return NOMES[random.nextInt(NOMES.length)] + " " + SOBRENOMES[random.nextInt(SOBRENOMES.length)];
    }

    private static String gerarEndereco() {
        return "Rua " + (random.nextInt(100) + 1) + ", nº " + (random.nextInt(1000) + 1) +
                " - " + (random.nextBoolean() ? "Apto " + (random.nextInt(300) + 1) : "Casa " + (random.nextInt(50) + 1));
    }

    private static Date gerarDataNascimento(int idadeMinima, int idadeMaxima) {
        long idadeAleatoria = (long)(random.nextInt(idadeMaxima - idadeMinima) + idadeMinima);
        return new Date(System.currentTimeMillis() - idadeAleatoria * 365L * 24 * 60 * 60 * 1000);
    }

    private static String gerarCPF() {
        int[] cpf = new int[11];
        for (int i = 0; i < 9; i++) {
            cpf[i] = random.nextInt(10);
        }

        cpf[9] = calcularDigitoVerificador(cpf, 9);
        cpf[10] = calcularDigitoVerificador(cpf, 10);

        return String.format("%d%d%d.%d%d%d.%d%d%d-%d%d",
                cpf[0], cpf[1], cpf[2], cpf[3], cpf[4], cpf[5],
                cpf[6], cpf[7], cpf[8], cpf[9], cpf[10]);
    }

    private static int calcularDigitoVerificador(int[] cpf, int posicao) {
        int soma = 0;
        int peso = posicao + 1;

        for (int i = 0; i < posicao; i++) {
            soma += cpf[i] * peso;
            peso--;
        }

        int resto = soma % 11;
        return resto < 2 ? 0 : 11 - resto;
    }
}