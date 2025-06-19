package Telas.ContaBancaria;

import Classes.Agencia;
import Classes.Cliente;


import javax.swing.*;
import java.awt.*;

import static Telas.SwingUtils.criarBotaoEstilizado;

public class TelaInicialContaBancaria extends JFrame {
    public TelaInicialContaBancaria(Cliente cliente_associado, Agencia agencia_associada) {
        setTitle("Conta Bancária - Menu Principal");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Painel principal com layout vertical
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        // Título
        JLabel lblTitulo = new JLabel("Menu de Conta Bancária");
        lblTitulo.setAlignmentX(Component.CENTER_ALIGNMENT);
        lblTitulo.setFont(new Font("Arial", Font.BOLD, 18));
        mainPanel.add(lblTitulo);
        mainPanel.add(Box.createVerticalStrut(30));

        // Botão Cadastrar nova conta
        JButton btnCadastrar = criarBotaoEstilizado("Cadastrar nova conta");
        btnCadastrar.setAlignmentX(Component.CENTER_ALIGNMENT);
        btnCadastrar.addActionListener(e -> new TelaCadastroConta(cliente_associado, agencia_associada));
        mainPanel.add(btnCadastrar);
        mainPanel.add(Box.createVerticalStrut(15));

        // Botão Acessar conta
        JButton btnAcessar = criarBotaoEstilizado("Acessar conta");
        btnAcessar.setAlignmentX(Component.CENTER_ALIGNMENT);
        btnAcessar.addActionListener(e -> new TelaLoginConta(cliente_associado));
        mainPanel.add(btnAcessar);
        mainPanel.add(Box.createVerticalStrut(15));

        // Botão Sair
        JButton btnSair = criarBotaoEstilizado("Sair", Color.RED, Color.WHITE);
        btnSair.setAlignmentX(Component.CENTER_ALIGNMENT);
        btnSair.addActionListener(e -> System.exit(0));
        mainPanel.add(btnSair);

        // Adicionar o painel principal à janela
        add(mainPanel);

        setVisible(true);
    }
}