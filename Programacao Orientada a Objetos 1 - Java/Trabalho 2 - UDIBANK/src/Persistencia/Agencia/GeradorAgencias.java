package Persistencia.Agencia;

import Classes.Agencia;
import Classes.Funcionario;
import Classes.Gerente;
import ExceptionsAndInterfaces.ValorInvalidoException;

import java.util.Date;
import java.util.Random;

public class GeradorAgencias {
    private static final Random random = new Random();

    // Arrays de dados fictícios para geração
    private static final String[] NOMES_AGENCIAS = {
            "Centro", "Norte", "Sul", "Leste", "Oeste", "Central", "Financeira", "Comercial"
    };

    private static final String[] BAIRROS = {
            "Centro", "Jardim", "Vila", "Alto", "Bela Vista", "Liberdade", "Moema", "Pinheiros"
    };

    private static final String[] CIDADES = {
            "São Paulo", "Rio de Janeiro", "Belo Horizonte", "Porto Alegre", "Curitiba", "Salvador", "Recife"
    };

    private static final String[] ESTADOS = {
            "SP", "RJ", "MG", "RS", "PR", "BA", "PE"
    };

    private static final String[] CARGOS = {
            "Caixa", "Atendente", "Assistente", "Analista", "Supervisor"
    };

    private static final String[] NOMES_PESSOAS = {
            "João", "Maria", "Pedro", "Ana", "Carlos", "Lucia", "Marcos", "Julia"
    };

    private static final String[] SOBRENOMES = {
            "Silva", "Santos", "Oliveira", "Souza", "Pereira", "Costa", "Rodrigues", "Almeida"
    };

    public static Agencia gerarAgenciaCompleta(int numeroSequencial) {
        // Gerar dados básicos da agência
        String nmrAgencia = String.format("%04d", numeroSequencial);
        String nmAgencia = "Agência " + NOMES_AGENCIAS[random.nextInt(NOMES_AGENCIAS.length)];
        String bairro = BAIRROS[random.nextInt(BAIRROS.length)];
        String cidade = CIDADES[random.nextInt(CIDADES.length)];
        String estado = ESTADOS[random.nextInt(ESTADOS.length)];
        String endereco = "Rua " + (random.nextInt(100) + 1) + ", " + (random.nextInt(1000) + 1);

        // Primeiro gerar o gerente (que precisa da agência)
        Gerente gerente = gerarGerenteFicticio(null); // null temporário

        // Gerar funcionários (3 a 5 por agência)
        int numFuncionarios = 3 + random.nextInt(3);
        Funcionario[] funcionarios = new Funcionario[numFuncionarios];
        for (int i = 0; i < numFuncionarios; i++) {
            funcionarios[i] = gerarFuncionarioFicticio();
        }

        // Criar a agência
        Agencia agencia = new Agencia(
                nmrAgencia, nmAgencia, endereco, cidade, estado, bairro, gerente, funcionarios
        );

        // Atualizar a referência da agência no gerente
        gerente.setAgencia_gerenciada(agencia);

        return agencia;
    }

    private static Gerente gerarGerenteFicticio(Agencia agencia) {
        try {
            String cpf = gerarCPF();
            String nomeCompleto = gerarNomeCompleto();
            String endereco = "Av. " + (random.nextInt(100) + 1) + ", " + (random.nextInt(1000) + 1);
            String estadoCivil = random.nextBoolean() ? "Solteiro(a)" : "Casado(a)";
            String escolaridade = "Superior Completo";
            Date dataNascimento = new Date(System.currentTimeMillis() - (long)(random.nextInt(30) + 25) * 365 * 24 * 60 * 60 * 1000L);
            String carteiraTrabalho = String.valueOf(100000000 + random.nextInt(900000000));
            String rg = String.valueOf(10000000 + random.nextInt(90000000)) + "-" + (random.nextInt(10));
            String cargo = "Gerente";
            String salario = String.format("%.2f", 8000 + random.nextDouble() * 7000);
            String anoIngresso = String.valueOf(2000 + random.nextInt(23));
            String sexo = random.nextBoolean() ? "Masculino" : "Feminino";
            Date ingressoGerencia = new Date(System.currentTimeMillis() - (long)(random.nextInt(5) + 1) * 365 * 24 * 60 * 60 * 1000L);
            boolean formacaoBasica = random.nextBoolean();

            return new Gerente(
                    cpf, nomeCompleto, endereco, estadoCivil, escolaridade,
                    dataNascimento, carteiraTrabalho, rg, cargo, salario,
                    anoIngresso, sexo, ingressoGerencia, agencia, formacaoBasica
            );
        } catch (ValorInvalidoException e) {
            throw new RuntimeException("Erro ao gerar gerente fictício", e);
        }
    }

    private static Funcionario gerarFuncionarioFicticio() {
        try {
            String cpf = gerarCPF();
            String nomeCompleto = gerarNomeCompleto();
            String endereco = "Rua " + (random.nextInt(100) + 1) + ", " + (random.nextInt(1000) + 1);
            String estadoCivil = random.nextBoolean() ? "Solteiro(a)" : "Casado(a)";
            String escolaridade = random.nextBoolean() ? "Superior Completo" : "Médio Completo";
            Date dataNascimento = new Date(System.currentTimeMillis() - (long)(random.nextInt(30) + 20) * 365 * 24 * 60 * 60 * 1000L);
            String carteiraTrabalho = String.valueOf(100000000 + random.nextInt(900000000));
            String rg = String.valueOf(10000000 + random.nextInt(90000000)) + "-" + (random.nextInt(10));
            String cargo = CARGOS[random.nextInt(CARGOS.length)];
            String salario = String.format("%.2f", 2000 + random.nextDouble() * 5000);
            String anoIngresso = String.valueOf(2015 + random.nextInt(8));
            String sexo = random.nextBoolean() ? "Masculino" : "Feminino";

            return new Funcionario(
                    cpf, nomeCompleto, endereco, estadoCivil, escolaridade,
                    dataNascimento, carteiraTrabalho, rg, cargo, salario,
                    anoIngresso, sexo
            );
        } catch (ValorInvalidoException e) {
            throw new RuntimeException("Erro ao gerar funcionário fictício", e);
        }
    }

    private static String gerarNomeCompleto() {
        return NOMES_PESSOAS[random.nextInt(NOMES_PESSOAS.length)] + " " +
                SOBRENOMES[random.nextInt(SOBRENOMES.length)];
    }

    private static String gerarCPF() {
        // Gera um CPF válido (apenas para fins de teste)
        int[] cpf = new int[11];
        for (int i = 0; i < 9; i++) {
            cpf[i] = random.nextInt(10);
        }

        // Cálculo dos dígitos verificadores
        cpf[9] = calcularDigitoVerificador(cpf, 9);
        cpf[10] = calcularDigitoVerificador(cpf, 10);

        // Formata como string
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