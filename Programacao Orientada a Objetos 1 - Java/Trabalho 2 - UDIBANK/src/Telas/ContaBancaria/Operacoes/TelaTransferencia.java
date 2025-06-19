package Telas.ContaBancaria.Operacoes;

import Classes.ContaBancaria;
import ExceptionsAndInterfaces.ValorInvalidoException;
import Persistencia.BancoDados;
import Telas.SwingUtils;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.util.List;

public class TelaTransferencia extends JFrame {
    private ContaBancaria contaOrigem;
    private List<ContaBancaria> todasContas;
    private JTextField txtValor;
    private JComboBox<ContaBancaria> comboContas;
    private JComboBox<String> comboCanal;

    public TelaTransferencia(ContaBancaria contaOrigem) {
        this.contaOrigem = contaOrigem;
        this.todasContas = BancoDados.getTodasContas();
        initComponents();
    }

    private void initComponents() {
        setTitle("Transferência - Conta " + contaOrigem.getNumeroConta());
        setSize(500, 300);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLocationRelativeTo(null);

        // Painel principal
        JPanel mainPanel = SwingUtils.criarPainelPrincipal();

        // Título
        mainPanel.add(SwingUtils.criarLabelTitulo("Realizar Transferência"));
        mainPanel.add(Box.createVerticalStrut(20));

        // Painel de formulário
        JPanel panelForm = new JPanel(new GridLayout(3, 2, 10, 10));
        panelForm.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));

        panelForm.add(new JLabel("Valor da transferência:"));
        txtValor = new JTextField();
        panelForm.add(txtValor);

        panelForm.add(new JLabel("Conta destino:"));
        comboContas = new JComboBox<>();
        todasContas.stream()
                .filter(c -> !c.getNumeroConta().equals(contaOrigem.getNumeroConta()))
                .forEach(comboContas::addItem);
        panelForm.add(comboContas);

        panelForm.add(new JLabel("Canal:"));
        comboCanal = new JComboBox<>(new String[]{"Caixa Eletrônico", "Guichê", "Internet Banking", "App Mobile"});
        panelForm.add(comboCanal);

        mainPanel.add(panelForm);
        mainPanel.add(Box.createVerticalStrut(20));

        // Painel de botões
        JPanel panelBotoes = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 0));
        JButton btnConfirmar = SwingUtils.criarBotaoEstilizado("Confirmar Transferência");
        JButton btnCancelar = SwingUtils.criarBotaoEstilizado("Cancelar", Color.GRAY, Color.WHITE);

        btnConfirmar.addActionListener(this::realizarTransferencia);
        btnCancelar.addActionListener(e -> dispose());

        panelBotoes.add(btnConfirmar);
        panelBotoes.add(btnCancelar);
        mainPanel.add(panelBotoes);

        add(mainPanel);
    }

    private void realizarTransferencia(ActionEvent evt) {
        try {
            double valor = Double.parseDouble(txtValor.getText());
            ContaBancaria contaDestino = (ContaBancaria) comboContas.getSelectedItem();
            String canal = (String) comboCanal.getSelectedItem();

            contaOrigem.efetuarPagamento(valor, contaDestino, canal);
            JOptionPane.showMessageDialog(this, "Transferência realizada com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            dispose();
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Valor inválido!", "Erro", JOptionPane.ERROR_MESSAGE);
        } catch (ValorInvalidoException e) {
            JOptionPane.showMessageDialog(this, e.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}