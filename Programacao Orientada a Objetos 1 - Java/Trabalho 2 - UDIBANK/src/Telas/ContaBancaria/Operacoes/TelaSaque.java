package Telas.ContaBancaria.Operacoes;

import Classes.ContaBancaria;
import ExceptionsAndInterfaces.ValorInvalidoException;
import Telas.SwingUtils;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class TelaSaque extends JFrame {
    private ContaBancaria conta;
    private JTextField txtValor;
    private JComboBox<String> comboCanal;

    public TelaSaque(ContaBancaria conta) {
        this.conta = conta;
        initComponents();
    }

    private void initComponents() {
        setTitle("Saque - Conta " + conta.getNumeroConta());
        setSize(400, 350);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLocationRelativeTo(null);

        // Painel principal
        JPanel mainPanel = SwingUtils.criarPainelPrincipal();

        // Título
        mainPanel.add(SwingUtils.criarLabelTitulo("Realizar Saque"));
        mainPanel.add(Box.createVerticalStrut(20));

        // Painel de formulário
        JPanel panelForm = new JPanel(new GridLayout(2, 2, 10, 10));
        panelForm.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));

        panelForm.add(new JLabel("Valor do saque:"));
        txtValor = new JTextField();
        panelForm.add(txtValor);

        panelForm.add(new JLabel("Canal:"));
        comboCanal = new JComboBox<>(new String[]{"Caixa Eletrônico", "Guichê", "Internet Banking", "App Mobile"});
        panelForm.add(comboCanal);

        mainPanel.add(panelForm);
        mainPanel.add(Box.createVerticalStrut(20));

        // Painel de botões
        JPanel panelBotoes = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 0));
        JButton btnConfirmar = SwingUtils.criarBotaoEstilizado("Confirmar Saque");
        JButton btnCancelar = SwingUtils.criarBotaoEstilizado("Cancelar", Color.GRAY, Color.WHITE);

        btnConfirmar.addActionListener(this::realizarSaque);
        btnCancelar.addActionListener(e -> dispose());

        panelBotoes.add(btnConfirmar);
        panelBotoes.add(btnCancelar);
        mainPanel.add(panelBotoes);

        add(mainPanel);
    }

    private void realizarSaque(ActionEvent evt) {
        try {
            double valor = Double.parseDouble(txtValor.getText());
            String canal = (String) comboCanal.getSelectedItem();

            conta.sacar(valor, canal);
            JOptionPane.showMessageDialog(this, "Saque realizado com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            dispose();
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Valor inválido!", "Erro", JOptionPane.ERROR_MESSAGE);
        } catch (ValorInvalidoException e) {
            JOptionPane.showMessageDialog(this, e.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}