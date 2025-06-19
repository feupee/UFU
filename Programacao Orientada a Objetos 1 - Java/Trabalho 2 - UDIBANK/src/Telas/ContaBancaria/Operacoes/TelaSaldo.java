package Telas.ContaBancaria.Operacoes;

import Classes.ContaBancaria;
import Telas.SwingUtils;

import javax.swing.*;
import java.awt.*;

public class TelaSaldo extends JFrame {
    private ContaBancaria conta;

    public TelaSaldo(ContaBancaria conta) {
        this.conta = conta;
        initComponents();
    }

    private void initComponents() {
        setTitle("Saldo - Conta " + conta.getNumeroConta());
        setSize(350, 250);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLocationRelativeTo(null);

        // Painel principal
        JPanel mainPanel = SwingUtils.criarPainelPrincipal();

        // Título
        mainPanel.add(SwingUtils.criarLabelTitulo("Consulta de Saldo"));
        mainPanel.add(Box.createVerticalStrut(20));

        // Painel de informações
        JPanel panelInfo = new JPanel(new GridLayout(2, 1, 10, 10));
        panelInfo.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));

        panelInfo.add(new JLabel("Número da Conta:"));
        panelInfo.add(new JLabel(conta.getNumeroConta()));

        panelInfo.add(new JLabel("Saldo Atual:"));
        panelInfo.add(new JLabel(String.format("R$ %.2f", conta.getSaldo())));

        mainPanel.add(panelInfo);
        mainPanel.add(Box.createVerticalStrut(20));

        // Botão OK
        JButton btnOk = SwingUtils.criarBotaoEstilizado("OK");
        btnOk.addActionListener(e -> dispose());
        mainPanel.add(btnOk);

        add(mainPanel);
    }
}