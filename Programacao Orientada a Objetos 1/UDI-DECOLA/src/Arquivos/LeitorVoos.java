package Arquivos;

import Dados.DadosTrechoVoo;
import Util.Aeroporto;
import Util.TrechoVoo;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class LeitorVoos {
    public static void lerArquivo(String caminhoArquivo, DadosTrechoVoo dadosTrechoVoo) {
        try (BufferedReader br = new BufferedReader(new FileReader(caminhoArquivo))) {
            String linha;
            while ((linha = br.readLine()) != null) {
                // Separar os dados da linha
                String[] dados = linha.split(";");

                // Criar Aeroportos para origem e destino
                Aeroporto origem = new Aeroporto(dados[2], dados[3]);
                Aeroporto destino = new Aeroporto(dados[4], dados[5]);

                // Converter os valores de String para double
                double valorDoVoo = 0.0; // valor padrão
                try {
                    valorDoVoo = Double.parseDouble(dados[8]);
                } catch (NumberFormatException e) {
                    System.err.println("Erro ao converter o valor do voo em double: " + e.getMessage());
                    // Trate o erro aqui, por exemplo, atribua um valor padrão
                }

                // Criar TrechoVoo e adicionar à lista de voos em dadosTrechoVoo
                TrechoVoo trechoVoo = new TrechoVoo(dados[0], dados[1], origem, destino, dados[6], dados[7], valorDoVoo, dados[9]);
                dadosTrechoVoo.cadastrar(trechoVoo);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void lerArquivo(DadosTrechoVoo dadosTrechoVoo) {
        String caminhoArquivo = "Arquivos/voos.txt"; // Caminho do arquivo estático
        lerArquivo(caminhoArquivo, dadosTrechoVoo);
    }
}