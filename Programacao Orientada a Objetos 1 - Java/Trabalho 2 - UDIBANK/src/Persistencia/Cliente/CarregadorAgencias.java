package Persistencia.Cliente;

import Classes.Agencia;
import ExceptionsAndInterfaces.ValorInvalidoException;
import Persistencia.Agencia.AgenciaBinarioIO;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CarregadorAgencias {
    public static List<Agencia> carregarTodasAgencias(int quantidade) {
        List<Agencia> agencias = new ArrayList<>();

        for (int i = 1; i <= quantidade; i++) {
            String nomeArquivo = String.format("dados/agencia_%04d.bin", i);
            try {
                Agencia agencia = AgenciaBinarioIO.carregarAgencia(nomeArquivo);
                agencias.add(agencia);
                System.out.println("Agência carregada: " + agencia.getNmrAgencia() + " - " + agencia.getNmAgencia());
            } catch (IOException | ValorInvalidoException e) {
                System.err.println("Erro ao carregar " + nomeArquivo + ": " + e.getMessage());
            }
        }

        return agencias;
    }
}