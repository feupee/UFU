package Util;

import Util.Aeroporto;

import java.util.*;

public class Companhia_Aerea {
    private String cnpj, nome_oficial, nome_de_divulgacao, data_de_criacao, quantidade_de_vagas, valor_do_voo;
    private List<Aeroporto> listaDeAeroportos;

    static final double valorFixoPorPassagemVendida = 10.0; // Valor fixo por cada passagem vendida

    //Construtor
    public Companhia_Aerea(String cnpj, String nome_oficial, String nome_de_divulgacao, String data_de_criacao, String vagas, String valor) {
        this.cnpj = cnpj;
        this.nome_oficial = nome_oficial;
        this.nome_de_divulgacao = nome_de_divulgacao;
        this.data_de_criacao = data_de_criacao;
        this.quantidade_de_vagas = vagas;
        this.valor_do_voo = valor;
        this.listaDeAeroportos = new ArrayList<>();
    }

    //Getters And Setters
    public String getCnpj() {
        return cnpj;
    }

    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }

    public String getNome_oficial() {
        return nome_oficial;
    }

    public void setNome_oficial(String nome_oficial) {
        this.nome_oficial = nome_oficial;
    }

    public String getNome_de_divulgacao() {
        return nome_de_divulgacao;
    }

    public void setNome_de_divulgacao(String nome_de_divulgacao) {
        this.nome_de_divulgacao = nome_de_divulgacao;
    }

    public String getData_de_criacao() {
        return data_de_criacao;
    }

    public void setData_de_criacao(String data_de_criacao) {
        this.data_de_criacao = data_de_criacao;
    }

    public String getQuantidade_de_vagas() {
        return quantidade_de_vagas;
    }

    public void setQuantidade_de_vagas(String quantidade_de_vagas) {
        this.quantidade_de_vagas = quantidade_de_vagas;
    }

    public String getValor_do_voo() {
        return valor_do_voo;
    }

    public void setValor_do_voo(String valor_do_voo) {
        this.valor_do_voo = valor_do_voo;
    }

    public List<Aeroporto> getListaDeAeroportos() {
        return listaDeAeroportos;
    }

    public void setListaDeAeroportos(List<Aeroporto> listaDeAeroportos) {
        this.listaDeAeroportos = listaDeAeroportos;
    }

    public void adicionarAeroporto(Aeroporto aeroporto) {
        listaDeAeroportos.add(aeroporto);
    }
    public List<Aeroporto> getListaDeAeroporto(){
        return listaDeAeroportos;
    }
}

