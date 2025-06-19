package Telas.ContaBancaria.Operacoes;

import Classes.ContaBancaria;
import Telas.SwingUtils;

import javax.swing.*;
import java.awt.*;

public class TelaOperacoes extends JFrame {
    private ContaBancaria conta;

    public TelaOperacoes(ContaBancaria conta) {
        this.conta = conta;
        initComponents();
    }

    private void initComponents() {
        setTitle("Operações - Conta " + conta.getNumeroConta());
        setSize(350, 300);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLocationRelativeTo(null);

        // Painel principal
        JPanel mainPanel = SwingUtils.criarPainelPrincipal();

        // Título
        mainPanel.add(SwingUtils.criarLabelTitulo("Operações Bancárias"));
        mainPanel.add(Box.createVerticalStrut(20));

        // Painel de botões
        JPanel panelBotoes = new JPanel();
        panelBotoes.setLayout(new GridLayout(5, 1, 10, 10));
        panelBotoes.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));

        // Botões estilizados
        JButton btnSaque = SwingUtils.criarBotaoEstilizado("Saque");
        JButton btnDeposito = SwingUtils.criarBotaoEstilizado("Depósito");
        JButton btnTransferencia = SwingUtils.criarBotaoEstilizado("Transferência");
        JButton btnSaldo = SwingUtils.criarBotaoEstilizado("Consultar Saldo");
        JButton btnVoltar = SwingUtils.criarBotaoEstilizado("Voltar", Color.GRAY, Color.WHITE);

        // Ações dos botões
        btnSaque.addActionListener(e -> {
            new TelaSaque(conta).setVisible(true);
        });

        btnDeposito.addActionListener(e -> {
            new TelaDeposito(conta).setVisible(true);
        });

        btnTransferencia.addActionListener(e -> {
            new TelaTransferencia(conta).setVisible(true);
        });

        btnSaldo.addActionListener(e -> {
            new TelaSaldo(conta).setVisible(true);
        });

        btnVoltar.addActionListener(e -> dispose());

        // Adiciona botões ao painel
        panelBotoes.add(btnSaque);
        panelBotoes.add(btnDeposito);
        panelBotoes.add(btnTransferencia);
        panelBotoes.add(btnSaldo);
        panelBotoes.add(btnVoltar);

        mainPanel.add(panelBotoes);
        add(mainPanel);

        setVisible(true);
    }
}