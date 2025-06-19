package Telas.ContaBancaria;

import javax.swing.*;
import java.awt.*;

import Classes.*;
import Persistencia.BancoDados;
import java.util.Date;

import static Persistencia.Conta.GeradorContasBancarias.gerarNumeroConta;

public class TelaCadastroConta extends JFrame {
    private JComboBox<String> tipoContaBox;
    private JPasswordField senhaField;
    private JTextField campoExtra;
    private JButton cadastrarButton;
    private Cliente clienteAssociado;
    private Agencia agenciaAssociada;

    public TelaCadastroConta(Cliente cliente, Agencia agencia) {
        this.clienteAssociado = cliente;
        this.agenciaAssociada = agencia;

        setTitle("Cadastro de Conta");
        setSize(350, 250);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 2, 5, 5));

        panel.add(new JLabel("Tipo de Conta:"));
        tipoContaBox = new JComboBox<>(new String[]{"Corrente", "Poupanca", "Salario"});
        panel.add(tipoContaBox);

        panel.add(new JLabel("Senha da Conta:"));
        senhaField = new JPasswordField();
        panel.add(senhaField);

        panel.add(new JLabel("Campo Extra:"));
        campoExtra = new JTextField();
        panel.add(campoExtra);

        cadastrarButton = new JButton("Cadastrar");
        panel.add(cadastrarButton);

        add(panel);

        tipoContaBox.addActionListener(e -> atualizarCampoExtra());
        cadastrarButton.addActionListener(e -> cadastrarConta());

        atualizarCampoExtra();
        setVisible(true);
    }

    private void atualizarCampoExtra() {
        String tipo = (String) tipoContaBox.getSelectedItem();
        if (tipo.equals("Corrente")) {
            campoExtra.setBorder(BorderFactory.createTitledBorder("Limite e taxa separados por vírgula (ex: 1000,25)"));
        } else if (tipo.equals("Poupanca")) {
            campoExtra.setBorder(BorderFactory.createTitledBorder("Rendimento mensal"));
        } else if (tipo.equals("Salario")) {
            campoExtra.setBorder(BorderFactory.createTitledBorder("Limite de saque e transferência (ex: 1000,1000)"));
        }
    }

    private void cadastrarConta() {
        String tipo = (String) tipoContaBox.getSelectedItem();
        String senha = new String(senhaField.getPassword());
        String extra = campoExtra.getText();

        try {
            ContaBancaria conta = null;
            String numeroConta = gerarNumeroConta();
            Date hoje = new Date();
            boolean status = true;
            double saldoInicial = 0.0;

            switch (tipo) {
                case "Corrente" -> {
                    String[] partes = extra.split(",");
                    double limite = Double.parseDouble(partes[0].trim());
                    double taxa = Double.parseDouble(partes[1].trim());
                    conta = new ContaCorrente(numeroConta, saldoInicial, hoje, limite, taxa, numeroConta, senha, status, agenciaAssociada, clienteAssociado);
                }
                case "Poupanca" -> {
                    double rendimento = Double.parseDouble(extra);
                    conta = new ContaPoupanca(numeroConta, saldoInicial, hoje, rendimento, senha, status, agenciaAssociada, clienteAssociado);
                }
                case "Salario" -> {
                    String[] limites = extra.split(",");
                    double limiteSaque = Double.parseDouble(limites[0].trim());
                    double limiteTransf = Double.parseDouble(limites[1].trim());
                    conta = new ContaSalario(numeroConta, saldoInicial, hoje, limiteSaque, limiteTransf, senha, status, agenciaAssociada, clienteAssociado);
                }
            }

            if (conta != null) {
                BancoDados.adicionarConta(conta);
                JOptionPane.showMessageDialog(this, "Conta " + tipo + "Numero Conta: " + conta.getNumeroConta() + " cadastrada com sucesso!");
                dispose();
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Erro ao cadastrar conta: " + e.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}