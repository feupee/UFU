package Telas.Cliente;

import Telas.SwingUtils;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class TelaInicialCliente extends JFrame {
    public TelaInicialCliente() {
        setTitle("Bem-vindo ao Banco");
        setSize(400, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Painel principal com BoxLayout para alinhamento vertical
        JPanel mainPanel = SwingUtils.criarPainelPrincipal();

        // Título centralizado
        JLabel lblTitulo = SwingUtils.criarLabelTitulo("Bem-vindo ao Banco");
        lblTitulo.setAlignmentX(Component.CENTER_ALIGNMENT);
        mainPanel.add(lblTitulo);
        mainPanel.add(Box.createVerticalStrut(30));

        // Painel para agrupar os botões com alinhamento central
        JPanel panelBotoes = new JPanel();
        panelBotoes.setLayout(new BoxLayout(panelBotoes, BoxLayout.Y_AXIS));
        panelBotoes.setAlignmentX(Component.CENTER_ALIGNMENT);

        // Painel para clientes existentes
        JPanel panelLogin = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 0));
        panelLogin.add(new JLabel("Se for cliente: "));
        JButton btnLogin = SwingUtils.criarBotaoEstilizado("Login");
        panelLogin.add(btnLogin);

        // Painel para novos clientes
        JPanel panelCadastro = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 0));
        panelCadastro.add(new JLabel("Se não for cliente: "));
        JButton btnCadastro = SwingUtils.criarBotaoEstilizado("Cadastrar");
        panelCadastro.add(btnCadastro);

        // Adiciona os painéis ao grupo principal
        panelBotoes.add(panelLogin);
        panelBotoes.add(Box.createVerticalStrut(15));
        panelBotoes.add(panelCadastro);

        // Centraliza o painel de botões
        JPanel panelCentral = new JPanel();
        panelCentral.setLayout(new BoxLayout(panelCentral, BoxLayout.X_AXIS));
        panelCentral.add(Box.createHorizontalGlue());
        panelCentral.add(panelBotoes);
        panelCentral.add(Box.createHorizontalGlue());

        mainPanel.add(panelCentral);
        add(mainPanel);

        // Listeners
        btnCadastro.addActionListener((ActionEvent e) -> {
            new TelaCadastroCliente();
            dispose();
        });

        btnLogin.addActionListener((ActionEvent e) -> {
            new TelaClienteLogin();
            dispose();
        });

        setVisible(true);
    }
}