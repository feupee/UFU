package Telas;

import Telas.Cliente.TelaInicialCliente;

import static Persistencia.BancoDados.carregarTudo;

public class JanelaPrincipal {
    public static void main(String[] args) {
        carregarTudo();
        new TelaInicialCliente();
    }
}
