package Telas;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Date;
import java.util.List;

import Dados.DadosHotel;
import Util.*;
import Dados.DadosCliente;
import Dados.DadosTrechoVoo;

public class TelaPrincipalPrograma extends JFrame {

    private JLabel labelNome;
    private JLabel labelCPF;
    private JLabel labelEndereco;
    private JLabel labelDataNascimento;
    private JLabel labelEmail;
    private JPanel clientePanel;

    public TelaPrincipalPrograma() {
        setTitle("Tela Principal");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setMinimumSize(new Dimension(1200, 800));
        setResizable(false);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel(new BorderLayout());
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        JPanel buttonPanel = new JPanel(new GridLayout(1, 6, 10, 10));
        JButton btnComprarVoo = new JButton("Compra de Voo");
        JButton btnComprarDiariaHotel = new JButton("Compra de Diária de Hotel");
        JButton btnHistorico = new JButton("Histórico");
        JButton btnPerfil = new JButton("Perfil");
        JButton btnAdministracao = new JButton("Administração");
        JButton btnVoltar = new JButton("Voltar");

        buttonPanel.add(btnComprarVoo);
        buttonPanel.add(btnComprarDiariaHotel);
        buttonPanel.add(btnHistorico);
        buttonPanel.add(btnPerfil);
        buttonPanel.add(btnAdministracao);
        buttonPanel.add(btnVoltar);

        panel.add(buttonPanel, BorderLayout.NORTH);

        clientePanel = new JPanel();
        clientePanel.setPreferredSize(new Dimension(350, 350));
        clientePanel.setLayout(new BoxLayout(clientePanel, BoxLayout.Y_AXIS));
        clientePanel.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        labelNome = new JLabel();
        labelCPF = new JLabel();
        labelEndereco = new JLabel();
        labelDataNascimento = new JLabel();
        labelEmail = new JLabel();

        clientePanel.setVisible(false);
        clientePanel.add(labelNome);
        clientePanel.add(labelCPF);
        clientePanel.add(labelEndereco);
        clientePanel.add(labelDataNascimento);
        clientePanel.add(labelEmail);

        panel.add(clientePanel, BorderLayout.CENTER);

        getContentPane().add(panel);

        String cpfUsuarioLogado = DadosCliente.getCpfUsuarioLogado();
        btnAdministracao.setVisible(cpfUsuarioLogado.equals("15285426650"));

        btnPerfil.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                mostrarInformacoesCliente();
            }
        });

        btnAdministracao.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                abrirTelaAdm();
            }
        });

        btnComprarVoo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                abrirJanelaCompraVoo();
            }
        });

        btnComprarDiariaHotel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                abrirJanelaCompraHotel();
            }
        });

        btnHistorico.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                mostrarHistoricoCompras();
            }
        });

        btnVoltar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                esconderInformacoesCliente();
            }
        });

        btnVoltar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                voltarParaTelaPrincipalInicio();
            }
        });
    }

    private void abrirTelaAdm() {
        TelaAdministracao telaAdministracao = new TelaAdministracao(this);
        telaAdministracao.setVisible(true);
    }

    private void mostrarInformacoesCliente() {
        String cpfUsuarioLogado = DadosCliente.getCpfUsuarioLogado();
        Cliente cliente = DadosCliente.buscar(cpfUsuarioLogado);

        if (cliente != null) {
            labelNome.setText("Nome: " + cliente.getNome());
            labelCPF.setText("CPF: " + cliente.getCpf());
            labelEndereco.setText("Endereço: " + cliente.getEnderecoCompleto());
            labelDataNascimento.setText("Data de Nascimento: " + cliente.getDataNascimento());
            labelEmail.setText("Email: " + cliente.getEmail());

            clientePanel.setVisible(true);
        } else {
            JOptionPane.showMessageDialog(this, "Cliente não encontrado.");
        }
    }

    private void esconderInformacoesCliente() {
        clientePanel.setVisible(false);
    }

    private void abrirJanelaCompraVoo() {
        JFrame frameCompraVoo = new JFrame("Compra de Voo");
        frameCompraVoo.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frameCompraVoo.setSize(400, 250);
        frameCompraVoo.setLocationRelativeTo(this);

        JPanel mainPanel = new JPanel(new BorderLayout());
        JPanel panelCompraVoo = new JPanel(new GridLayout(5, 2, 10, 10));
        panelCompraVoo.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JLabel labelQuantidadePassagens = new JLabel("Quantidade de Passagens:");
        JSpinner spinnerQuantidadePassagens = new JSpinner();
        spinnerQuantidadePassagens.setModel(new SpinnerNumberModel(1, 1, Integer.MAX_VALUE, 1)); // Configura o modelo para aceitar apenas números inteiros positivos

        JLabel labelFormaPagamento = new JLabel("Forma de Pagamento:");
        JComboBox<String> comboBoxFormaPagamento = new JComboBox<>(new String[]{"Crédito", "Débito"});

        JLabel labelOrigem = new JLabel("Origem:");
        JComboBox<String> comboBoxOrigem = new JComboBox<>();
        List<String> origens = DadosTrechoVoo.obterOrigens();
        for (String origem : origens) {
            comboBoxOrigem.addItem(origem);
        }

        JLabel labelDestino = new JLabel("Destino:");
        JComboBox<String> comboBoxDestino = new JComboBox<>();
        comboBoxOrigem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                comboBoxDestino.removeAllItems();
                List<String> destinos = DadosTrechoVoo.obterDestinos((String) comboBoxOrigem.getSelectedItem());
                for (String destino : destinos) {
                    comboBoxDestino.addItem(destino);
                }
            }
        });

        JButton btnConfirmarCompra = new JButton("Confirmar Compra");
        btnConfirmarCompra.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int quantidadePassagens = (int) spinnerQuantidadePassagens.getValue();
                String formaPagamento = (String) comboBoxFormaPagamento.getSelectedItem();
                Date dataHoraCompra = new Date();
                Cliente cliente = DadosCliente.buscar(DadosCliente.getCpfUsuarioLogado());
                String origem = (String) comboBoxOrigem.getSelectedItem();
                String destino = (String) comboBoxDestino.getSelectedItem();
                TrechoVoo trechoVoo = DadosTrechoVoo.buscarTrecho(origem, destino);

                if (trechoVoo != null) {
                    Compras novaCompra = new Compras(quantidadePassagens, formaPagamento, dataHoraCompra, cliente, trechoVoo);
                    cliente.adicionarCompra(novaCompra);
                    JOptionPane.showMessageDialog(null, "Compra efetuada com sucesso!");
                    frameCompraVoo.dispose(); // Fecha a janela de compra após a compra ser efetuada com sucesso
                } else {
                    JOptionPane.showMessageDialog(null, "Trecho de voo não encontrado para os destinos selecionados.", "Erro", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        panelCompraVoo.add(labelQuantidadePassagens);
        panelCompraVoo.add(spinnerQuantidadePassagens);
        panelCompraVoo.add(labelFormaPagamento);
        panelCompraVoo.add(comboBoxFormaPagamento);
        panelCompraVoo.add(labelOrigem);
        panelCompraVoo.add(comboBoxOrigem);
        panelCompraVoo.add(labelDestino);
        panelCompraVoo.add(comboBoxDestino);
        panelCompraVoo.add(new JLabel());
        panelCompraVoo.add(btnConfirmarCompra);

        mainPanel.add(panelCompraVoo, BorderLayout.CENTER);
        frameCompraVoo.add(mainPanel);
        frameCompraVoo.setVisible(true);
    }


    private void abrirJanelaCompraHotel() {
        JFrame frameCompraHotel = new JFrame("Compra de Diária de Hotel");
        frameCompraHotel.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frameCompraHotel.setSize(400, 300);
        frameCompraHotel.setLocationRelativeTo(this);

        JPanel mainPanel = new JPanel(new BorderLayout());
        JPanel panelCompraHotel = new JPanel(new GridLayout(5, 2, 10, 10));
        panelCompraHotel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JLabel labelQuantidadeDiarias = new JLabel("Quantidade de Diárias:");
        JSpinner spinnerQuantidadeDiarias = new JSpinner();
        spinnerQuantidadeDiarias.setModel(new SpinnerNumberModel(1, 1, Integer.MAX_VALUE, 1));

        JLabel labelFormaPagamento = new JLabel("Forma de Pagamento:");
        JComboBox<String> comboBoxFormaPagamento = new JComboBox<>(new String[]{"Crédito", "Débito"});

        JLabel labelCidade = new JLabel("Cidade do Hotel:");
        JComboBox<String> comboBoxCidade = new JComboBox<>();

        // Adicione todas as cidades dos hotéis
        for (Hotel hotel : DadosHotel.getHoteis()) {
            comboBoxCidade.addItem(hotel.getCidade());
        }

        JLabel labelTipoQuarto = new JLabel("Tipo de Quarto:");
        JComboBox<String> comboBoxTipoQuarto = new JComboBox<>();

        // Atualiza o ComboBox de tipo de quarto quando a cidade é selecionada
        comboBoxCidade.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String cidadeSelecionada = (String) comboBoxCidade.getSelectedItem();
                comboBoxTipoQuarto.removeAllItems(); // Limpa os itens existentes

                // Encontra o hotel correspondente à cidade selecionada
                Hotel hotelSelecionado = DadosHotel.buscarHotelPorCidade(cidadeSelecionada);

                // Se o hotel for encontrado, adiciona os tipos de quartos disponíveis
                if (hotelSelecionado != null) {
                    List<String> tiposQuarto = hotelSelecionado.getTiposQuarto();
                    for (String tipo : tiposQuarto) {
                        comboBoxTipoQuarto.addItem(tipo);
                    }
                }
            }
        });

        JButton btnConfirmarCompra = new JButton("Confirmar Compra");
        btnConfirmarCompra.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int quantidadeDiarias = (int) spinnerQuantidadeDiarias.getValue();
                String formaPagamento = (String) comboBoxFormaPagamento.getSelectedItem();
                String cidade = (String) comboBoxCidade.getSelectedItem();
                String tipoQuarto = (String) comboBoxTipoQuarto.getSelectedItem(); // Tipo de quarto selecionado
                Date dataHoraCompra = new Date();
                Cliente cliente = DadosCliente.buscar(DadosCliente.getCpfUsuarioLogado());

                // Obter o valor das diárias e o valor descontado com base no tipo de quarto selecionado
                double valorDiaria = 0.0;
                double desconto = 0.0;

                // Obtenha o hotel correspondente à cidade selecionada
                Hotel hotel = DadosHotel.buscarHotelPorCidade(cidade); // Substitua esse método pelo método apropriado para encontrar o hotel por cidade

                // Verifique se o hotel foi encontrado
                Quarto quartoSelecionado;
                if (hotel != null) {
                    // Obtenha o tipo de quarto correspondente ao tipo selecionado
                    quartoSelecionado = DadosHotel.obterQuartoPorTipo(hotel.getCnpj(), tipoQuarto);

                    // Verifique se o quarto foi encontrado
                    if (quartoSelecionado != null) {
                        // Atribua os valores das diárias e do desconto
                        valorDiaria = quartoSelecionado.getValor_do_quarto();
                        desconto = quartoSelecionado.getDesconto();
                    } else {
                        JOptionPane.showMessageDialog(null, "Quarto não encontrado para o tipo selecionado.");
                        return; // Saia do método actionPerformed se o quarto não for encontrado
                    }
                } else {
                    JOptionPane.showMessageDialog(null, "Hotel não encontrado para a cidade selecionada.");
                    return; // Saia do método actionPerformed se o hotel não for encontrado
                }

                // Criação do objeto Compras para representar a compra de diárias de hotel
                Compras novaCompra = new Compras(formaPagamento, quantidadeDiarias, dataHoraCompra, cliente, quartoSelecionado);

                // Adiciona a nova compra à lista de compras do cliente
                cliente.adicionarCompra(novaCompra);

                JOptionPane.showMessageDialog(null, "Compra de diárias de hotel efetuada com sucesso!");
                frameCompraHotel.dispose(); // Fecha a janela de compra de hotel após a compra ser efetuada com sucesso
            }
        });

        panelCompraHotel.add(labelQuantidadeDiarias);
        panelCompraHotel.add(spinnerQuantidadeDiarias);
        panelCompraHotel.add(labelFormaPagamento);
        panelCompraHotel.add(comboBoxFormaPagamento);
        panelCompraHotel.add(labelCidade);
        panelCompraHotel.add(comboBoxCidade);
        panelCompraHotel.add(labelTipoQuarto);
        panelCompraHotel.add(comboBoxTipoQuarto);
        panelCompraHotel.add(new JLabel());
        panelCompraHotel.add(btnConfirmarCompra);

        mainPanel.add(panelCompraHotel, BorderLayout.CENTER);
        frameCompraHotel.add(mainPanel);
        frameCompraHotel.setVisible(true);
    }



    private void mostrarHistoricoCompras() {
        String cpfUsuarioLogado = DadosCliente.getCpfUsuarioLogado();
        Cliente cliente = DadosCliente.buscar(cpfUsuarioLogado);

        if (cliente != null) {
            List<Compras> compras = cliente.getCompras();
            if (compras != null && !compras.isEmpty()) {
                HistoricoComprasJanela historicoComprasJanela = new HistoricoComprasJanela(compras);
                historicoComprasJanela.setVisible(true);
            } else {
                JOptionPane.showMessageDialog(this, "Este cliente não possui histórico de compras.");
            }
        } else {
            JOptionPane.showMessageDialog(this, "Cliente não encontrado.");
        }
    }

    private void voltarParaTelaPrincipalInicio() {
        dispose();
        TelaPrincipalInicio telaInicio = new TelaPrincipalInicio();
        telaInicio.setVisible(true);
    }
}
