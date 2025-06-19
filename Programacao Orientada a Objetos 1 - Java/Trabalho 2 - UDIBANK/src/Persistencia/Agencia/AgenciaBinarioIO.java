package Persistencia.Agencia;

import Classes.Agencia;
import Classes.Funcionario;
import Classes.Gerente;
import ExceptionsAndInterfaces.ValorInvalidoException;

import java.io.*;
import java.util.Date;

public class AgenciaBinarioIO {

    // Salva uma agência em arquivo binário
    public static void salvarAgencia(Agencia agencia, String nomeArquivo) throws IOException {
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream(nomeArquivo))) {
            dos.writeUTF(agencia.getNmrAgencia());
            dos.writeUTF(agencia.getNmAgencia());
            dos.writeUTF(agencia.getEndereco());
            dos.writeUTF(agencia.getCidade());
            dos.writeUTF(agencia.getEstado());
            dos.writeUTF(agencia.getBairro());

            // Salva o gerente
            salvarGerente(dos, agencia.getGerente());

            // Salva funcionários
            Funcionario[] funcionarios = agencia.getFuncionarios();
            dos.writeInt(funcionarios.length);
            for (Funcionario func : funcionarios) {
                salvarFuncionario(dos, func);
            }
        }
    }

    // Carrega uma agência de arquivo binário
    public static Agencia carregarAgencia(String nomeArquivo) throws IOException, ValorInvalidoException {
        try (DataInputStream dis = new DataInputStream(new FileInputStream(nomeArquivo))) {
            // Lê dados da agência
            String nmrAgencia = dis.readUTF();
            String nmAgencia = dis.readUTF();
            String endereco = dis.readUTF();
            String cidade = dis.readUTF();
            String estado = dis.readUTF();
            String bairro = dis.readUTF();

            // Carrega gerente (agencia ainda null - será setada depois)
            Gerente gerente = carregarGerente(dis);

            // Carrega funcionários
            int numFuncionarios = dis.readInt();
            Funcionario[] funcionarios = new Funcionario[numFuncionarios];
            for (int i = 0; i < numFuncionarios; i++) {
                funcionarios[i] = carregarFuncionario(dis);
            }

            // Cria a agência
            Agencia agencia = new Agencia(nmrAgencia, nmAgencia, endereco, cidade,
                    estado, bairro, gerente, funcionarios);

            // Atualiza referência no gerente
            gerente.setAgencia_gerenciada(agencia);

            return agencia;
        }
    }

    // Métodos auxiliares para salvar/carregar Gerente e Funcionario
    private static void salvarGerente(DataOutputStream dos, Gerente gerente) throws IOException {
        salvarFuncionario(dos, gerente); // Salva parte de Funcionario primeiro
        dos.writeLong(gerente.getIngresso_gerencia().getTime());
        dos.writeBoolean(gerente.getFormacaoBasica_gerencia());
    }

    private static Gerente carregarGerente(DataInputStream dis) throws IOException, ValorInvalidoException {
        Funcionario func = carregarFuncionario(dis);
        Date ingressoGerencia = new Date(dis.readLong());
        boolean formacaoBasica = dis.readBoolean();

        return new Gerente(
                func.getCPF(), func.getNome(), func.getEndereco_completo(),
                func.getEstado_civil(), func.getEscolaridade(), func.getData_nascimento(),
                func.getNro_carteiradeTrabalho(), func.getRG(), func.getCargo_empresa(),
                func.getSalario(), func.getAno_ingresso(), func.getSexo(),
                ingressoGerencia, null, formacaoBasica // agencia será setada depois
        );
    }

    private static void salvarFuncionario(DataOutputStream dos, Funcionario func) throws IOException {
        dos.writeUTF(func.getCPF());
        dos.writeUTF(func.getNome());
        dos.writeUTF(func.getEndereco_completo());
        dos.writeUTF(func.getEstado_civil());
        dos.writeUTF(func.getEscolaridade());
        dos.writeLong(func.getData_nascimento().getTime());
        dos.writeUTF(func.getNro_carteiradeTrabalho());
        dos.writeUTF(func.getRG());
        dos.writeUTF(func.getCargo_empresa());
        dos.writeUTF(func.getSalario());
        dos.writeUTF(func.getAno_ingresso());
        dos.writeUTF(func.getSexo());
    }

    private static Funcionario carregarFuncionario(DataInputStream dis) throws IOException, ValorInvalidoException {
        String cpf = dis.readUTF();
        String nome = dis.readUTF();
        String endereco = dis.readUTF();
        String estadoCivil = dis.readUTF();
        String escolaridade = dis.readUTF();
        Date dataNascimento = new Date(dis.readLong());
        String carteiraTrabalho = dis.readUTF();
        String rg = dis.readUTF();
        String cargo = dis.readUTF();
        String salario = dis.readUTF();
        String anoIngresso = dis.readUTF();
        String sexo = dis.readUTF();

        return new Funcionario(
                cpf, nome, endereco, estadoCivil, escolaridade,
                dataNascimento, carteiraTrabalho, rg, cargo,
                salario, anoIngresso, sexo
        );
    }
}