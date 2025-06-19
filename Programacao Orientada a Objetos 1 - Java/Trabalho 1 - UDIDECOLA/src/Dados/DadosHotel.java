package Dados;

import Util.Hotel;
import Util.Quarto;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class DadosHotel {
    private static Map<String, Hotel> hoteis;

    public static void adicionarQuartosAoHotel(Hotel hotel) {
        int totalQuartos = hotel.getTotal_de_quartos();
        if (totalQuartos > 0) {
            JFrame frame = new JFrame("Adicionar Quartos ao Hotel");
            frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            JPanel panel = new JPanel(new GridLayout(totalQuartos + 1, 2));
            panel.add(new JLabel("Cadastro de Quartos para o Hotel: " + hotel.getNome_oficial()));
            // Adicione os campos necessários para cada quarto
            for (int i = 1; i <= totalQuartos; i++) {
                panel.add(new JLabel("Tipo do Quarto " + i + ":"));
                panel.add(new JTextField());
                // Adicione outros campos necessários (ex: preço, disponibilidade, etc.)
            }
            JButton btnConfirmar = new JButton("Confirmar");
            btnConfirmar.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    // Obtenha os dados dos quartos e associe-os ao hotel
                    // Feche a janela após confirmar
                    JOptionPane.showMessageDialog(null, "Quartos adicionados com sucesso!");
                    frame.dispose();
                }
            });
            panel.add(btnConfirmar);
            frame.getContentPane().add(panel);
            frame.pack();
            frame.setVisible(true);
        } else {
            JOptionPane.showMessageDialog(null, "O hotel não possui quartos para adicionar.");
        }
    }

    public DadosHotel() {
        hoteis = new HashMap<>();
    }

    public static List<Hotel> getHoteis() {
        return new ArrayList<>(hoteis.values());
    }

    public static void listar() {
        System.out.println("Lista de Hotéis:");
        for (Hotel hotel : hoteis.values()) {
            System.out.println("CNPJ: " + hotel.getCnpj());
            System.out.println("Nome: " + hotel.getNome_oficial());
            System.out.println("Cidade: " + hotel.getCidade());
            System.out.println("Número de Estrelas: " + hotel.getNumero_de_estrelas());
            System.out.println("Total de Quartos: " + hotel.getTotal_de_quartos());
            System.out.println("Aceita Pets: " + hotel.getAceita_pets());
            System.out.println("Quartos Disponíveis:");
            for (Map.Entry<Date, Map<String, List<Quarto>>> entry : hotel.getQuartosDisponiveis().entrySet()) {
                System.out.println("Data: " + entry.getKey());
                for (Map.Entry<String, List<Quarto>> innerEntry : entry.getValue().entrySet()) {
                    String tipoQuarto = innerEntry.getKey();
                    List<Quarto> quartos = innerEntry.getValue();
                    System.out.println("  Tipo: " + tipoQuarto);
                    System.out.println("  Número de Quartos: " + quartos.size());
                    for (Quarto quarto : quartos) {
                        System.out.println("    Tipo: " + quarto.getTipo());
                        System.out.println("    De Luxo: " + quarto.isDeLuxo());
                        System.out.println("    Diária Sem Desconto: " + quarto.getDiariaSemDesconto());
                        System.out.println("    Desconto: " + quarto.getDesconto());
                        System.out.println("    Valor do Quarto: " + quarto.getValor_do_quarto());
                        System.out.println("    Valor Após Desconto: " + quarto.getValorAposDesconto());
                        System.out.println("    Aceita Cancelamento: " + quarto.isAceitaCancelamento());
                    }
                }
            }
            System.out.println("--------------------------------------");
        }
    }

    public static void cadastrar(Hotel hotel) {
        hoteis.put(hotel.getCnpj(), hotel);
    }


    public Hotel buscarHotelPorCnpj(String cnpj) {
        return hoteis.get(cnpj);
    }

    // Métodos para manipulação de quartos
    public void adicionarQuartosDisponiveis(String cnpjHotel, Date data, String tipoQuarto, List<Quarto> quartos) {
        Hotel hotel = hoteis.get(cnpjHotel);
        if (hotel != null) {
            hotel.adicionarQuartosDisponiveis(data, tipoQuarto, quartos);
        } else {
            System.err.println("Hotel não encontrado para o CNPJ: " + cnpjHotel);
        }
    }

    public List<Quarto> obterQuartosDisponiveis(String cnpjHotel, Date data, String tipoQuarto) {
        Hotel hotel = hoteis.get(cnpjHotel);
        if (hotel != null) {
            return hotel.obterQuartosDisponiveis(data, tipoQuarto);
        } else {
            System.err.println("Hotel não encontrado para o CNPJ: " + cnpjHotel);
            return new ArrayList<>();
        }
    }

    public static List<String> obterTiposQuartoDisponiveis(String cidade) {
        List<String> tiposQuartoDisponiveis = new ArrayList<>();
        for (Hotel hotel : hoteis.values()) {
            if (hotel.getCidade().equals(cidade)) {
                for (Map.Entry<Date, Map<String, List<Quarto>>> entry : hotel.getQuartosDisponiveis().entrySet()) {
                    for (String tipoQuarto : entry.getValue().keySet()) {
                        if (!tiposQuartoDisponiveis.contains(tipoQuarto)) {
                            tiposQuartoDisponiveis.add(tipoQuarto);
                        }
                    }
                }
            }
        }
        return tiposQuartoDisponiveis;
    }
    public static Hotel buscarHotelPorCidade(String cidade) {
        for (Hotel hotel : hoteis.values()) {
            if (hotel.getCidade().equals(cidade)) {
                return hotel;
            }
        }
        return null; // Retorna null se nenhum hotel for encontrado para a cidade especificada
    }

    public String buscarCnpjDoHotel(Hotel hotel) {
        for (Map.Entry<String, Hotel> entry : hoteis.entrySet()) {
            if (entry.getValue().equals(hotel)) {
                return entry.getKey(); // Retorna o CNPJ correspondente ao hotel
            }
        }
        return null; // Retorna null se o hotel não for encontrado
    }

    public static Quarto obterQuartoPorTipo(String cnpjHotel, String tipoQuarto) {
        Hotel hotel = hoteis.get(cnpjHotel);
        if (hotel != null) {
            for (Map.Entry<Date, Map<String, List<Quarto>>> entry : hotel.getQuartosDisponiveis().entrySet()) {
                Map<String, List<Quarto>> quartosPorTipo = entry.getValue();
                if (quartosPorTipo.containsKey(tipoQuarto)) {
                    List<Quarto> quartos = quartosPorTipo.get(tipoQuarto);
                    if (!quartos.isEmpty()) {
                        return quartos.getFirst(); // Retorna o primeiro quarto encontrado do tipo especificado
                    }
                }
            }
        }
        return null; // Retorna null se nenhum quarto for encontrado para o tipo especificado
    }
}