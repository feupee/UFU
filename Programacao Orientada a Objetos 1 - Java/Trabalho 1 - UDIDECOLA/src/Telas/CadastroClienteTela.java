package Telas;
import Arquivos.Escrita_Registro;
import Ferramentas.LimitadorDeCaracteres;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Date;

import Dados.DadosCliente;
import com.toedter.calendar.JDateChooser;

import static PostgreSQL.Insere_Registro.inserirCliente_Banco;


public class CadastroClienteTela extends JFrame implements ActionListener {

    // Componentes da tela
    private JTextField textFieldNome;
    private JTextField textFieldCPF;
    private JTextField textFieldEndereco;
    private JTextField textFieldEmail;
    private JDateChooser dateChooserDataNascimento;
    private JPasswordField passwordFieldSenha;
    private JPasswordField passwordFieldConfirmarSenha;
    private JButton buttonCadastrar;
    private JButton buttonVoltar;
    private JLabel labelMensagem;

    // Instância de Dados.DadosCliente para gerenciar os clientes
    private DadosCliente dadosCliente;

    public CadastroClienteTela() {
        setTitle("Cadastro de Util.Cliente");

        setMinimumSize(new Dimension(800, 800));
        dadosCliente = new DadosCliente();

        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);

        JLabel labelNome = new JLabel("Nome:");
        textFieldNome = new JTextField(20);
        JLabel labelCPF = new JLabel("CPF:");
        textFieldCPF = new JTextField(20);
        JLabel labelEndereco = new JLabel("Endereço:");
        textFieldEndereco = new JTextField(20);
        JLabel labelEmail = new JLabel("Email:");
        textFieldEmail = new JTextField(20);
        JLabel labelDataNascimento = new JLabel("Data de Nascimento:");
        dateChooserDataNascimento = new JDateChooser();
        dateChooserDataNascimento.setPreferredSize(new Dimension(200, 25));
        JLabel labelSenha = new JLabel("Senha:");
        passwordFieldSenha = new JPasswordField(20);
        JLabel labelConfirmarSenha = new JLabel("Confirmar Senha:");
        passwordFieldConfirmarSenha = new JPasswordField(20);
        buttonCadastrar = new JButton("Cadastrar");
        buttonVoltar = new JButton("Voltar");
        labelMensagem = new JLabel("");

        textFieldNome.setDocument(new LimitadorDeCaracteres(50));
        textFieldCPF.setDocument(new LimitadorDeCaracteres(11));
        textFieldEndereco.setDocument(new LimitadorDeCaracteres(100));
        passwordFieldSenha.setDocument(new LimitadorDeCaracteres(20));
        passwordFieldConfirmarSenha.setDocument(new LimitadorDeCaracteres(20));

        gbc.gridx = 0;
        gbc.gridy = 0;
        panel.add(labelNome, gbc);

        gbc.gridy++;
        panel.add(labelCPF, gbc);

        gbc.gridy++;
        panel.add(labelEndereco, gbc);

        gbc.gridy++;
        panel.add(labelEmail, gbc);

        gbc.gridy++;
        panel.add(labelDataNascimento, gbc);

        gbc.gridy++;
        panel.add(labelSenha, gbc);

        gbc.gridy++;
        panel.add(labelConfirmarSenha, gbc);

        gbc.gridx = 1;
        gbc.gridy = 0;
        panel.add(textFieldNome, gbc);

        gbc.gridy++;
        panel.add(textFieldCPF, gbc);

        gbc.gridy++;
        panel.add(textFieldEndereco, gbc);

        gbc.gridy++;
        panel.add(textFieldEmail, gbc);

        gbc.gridy++;
        panel.add(dateChooserDataNascimento, gbc);

        gbc.gridy++;
        panel.add(passwordFieldSenha, gbc);

        gbc.gridy++;
        panel.add(passwordFieldConfirmarSenha, gbc);

        gbc.gridx = 0;
        gbc.gridy++;
        gbc.gridwidth = 2;
        panel.add(buttonCadastrar, gbc);

        gbc.gridy++;
        panel.add(buttonVoltar, gbc);

        gbc.gridy++;
        panel.add(labelMensagem, gbc);

        getContentPane().add(panel);
        pack();
        setLocationRelativeTo(null);

        buttonCadastrar.addActionListener(this);
        buttonVoltar.addActionListener(this);
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == buttonCadastrar) {
            cadastrarCliente();
        } else if (e.getSource() == buttonVoltar) {
            voltarParaTelaPrincipal();
        }
    }

    private void cadastrarCliente() {
        String nome = textFieldNome.getText();
        String cpf = textFieldCPF.getText();
        String endereco = textFieldEndereco.getText();
        String email = textFieldEmail.getText();
        String senha = new String(passwordFieldSenha.getPassword());
        String confirmarSenha = new String(passwordFieldConfirmarSenha.getPassword());
        Date dataNascimento = dateChooserDataNascimento.getDate();

        // Verifica se todos os campos obrigatórios foram preenchidos
        if (nome.isEmpty() || cpf.isEmpty() || endereco.isEmpty() || email.isEmpty() || senha.isEmpty() || confirmarSenha.isEmpty() || dataNascimento == null) {
            JOptionPane.showMessageDialog(this, "Por favor, preencha todos os campos!", "Erro ao cadastrar", JOptionPane.ERROR_MESSAGE);
            return;
        }
        // Verifica se as senhas coincidem
        if (!senha.equals(confirmarSenha)) {
            JOptionPane.showMessageDialog(this, "As senhas não correspondem!", "Erro ao cadastrar", JOptionPane.ERROR_MESSAGE);
            return;
        }

        // Verifica se o CPF é válido
        if (!DadosCliente.validarCPF(cpf)) {
            JOptionPane.showMessageDialog(this, "CPF inválido!", "Erro ao cadastrar", JOptionPane.ERROR_MESSAGE);
            return;
        }

        // Verifica se o CPF já está cadastrado
        if (DadosCliente.buscar(cpf) != null) {
            JOptionPane.showMessageDialog(this, "CPF já cadastrado!", "Erro ao cadastrar", JOptionPane.ERROR_MESSAGE);
            return;
        }

        // Insere os dados no banco de dados e Arquivo
        DadosCliente.cadastrarCliente(nome, cpf, endereco, dataNascimento,email, senha); //Array
        Escrita_Registro.salvarCliente(nome, cpf, endereco, email, senha, dataNascimento); //Arquivo
        inserirCliente_Banco(nome, cpf, endereco, email, senha, dataNascimento); //Banco de Dados

        // Exibe mensagem de sucesso
        JOptionPane.showMessageDialog(this, "Cadastro realizado com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);

        // Fecha a tela de cadastro
        voltarParaTelaPrincipal();
    }

    private void voltarParaTelaPrincipal() {
        dispose();
    }
}