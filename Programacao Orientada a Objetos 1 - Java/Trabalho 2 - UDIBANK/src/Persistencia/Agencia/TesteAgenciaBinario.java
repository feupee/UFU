package Persistencia.Agencia;

import Classes.Agencia;

import java.io.IOException;

public class TesteAgenciaBinario {
    public static void main(String[] args) {
        // Gerar e salvar 5 agências
        for (int i = 1; i <= 5; i++) {
            // 1. Gerar a agência
            Agencia agencia = GeradorAgencias.gerarAgenciaCompleta(i);

            // 2. Criar nome do arquivo no formato agencia_0001.bin, agencia_0002.bin, etc.
            String nomeArquivo = String.format("dados/agencia_%04d.bin", i);

            // 3. Salvar em arquivo binário
            try {
                AgenciaBinarioIO.salvarAgencia(agencia, nomeArquivo);

                // 4. Mostrar informações no console
                System.out.println("----------------------------------------");
                System.out.println("Agência gerada e salva: " + nomeArquivo);
                System.out.println("Número: " + agencia.getNmrAgencia());
                System.out.println("Nome: " + agencia.getNmAgencia());
                System.out.println("Cidade: " + agencia.getCidade() + "/" + agencia.getEstado());
                System.out.println("Gerente: " + agencia.getGerente().getNome());
                System.out.println("Total de funcionários: " + agencia.getFuncionarios().length);

            } catch (IOException e) {
                System.err.println("Erro ao salvar a agência " + nomeArquivo + ": " + e.getMessage());
            }
        }

        System.out.println("----------------------------------------");
        System.out.println("Operação concluída. 5 agências foram salvas em arquivos binários.");
    }
}