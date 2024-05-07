package Ferramentas;

import Util.TrechoVoo;

import java.util.List;

public class GerenciadorVoos {
    // Método estático para encontrar o melhor voo com base nos critérios especificados
    public static TrechoVoo encontrarMelhorVoo(List<TrechoVoo> trechoVoos, String origem, String destino, String data) {
        TrechoVoo melhorTrechoVoo = null;
        int menorTempoEstimado = Integer.MAX_VALUE; // Inicializa com o maior valor possível
        int maiorQuantidadeVagas = Integer.MIN_VALUE; // Inicializa com o menor valor possível

        for (TrechoVoo trechoVoo : trechoVoos) {
            if (trechoVoo.getOrigem().getCidade().equals(origem) &&
                    trechoVoo.getDestino().getCidade().equals(destino) &&
                    trechoVoo.getData().equals(data)) {

                // Verifica se o voo tem um tempo estimado menor que o atual
                int tempoEstimado = trechoVoo.calcularTempoEstimado();
                if (tempoEstimado < menorTempoEstimado) {
                    menorTempoEstimado = tempoEstimado;
                    melhorTrechoVoo = trechoVoo;
                }

                // Verifica se o voo tem uma quantidade de vagas maior que o atual
                int quantidadeVagas = Integer.parseInt(trechoVoo.getQuantidadeDeVagas());
                if (quantidadeVagas > maiorQuantidadeVagas) {
                    maiorQuantidadeVagas = quantidadeVagas;
                    melhorTrechoVoo = trechoVoo;
                }
            }
        }

        return melhorTrechoVoo;
    }
}
