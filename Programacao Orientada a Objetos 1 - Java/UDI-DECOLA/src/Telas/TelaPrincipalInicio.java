package Telas;

import Dados.InicializarDados;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TelaPrincipalInicio extends JFrame implements ActionListener {

    private final JButton buttonLogin;
    private final JButton buttonCadastro;

    public TelaPrincipalInicio() {
        setTitle("Escolha uma opção");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS)); // Layout de caixa vertical

        // Criação dos botões
        buttonLogin = new JButton("Login");
        buttonLogin.setAlignmentX(Component.CENTER_ALIGNMENT);
        buttonLogin.addActionListener(this);
        // Define o tamanho fixo para o botão de login
        buttonLogin.setMaximumSize(new Dimension(200, 50));

        buttonCadastro = new JButton("Cadastrar");
        buttonCadastro.setAlignmentX(Component.CENTER_ALIGNMENT);
        buttonCadastro.addActionListener(this);
        // Define o tamanho fixo para o botão de cadastro
        buttonCadastro.setMaximumSize(new Dimension(200, 50));

        // Adiciona os botões ao painel
        panel.add(Box.createVerticalGlue()); // Espaço no topo
        panel.add(buttonLogin);
        panel.add(Box.createVerticalStrut(20)); // Espaço entre os botões
        panel.add(buttonCadastro);
        panel.add(Box.createVerticalGlue()); // Espaço no final

        getContentPane().add(panel);

        pack();
        setMinimumSize(new Dimension(800, 800)); // Define o tamanho mínimo da janela
        setLocationRelativeTo(null);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == buttonLogin) {
            abrirTelaLogin();
        } else if (e.getSource() == buttonCadastro) {
            abrirTelaCadastro();
        }
    }

    private void abrirTelaLogin() {
        LoginClienteTela telaLoginCliente = new LoginClienteTela(this); // Passando a instância de TelaPrincipalInicio como argumento
        telaLoginCliente.setVisible(true);
    }

    private void abrirTelaCadastro() {
        CadastroClienteTela telaCadastroCliente = new CadastroClienteTela();
        telaCadastroCliente.setVisible(true);
    }

    public static void main(String[] args) {
        InicializarDados.inicializarDados();

        SwingUtilities.invokeLater(() -> {
            TelaPrincipalInicio telaPrincipalInicio = new TelaPrincipalInicio();
            telaPrincipalInicio.setVisible(true);
        });
    }
}