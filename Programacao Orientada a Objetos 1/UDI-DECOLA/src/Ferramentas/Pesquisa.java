package Ferramentas;

import java.util.Date;

public class Pesquisa {
    private String origem;
    private String destino;
    private Date dataInicio;
    private Date dataFim;
    private Date dataHoraRealizacao;

    // Construtor
    public Pesquisa(String origem, String destino, Date dataInicio, Date dataFim, Date dataHoraRealizacao) {
        this.origem = origem;
        this.destino = destino;
        this.dataInicio = dataInicio;
        this.dataFim = dataFim;
        this.dataHoraRealizacao = dataHoraRealizacao;
    }

    // Métodos getters e setters
    public String getOrigem() {
        return origem;
    }

    public void setOrigem(String origem) {
        this.origem = origem;
    }

    public String getDestino() {
        return destino;
    }

    public void setDestino(String destino) {
        this.destino = destino;
    }

    public Date getDataInicio() {
        return dataInicio;
    }

    public void setDataInicio(Date dataInicio) {
        this.dataInicio = dataInicio;
    }

    public Date getDataFim() {
        return dataFim;
    }

    public void setDataFim(Date dataFim) {
        this.dataFim = dataFim;
    }

    public Date getDataHoraRealizacao() {
        return dataHoraRealizacao;
    }

    public void setDataHoraRealizacao(Date dataHoraRealizacao) {
        this.dataHoraRealizacao = dataHoraRealizacao;
    }
}