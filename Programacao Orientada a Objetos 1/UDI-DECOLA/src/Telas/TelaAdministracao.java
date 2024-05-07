package Telas;

import Dados.DadosCliente;
import Dados.DadosFuncionarios;
import Dados.DadosHotel;
import Dados.DadosTrechoVoo;
import Util.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Date;

public class TelaAdministracao extends JFrame {

    public TelaAdministracao(TelaPrincipalPrograma telaPrincipalPrograma) {

        setTitle("Administração");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // Fecha apenas esta janela, não a aplicação inteira
        setPreferredSize(new Dimension(400, 300));
        setLocationRelativeTo(telaPrincipalPrograma); // Abre no centro da tela principal

        JPanel panel = new JPanel(new GridLayout(4, 1, 10, 10));
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        JButton btnAdicionarVoo = new JButton("Adicionar Voo");
        JButton btnAdicionarHotel = new JButton("Adicionar Hotel");
        JButton btnAdicionarFuncionario = new JButton("Adicionar Funcionário");
        JButton btnAdicionarCliente = new JButton("Adicionar Cliente");

        // Definindo o tamanho dos botões
        Dimension btnSize = new Dimension(200, 50);
        btnAdicionarVoo.setPreferredSize(btnSize);
        btnAdicionarHotel.setPreferredSize(btnSize);
        btnAdicionarFuncionario.setPreferredSize(btnSize);
        btnAdicionarCliente.setPreferredSize(btnSize);


        btnAdicionarVoo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Inputs para o cadastro do voo
                JTextField horarioEntradaField = new JTextField();
                JTextField horarioSaidaField = new JTextField();
                JTextField origemCidadeField = new JTextField();
                JTextField origemCodigoIATAField = new JTextField();
                JTextField destinoCidadeField = new JTextField();
                JTextField destinoCodigoIATAField = new JTextField();
                JTextField dataField = new JTextField();
                JTextField vagasField = new JTextField();
                JTextField valorField = new JTextField();
                JTextField codigoVooField = new JTextField();

                JPanel panel = new JPanel(new GridLayout(10, 2));
                panel.add(new JLabel("Horário de Entrada:"));
                panel.add(horarioEntradaField);
                panel.add(new JLabel("Horário de Saída:"));
                panel.add(horarioSaidaField);
                panel.add(new JLabel("Origem - Cidade:"));
                panel.add(origemCidadeField);
                panel.add(new JLabel("Origem - Código IATA:"));
                panel.add(origemCodigoIATAField);
                panel.add(new JLabel("Destino - Cidade:"));
                panel.add(destinoCidadeField);
                panel.add(new JLabel("Destino - Código IATA:"));
                panel.add(destinoCodigoIATAField);
                panel.add(new JLabel("Data:"));
                panel.add(dataField);
                panel.add(new JLabel("Vagas:"));
                panel.add(vagasField);
                panel.add(new JLabel("Valor:"));
                panel.add(valorField);
                panel.add(new JLabel("Código do Voo:"));
                panel.add(codigoVooField);

                int result = JOptionPane.showConfirmDialog(null, panel, "Cadastro de Voo",
                        JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);

                if (result == JOptionPane.OK_OPTION) {
                    // Criação de instâncias de Aeroporto com os dados inseridos pelo usuário
                    Aeroporto origem = new Aeroporto(origemCidadeField.getText(), origemCodigoIATAField.getText());
                    Aeroporto destino = new Aeroporto(destinoCidadeField.getText(), destinoCodigoIATAField.getText());

                    // Conversão da String do valor do voo para double
                    double valorDoVoo = Double.parseDouble(valorField.getText());

                    // Criação de uma instância de TrechoVoo com os dados inseridos pelo usuário
                    TrechoVoo novoTrechoVoo = new TrechoVoo(
                            horarioEntradaField.getText(),
                            horarioSaidaField.getText(),
                            origem,
                            destino,
                            dataField.getText(),
                            vagasField.getText(),
                            valorDoVoo,  // Aqui você passa o valor convertido para double
                            codigoVooField.getText()
                    );

                    // Criação de uma instância de DadosTrechoVoo
                    DadosTrechoVoo dadosTrechoVoo = new DadosTrechoVoo();

                    // Chamada do método cadastrar() para adicionar o novo TrechoVoo
                    dadosTrechoVoo.cadastrar(novoTrechoVoo);

                    // Exemplo de mensagem de confirmação (pode ser substituída por um diálogo, por exemplo)
                    JOptionPane.showMessageDialog(null, "Voo adicionado com sucesso!");
                }
            }
        });

        btnAdicionarHotel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Inputs para o cadastro do hotel
                JTextField cnpjField = new JTextField();
                JTextField nomeOficialField = new JTextField();
                JTextField nomeDivulgacaoField = new JTextField();
                JTextField enderecoCompletoField = new JTextField();
                JTextField anoCriacaoField = new JTextField();
                JTextField checkInField = new JTextField();
                JTextField checkOutField = new JTextField();
                JTextField mensagemDivulgacaoField = new JTextField();
                JTextField cidadeField = new JTextField();
                JTextField estrelasField = new JTextField();
                JTextField quartosField = new JTextField();
                JTextField petsField = new JTextField();

                JPanel panel = new JPanel(new GridLayout(16, 2)); // Acrescentamos mais um campo para a quantidade de quartos e um para indicar o início dos campos de quartos
                panel.add(new JLabel("CNPJ:"));
                panel.add(cnpjField);
                panel.add(new JLabel("Nome Oficial:"));
                panel.add(nomeOficialField);
                panel.add(new JLabel("Nome de Divulgação:"));
                panel.add(nomeDivulgacaoField);
                panel.add(new JLabel("Endereço Completo:"));
                panel.add(enderecoCompletoField);
                panel.add(new JLabel("Ano de Criação:"));
                panel.add(anoCriacaoField);
                panel.add(new JLabel("Check-In:"));
                panel.add(checkInField);
                panel.add(new JLabel("Check-Out:"));
                panel.add(checkOutField);
                panel.add(new JLabel("Mensagem de Divulgação:"));
                panel.add(mensagemDivulgacaoField);
                panel.add(new JLabel("Cidade:"));
                panel.add(cidadeField);
                panel.add(new JLabel("Estrelas:"));
                panel.add(estrelasField);
                panel.add(new JLabel("Total de Quartos:"));
                panel.add(quartosField);
                panel.add(new JLabel("Aceita Pets (true/false):"));
                panel.add(petsField);

                int result = JOptionPane.showConfirmDialog(null, panel, "Cadastro de Hotel",
                        JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);

                if (result == JOptionPane.OK_OPTION) {
                    try {
                        // Conversão de valores de string para os tipos adequados
                        int numeroEstrelas = Integer.parseInt(estrelasField.getText());
                        int totalQuartos = Integer.parseInt(quartosField.getText());
                        boolean aceitaPets = Boolean.parseBoolean(petsField.getText());

                        // Criação de uma instância de Hotel com os dados inseridos pelo usuário
                        Hotel novoHotel = new Hotel(
                                cnpjField.getText(),
                                nomeOficialField.getText(),
                                nomeDivulgacaoField.getText(),
                                enderecoCompletoField.getText(),
                                anoCriacaoField.getText(),
                                checkInField.getText(),
                                checkOutField.getText(),
                                mensagemDivulgacaoField.getText(),
                                cidadeField.getText(),
                                numeroEstrelas,
                                totalQuartos,
                                aceitaPets
                        );

                        // Adicionar quartos ao hotel
                        DadosHotel.adicionarQuartosAoHotel(novoHotel);

                        // Chamada do método cadastrar() para adicionar o novo Hotel
                        DadosHotel.cadastrar(novoHotel);

                        // Exemplo de mensagem de confirmação (pode ser substituída por um diálogo, por exemplo)
                        JOptionPane.showMessageDialog(null, "Hotel adicionado com sucesso!");
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(null, "Erro ao cadastrar hotel. Verifique os dados inseridos.");
                    }
                }
            }
        });

        btnAdicionarFuncionario.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Inputs para o cadastro do funcionário
                JTextField nomeField = new JTextField();
                JTextField cpfField = new JTextField();
                JTextField enderecoCompletoField = new JTextField();
                JTextField numeroCarteiraTrabalhoField = new JTextField();
                JTextField dataNascimentoField = new JTextField();
                JTextField salarioFixoField = new JTextField();

                JPanel panel = new JPanel(new GridLayout(6, 2));
                panel.add(new JLabel("Nome:"));
                panel.add(nomeField);
                panel.add(new JLabel("CPF:"));
                panel.add(cpfField);
                panel.add(new JLabel("Endereço Completo:"));
                panel.add(enderecoCompletoField);
                panel.add(new JLabel("Número da Carteira de Trabalho:"));
                panel.add(numeroCarteiraTrabalhoField);
                panel.add(new JLabel("Data de Nascimento (YYYY-MM-DD):"));
                panel.add(dataNascimentoField);
                panel.add(new JLabel("Salário Fixo:"));
                panel.add(salarioFixoField);

                int result = JOptionPane.showConfirmDialog(null, panel, "Cadastro de Funcionário",
                        JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);

                if (result == JOptionPane.OK_OPTION) {
                    try {
                        // Conversão de valores de string para os tipos adequados
                        Date dataNascimento = java.sql.Date.valueOf(dataNascimentoField.getText());
                        double salarioFixo = Double.parseDouble(salarioFixoField.getText());

                        // Criação de uma instância de Funcionario com os dados inseridos pelo usuário
                        Funcionario novoFuncionario = new Funcionario(
                                nomeField.getText(),
                                cpfField.getText(),
                                enderecoCompletoField.getText(),
                                numeroCarteiraTrabalhoField.getText(),
                                dataNascimento,
                                salarioFixo
                        );

                        // Criação de uma instância de DadosFuncionarios
                        DadosFuncionarios dadosFuncionarios = new DadosFuncionarios();

                        // Chamada do método cadastrar() para adicionar o novo Funcionario
                        dadosFuncionarios.cadastrar(novoFuncionario);

                        // Exemplo de mensagem de confirmação (pode ser substituída por um diálogo, por exemplo)
                        JOptionPane.showMessageDialog(null, "Funcionário adicionado com sucesso!");
                    } catch (Exception ex) {
                        JOptionPane.showMessageDialog(null, "Erro ao cadastrar funcionário. Verifique os dados inseridos.");
                    }
                }
            }
        });

        btnAdicionarCliente.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Inputs para o cadastro do cliente
                JTextField nomeField = new JTextField();
                JTextField cpfField = new JTextField();
                JTextField enderecoCompletoField = new JTextField();
                JTextField dataNascimentoField = new JTextField();
                JTextField emailField = new JTextField();
                JTextField senhaField = new JTextField();

                JPanel panel = new JPanel(new GridLayout(6, 2));
                panel.add(new JLabel("Nome:"));
                panel.add(nomeField);
                panel.add(new JLabel("CPF:"));
                panel.add(cpfField);
                panel.add(new JLabel("Endereço Completo:"));
                panel.add(enderecoCompletoField);
                panel.add(new JLabel("Data de Nascimento (YYYY-MM-DD):"));
                panel.add(dataNascimentoField);
                panel.add(new JLabel("Email:"));
                panel.add(emailField);
                panel.add(new JLabel("Senha:"));
                panel.add(senhaField);

                int result = JOptionPane.showConfirmDialog(null, panel, "Cadastro de Cliente",
                        JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);

                if (result == JOptionPane.OK_OPTION) {
                    try {
                        // Conversão de valores de string para os tipos adequados
                        Date dataNascimento = java.sql.Date.valueOf(dataNascimentoField.getText());

                        // Criação de uma instância de Cliente com os dados inseridos pelo usuário
                        Cliente novoCliente = new Cliente(
                                nomeField.getText(),
                                cpfField.getText(),
                                enderecoCompletoField.getText(),
                                dataNascimento,
                                emailField.getText(),
                                senhaField.getText(),
                                new Date() // Data de cadastro definida como a data atual
                        );

                        // Criação de uma instância de DadosCliente
                        DadosCliente dadosCliente = new DadosCliente();

                        // Chamada do método cadastrarCliente() para adicionar o novo Cliente
                        dadosCliente.cadastrarCliente(novoCliente);

                        // Exemplo de mensagem de confirmação (pode ser substituída por um diálogo, por exemplo)
                        JOptionPane.showMessageDialog(null, "Cliente adicionado com sucesso!");
                    } catch (Exception ex) {
                        JOptionPane.showMessageDialog(null, "Erro ao cadastrar cliente. Verifique os dados inseridos.");
                    }
                }
            }
        });

        panel.add(btnAdicionarVoo);
        panel.add(btnAdicionarHotel);
        panel.add(btnAdicionarFuncionario);
        panel.add(btnAdicionarCliente);

        getContentPane().add(panel);
        pack();
    }
}