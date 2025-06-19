package Telas.Cliente;

import Classes.Agencia;
import Classes.Cliente;
import Persistencia.BancoDados;
import Telas.ContaBancaria.TelaInicialContaBancaria;
import Telas.SwingUtils;

import javax.swing.*;
import java.awt.*;
import java.util.List;

public class TelaClienteLogin extends JFrame {
    public TelaClienteLogin() {
        setTitle("Login da Conta");
        setSize(350, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Painel principal
        JPanel mainPanel = SwingUtils.criarPainelPrincipal();

        // Campos de login
        JPanel panelCampos = new JPanel(new GridLayout(2, 2, 5, 15));
        panelCampos.add(new JLabel("Nome:"));
        JTextField txtNomeConta = new JTextField();
        panelCampos.add(txtNomeConta);

        panelCampos.add(new JLabel("CPF:"));
        JPasswordField txtSenha = new JPasswordField();
        panelCampos.add(txtSenha);

        mainPanel.add(panelCampos);
        mainPanel.add(Box.createVerticalStrut(20));

        // Painel de botões
        JPanel panelBotoes = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 0));
        JButton btnEntrar = SwingUtils.criarBotaoEstilizado("Entrar");
        JButton btnVoltar = SwingUtils.criarBotaoEstilizado("Voltar", Color.GRAY, Color.WHITE);

        panelBotoes.add(btnEntrar);
        panelBotoes.add(btnVoltar);
        mainPanel.add(panelBotoes);

        // Listeners
        btnEntrar.addActionListener(e -> {
            String nomeCliente = txtNomeConta.getText();
            String CPF = new String(txtSenha.getPassword());

            if (verificarLogin(nomeCliente, CPF)) {
                JOptionPane.showMessageDialog(null, "Login realizado com sucesso!");
                Cliente cliente = BancoDados.buscarClientePorCPF(CPF);
                Agencia agencia = cliente.getAgencia();
                new TelaInicialContaBancaria(cliente, agencia);
                dispose();
            } else {
                JOptionPane.showMessageDialog(null, "Nome ou CPF incorretos.");
            }
        });

        btnVoltar.addActionListener(e -> {
            new TelaInicialCliente();
            dispose();
        });

        add(mainPanel);
        setVisible(true);
    }

    private boolean verificarLogin(String nomeCliente, String CPF) {
        List<Cliente> clientes = BancoDados.getTodosClientes();
        for (Cliente c : clientes) {
            if (c.getNome().equalsIgnoreCase(nomeCliente.trim()) &&
                    c.getCPF().replaceAll("[^0-9]", "").equals(CPF.replaceAll("[^0-9]", ""))) {
                return true;
            }
        }
        return false;
    }
}