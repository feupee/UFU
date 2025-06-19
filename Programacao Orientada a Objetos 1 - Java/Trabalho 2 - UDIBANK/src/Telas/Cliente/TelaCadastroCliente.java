package Telas.Cliente;

import Classes.Agencia;
import Classes.Cliente;
import ExceptionsAndInterfaces.ValorInvalidoException;
import Persistencia.BancoDados;
import Telas.SwingUtils;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import static Classes.ValidadorCPF.validarCPF;

public class TelaCadastroCliente extends JFrame {
    private JTextField txtCpf, txtNome, txtEndereco, txtEscolaridade;
    private JComboBox<String> comboEstadoCivil;
    private JFormattedTextField txtDataNascimento;
    private JComboBox<Agencia> comboAgencias;

    public TelaCadastroCliente() {
        setTitle("Cadastro de Cliente");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLocationRelativeTo(null);

        // Layout principal
        JPanel mainPanel = SwingUtils.criarPainelPrincipal();

        // Painel de dados
        JPanel panelDados = new JPanel(new GridLayout(0, 2, 5, 10));
        panelDados.setBorder(BorderFactory.createTitledBorder("Dados Pessoais"));
        adicionarComponentes(panelDados);

        // Painel de botões
        JPanel panelBotoes = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 10));
        JButton btnConfirmar = SwingUtils.criarBotaoEstilizado("Confirmar");
        JButton btnCancelar = SwingUtils.criarBotaoEstilizado("Cancelar", Color.RED, Color.WHITE);

        // Configuração dos componentes
        mainPanel.add(panelDados);
        panelBotoes.add(btnConfirmar);
        panelBotoes.add(btnCancelar);

        // Listeners
        btnConfirmar.addActionListener(new ConfirmarCadastroListener());
        btnCancelar.addActionListener(e -> {
            new TelaInicialCliente().setVisible(true);
            dispose();
        });

        add(mainPanel, BorderLayout.CENTER);
        add(panelBotoes, BorderLayout.SOUTH);
        setVisible(true);
    }

    private void adicionarComponentes(JPanel panel) {
        panel.add(new JLabel("CPF:"));
        txtCpf = new JTextField();
        panel.add(txtCpf);

        panel.add(new JLabel("Nome Completo:"));
        txtNome = new JTextField();
        panel.add(txtNome);

        panel.add(new JLabel("Endereço:"));
        txtEndereco = new JTextField();
        panel.add(txtEndereco);

        panel.add(new JLabel("Estado Civil:"));
        comboEstadoCivil = new JComboBox<>(new String[]{"Solteiro(a)", "Casado(a)", "Divorciado(a)", "Viúvo(a)", "Separado(a)"});
        panel.add(comboEstadoCivil);

        panel.add(new JLabel("Escolaridade:"));
        txtEscolaridade = new JTextField();
        panel.add(txtEscolaridade);

        panel.add(new JLabel("Data Nascimento (dd/MM/yyyy):"));
        txtDataNascimento = new JFormattedTextField(new SimpleDateFormat("dd/MM/yyyy"));
        panel.add(txtDataNascimento);

        panel.add(new JLabel("Agência:"));
        comboAgencias = new JComboBox<>();
        comboAgencias.setRenderer(new DefaultListCellRenderer() {
            @Override
            public Component getListCellRendererComponent(JList<?> list, Object value, int index, boolean isSelected, boolean cellHasFocus) {
                super.getListCellRendererComponent(list, value, index, isSelected, cellHasFocus);
                if (value instanceof Agencia) {
                    Agencia agencia = (Agencia) value;
                    setText(agencia.getNmAgencia() + " - " + agencia.getEndereco());
                }
                return this;
            }
        });
        carregarAgenciasNoCombo();
        panel.add(comboAgencias);
    }

    private void carregarAgenciasNoCombo() {
        comboAgencias.removeAllItems();
        List<Agencia> agencias = BancoDados.getTodasAgencias();
        agencias.forEach(comboAgencias::addItem);
    }

    private class ConfirmarCadastroListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try {
                validarCampos();
                Cliente novoCliente = criarCliente();
                BancoDados.adicionarCliente(novoCliente);

                JOptionPane.showMessageDialog(null, "Cliente cadastrado com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
                new TelaInicialCliente().setVisible(true);
                dispose();
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
            }
        }

        private void validarCampos() throws Exception {
            if (txtCpf.getText().isEmpty() || txtNome.getText().isEmpty() ||
                    txtEndereco.getText().isEmpty() || txtEscolaridade.getText().isEmpty() ||
                    txtDataNascimento.getText().isEmpty()) {
                throw new Exception("Todos os campos são obrigatórios!");
            }
            if (!validarCPF(txtCpf.getText())) {
                throw new Exception("CPF inválido!");
            }
            if (comboAgencias.getSelectedItem() == null) {
                throw new Exception("Selecione uma agência válida!");
            }
        }

        private Cliente criarCliente() throws ParseException, ValorInvalidoException {
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
            Date dataNascimento = sdf.parse(txtDataNascimento.getText());
            Agencia agencia = (Agencia) comboAgencias.getSelectedItem();

            return new Cliente(
                    txtCpf.getText(),
                    txtNome.getText(),
                    txtEndereco.getText(),
                    (String) comboEstadoCivil.getSelectedItem(),
                    txtEscolaridade.getText(),
                    dataNascimento,
                    agencia
            );
        }
    }
}