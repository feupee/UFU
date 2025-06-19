package Telas.ContaBancaria;

import Classes.Cliente;
import Classes.ContaBancaria;
import Persistencia.BancoDados;
import Telas.ContaBancaria.Operacoes.TelaOperacoes;

import javax.swing.*;
import java.awt.*;

public class TelaLoginConta extends JFrame {
    private JTextField numeroContaField;
    private JPasswordField senhaField;
    private JButton loginButton;
    private Cliente cliente;

    public TelaLoginConta(Cliente cliente_associado) {
        this.cliente = cliente_associado;
        setTitle("Login da Conta");
        setSize(300, 200);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        JPanel panel = new JPanel(new GridLayout(3, 2, 5, 5));

        panel.add(new JLabel("Numero da Conta:"));
        numeroContaField = new JTextField();
        panel.add(numeroContaField);

        panel.add(new JLabel("Senha:"));
        senhaField = new JPasswordField();
        panel.add(senhaField);

        loginButton = new JButton("Entrar");
        panel.add(loginButton);

        add(panel);

        loginButton.addActionListener(e -> fazerLogin());

        setVisible(true);
    }

    private void fazerLogin() {
        String numeroConta = numeroContaField.getText();
        String senha = new String(senhaField.getPassword());

        ContaBancaria conta = BancoDados.buscarContaPorNum(numeroConta);

        if (conta != null && conta.getSenha().equals(senha)) {
            Cliente[] associados = conta.getClientes(); // método que retorna o array de clientes

            boolean clienteAssociado = false;
            for (Cliente c : associados) {
                if (c != null && c.getCPF().equals(cliente.getCPF())) {
                    clienteAssociado = true;
                    break;
                }
            }

            if (clienteAssociado) {
                JOptionPane.showMessageDialog(this, "Login bem-sucedido!");
                new TelaOperacoes(conta);
                dispose();
            } else {
                JOptionPane.showMessageDialog(this, "Esta conta não está associada ao cliente logado.");
            }
        } else {
            JOptionPane.showMessageDialog(this, "Número da conta ou senha incorretos.");
        }
    }
}