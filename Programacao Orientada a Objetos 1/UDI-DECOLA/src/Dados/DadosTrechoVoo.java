package Dados;

import Util.TrechoVoo;
import java.util.ArrayList;
import java.util.List;

public class DadosTrechoVoo {
    public static List<TrechoVoo> trechoVoos = new ArrayList<>();

    public void cadastrar(TrechoVoo trechoVoo) {
        trechoVoos.add(trechoVoo);
    }

    public static void listar() {
        for (TrechoVoo trechoVoo : trechoVoos) {
            trechoVoo.mostrarDados();
        }
    }

    public TrechoVoo buscar(String codigoVoo) {
        for (TrechoVoo trechoVoo : trechoVoos) {
            if (trechoVoo.getCodigo_voo().equals(codigoVoo)) {
                return trechoVoo;
            }
        }
        return null; // Retorna null se o voo não for encontrado
    }

    public boolean excluir(String codigoVoo) {
        TrechoVoo trechoVoo = this.buscar(codigoVoo);
        if (trechoVoo != null) {
            trechoVoos.remove(trechoVoo);
            return true;
        } else {
            return false;
        }
    }

    // Método para obter todas as cidades de origem dos trechos de voo // Array
    public static List<String> obterOrigens() {
        List<String> origens = new ArrayList<>();
        for (TrechoVoo trecho : trechoVoos) {
            String origem = trecho.getOrigem().getCidade();
            if (!origens.contains(origem)) {
                origens.add(origem);
            }
        }
        return origens;
    }


    // Método para obter todas as cidades de destino com base na origem selecionada // Array
    public static List<String> obterDestinos(String origemSelecionada) {
        List<String> destinos = new ArrayList<>();
        for (TrechoVoo trecho : trechoVoos) {
            if (trecho.getOrigem().getCidade().equals(origemSelecionada)) {
                String destino = trecho.getDestino().getCidade();
                if (!destinos.contains(destino)) {
                    destinos.add(destino);
                }
            }
        }
        return destinos;
    }

    public static String obterOrigemDoDestino(String destinoSelecionado) { //Valor
        for (TrechoVoo trecho : trechoVoos) {
            if (trecho.getDestino().getCidade().equals(destinoSelecionado)) {
                return trecho.getOrigem().getCidade();
            }
        }
        return null; // Retorna null se o destino não for encontrado
    }

    public static String obterDestinoDaOrigem(String origemSelecionada) { //Valor
        for (TrechoVoo trecho : trechoVoos) {
            if (trecho.getOrigem().getCidade().equals(origemSelecionada)) {
                return trecho.getDestino().getCidade();
            }
        }
        return null; // Retorna null se a origem não for encontrada
    }

    public static TrechoVoo buscarTrecho(String origem, String destino) {
        for (TrechoVoo trecho : trechoVoos) {
            if (trecho.getOrigem().getCidade().equals(origem) && trecho.getDestino().getCidade().equals(destino)) {
                return trecho;
            }
        }
        return null; // Retorna null se o trecho não for encontrado
    }
}