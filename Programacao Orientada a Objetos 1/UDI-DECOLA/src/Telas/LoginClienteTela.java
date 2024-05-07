package Telas;

import Dados.DadosCliente;
import Util.Cliente;
import Ferramentas.LimitadorDeCaracteres;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import static PostgreSQL.Busca_Registro.buscarSenhaCliente_Banco;

public class LoginClienteTela extends JFrame implements ActionListener {

    private JTextField textFieldCPF;
    private JPasswordField passwordFieldSenha;
    private JButton buttonLogin;
    private JButton buttonVoltar;
    private JLabel labelMensagem;
    private TelaPrincipalInicio telaPrincipalInicio;

    private DadosCliente dadosCliente;

    public LoginClienteTela(TelaPrincipalInicio telaPrincipalInicio) {
        setTitle("Login de Cliente");

        setMinimumSize(new Dimension(800, 800));
        dadosCliente = new DadosCliente();
        this.telaPrincipalInicio = telaPrincipalInicio;

        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);

        JLabel labelCPF = new JLabel("CPF:");
        textFieldCPF = new JTextField(20);
        JLabel labelSenha = new JLabel("Senha:");
        passwordFieldSenha = new JPasswordField(20);
        buttonLogin = new JButton("Login");
        buttonVoltar = new JButton("Voltar");
        labelMensagem = new JLabel("");

        // Adicionando limitadores de caracteres aos campos CPF e senha
        textFieldCPF.setDocument(new LimitadorDeCaracteres(11));
        passwordFieldSenha.setDocument(new LimitadorDeCaracteres(20));

        gbc.gridx = 0;
        gbc.gridy = 0;
        panel.add(labelCPF, gbc);

        gbc.gridy++;
        panel.add(labelSenha, gbc);

        gbc.gridx = 1;
        gbc.gridy = 0;
        panel.add(textFieldCPF, gbc);

        gbc.gridy++;
        panel.add(passwordFieldSenha, gbc);

        gbc.gridx = 0;
        gbc.gridy++;
        gbc.gridwidth = 2;
        panel.add(buttonLogin, gbc);

        gbc.gridy++;
        panel.add(buttonVoltar, gbc);

        gbc.gridy++;
        panel.add(labelMensagem, gbc);

        getContentPane().add(panel);
        pack();
        setLocationRelativeTo(null);

        buttonLogin.addActionListener(this);
        buttonVoltar.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == buttonLogin) {
            fazerLogin();
        } else if (e.getSource() == buttonVoltar) {
            voltarParaTelaPrincipal();
        }
    }

    private void fazerLogin() {
        String cpf = textFieldCPF.getText();
        String senha = new String(passwordFieldSenha.getPassword());
        String senhaEncontrada = buscarSenhaCliente_Banco(cpf);

        if (senhaEncontrada != null && senhaEncontrada.equals(senha)) {
            // Salva o CPF do usuário logado na classe DadosCliente
            DadosCliente.setCpfUsuarioLogado(cpf);

            JOptionPane.showMessageDialog(this, "Bem-vindo!", "Login bem-sucedido", JOptionPane.INFORMATION_MESSAGE);
            telaPrincipalInicio.setVisible(false);
            TelaPrincipalPrograma telaPrincipalPrograma = new TelaPrincipalPrograma();
            telaPrincipalPrograma.setVisible(true);
            dispose();
        } else {
            JOptionPane.showMessageDialog(this, "CPF ou senha incorretos!", "Erro de Login", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void voltarParaTelaPrincipal() {
        dispose();
    }
}