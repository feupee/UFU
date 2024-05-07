package Util;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;
import java.util.List;

public class Hotel {
    private Map<Date, Map<String, List<Quarto>>> quartosDisponiveis; // Mapa de datas para tipos de quarto disponíveis
    static final double valorFixoPorDiariaVendida = 10.0; // Valor fixo por cada diária vendida
    private static final double quantidadeDeComprasParaSeTornarVip = 10.0;
    private String cnpj;
    private String nome_oficial;
    private String nome_de_divulgacao;
    private String endereco_completo;
    private String ano_de_criacao;
    private String check_in;
    private String check_out;
    private String mensagem_de_divulgacao;
    private String cidade;
    private int numero_de_estrelas;
    private int total_de_quartos;
    private Boolean aceita_pets;

    //Construtor
    public Hotel(String cnpj, String nome_oficial, String nome_de_divulgacao, String endereco_completo, String ano_de_criacao, String check_in, String check_out, String mensagem_de_divulgacao, String cidade, int numero_de_estrelas, int total_de_quartos, Boolean aceita_pets) {
        this.cnpj = cnpj;
        this.nome_oficial = nome_oficial;
        this.nome_de_divulgacao = nome_de_divulgacao;
        this.endereco_completo = endereco_completo;
        this.ano_de_criacao = ano_de_criacao;
        this.check_in = check_in;
        this.check_out = check_out;
        this.mensagem_de_divulgacao = mensagem_de_divulgacao;
        this.cidade = cidade;
        this.numero_de_estrelas = numero_de_estrelas;
        this.total_de_quartos = total_de_quartos;
        this.aceita_pets = aceita_pets;
        this.quartosDisponiveis = new HashMap<>();
    }
    public void mostrarDadosHotel() {
        System.out.println("CNPJ: " + cnpj);
        System.out.println("Nome Oficial: " + nome_oficial);
        System.out.println("Nome de Divulgação: " + nome_de_divulgacao);
        System.out.println("Endereço Completo: " + endereco_completo);
        System.out.println("Ano de Criação: " + ano_de_criacao);
        System.out.println("Horário de Check-in: " + check_in);
        System.out.println("Horário de Check-out: " + check_out);
        System.out.println("Mensagem de Divulgação: " + mensagem_de_divulgacao);
        System.out.println("Cidade: " + cidade);
        System.out.println("Número de Estrelas: " + numero_de_estrelas);
        System.out.println("Total de Quartos: " + total_de_quartos);
        System.out.println("Aceita Pets: " + (aceita_pets ? "Sim" : "Não"));
        System.out.println("----------------------------------------");
    }

    // Adicionar quartos disponíveis para uma data específica
    public void adicionarQuartosDisponiveis(Date data, String tipoQuarto, List<Quarto> quartos) {
        Map<String, List<Quarto>> quartosPorTipo = quartosDisponiveis.getOrDefault(data, new HashMap<>());
        quartosPorTipo.put(tipoQuarto, quartos);
        quartosDisponiveis.put(data, quartosPorTipo);
    }

    // Obter quartos disponíveis para uma data e tipo de quarto específicos
    public List<Quarto> obterQuartosDisponiveis(Date data, String tipoQuarto) {
        Map<String, List<Quarto>> quartosPorTipo = quartosDisponiveis.get(data);
        if (quartosPorTipo != null) {
            return quartosPorTipo.getOrDefault(tipoQuarto, new ArrayList<>());
        } else {
            return new ArrayList<>(); // Retorna uma lista vazia se não houver quartos disponíveis para essa data
        }
    }

    // Método para obter os tipos de quarto disponíveis no hotel
    public List<String> getTiposQuarto() {
        List<String> tiposQuarto = new ArrayList<>();
        for (Map.Entry<Date, Map<String, List<Quarto>>> entry : quartosDisponiveis.entrySet()) {
            for (String tipoQuarto : entry.getValue().keySet()) {
                if (!tiposQuarto.contains(tipoQuarto)) {
                    tiposQuarto.add(tipoQuarto);
                }
            }
        }
        return tiposQuarto;
    }

    // Contar número de quartos de luxo disponíveis para uma data específica
    public int contarQuartosLuxoDisponiveis(Date data) {
        int count = 0; //Contador de quartos de luxo
        Map<String, List<Quarto>> quartosPorTipo = quartosDisponiveis.get(data); // Obtém os quartos disponíveis para a data especificada
        if (quartosPorTipo != null) { // Verifica se existem quartos disponíveis para a data
            // Procura em cima dos quartos disponíveis
            for (List<Quarto> quartos : quartosPorTipo.values()) {
                // Procura em cima dos quartos de cada tipo
                for (Quarto quarto : quartos) {
                    if (quarto.isDeLuxo()) { // Verifica se o quarto é de luxo
                        count++; // Incrementa o contador se o quarto for de luxo
                    }
                }
            }
        }
        return count; // Retorna o número total de quartos de luxo disponíveis para a data especificada
    }

    public String getCnpj() {
        return cnpj;
    }

    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }

    public String getNome_oficial() {
        return nome_oficial;
    }

    public void setNome_oficial(String nome_oficial) {
        this.nome_oficial = nome_oficial;
    }

    public String getNome_de_divulgacao() {
        return nome_de_divulgacao;
    }

    public void setNome_de_divulgacao(String nome_de_divulgacao) {
        this.nome_de_divulgacao = nome_de_divulgacao;
    }

    public String getEndereco_completo() {
        return endereco_completo;
    }

    public Map<Date, Map<String, List<Quarto>>> getQuartosDisponiveis() {
        return quartosDisponiveis;
    }

    public void setQuartosDisponiveis(Map<Date, Map<String, List<Quarto>>> quartosDisponiveis) {
        this.quartosDisponiveis = quartosDisponiveis;
    }

    public void setEndereco_completo(String endereco_completo) {
        this.endereco_completo = endereco_completo;
    }

    public String getAno_de_criacao() {
        return ano_de_criacao;
    }

    public void setAno_de_criacao(String ano_de_criacao) {
        this.ano_de_criacao = ano_de_criacao;
    }

    public String getCheck_in() {
        return check_in;
    }

    public void setCheck_in(String check_in) {
        this.check_in = check_in;
    }

    public String getCheck_out() {
        return check_out;
    }

    public void setCheck_out(String check_out) {
        this.check_out = check_out;
    }

    public String getMensagem_de_divulgacao() {
        return mensagem_de_divulgacao;
    }

    public void setMensagem_de_divulgacao(String mensagem_de_divulgacao) {
        this.mensagem_de_divulgacao = mensagem_de_divulgacao;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public int getNumero_de_estrelas() {
        return numero_de_estrelas;
    }

    public void setNumero_de_estrelas(int numero_de_estrelas) {
        this.numero_de_estrelas = numero_de_estrelas;
    }

    public int getTotal_de_quartos() {
        return total_de_quartos;
    }

    public void setTotal_de_quartos(int total_de_quartos) {
        this.total_de_quartos = total_de_quartos;
    }

    public Boolean getAceita_pets() {
        return aceita_pets;
    }

    public void setAceita_pets(Boolean aceita_pets) {
        this.aceita_pets = aceita_pets;
    }

    public void adicionarQuarto(Quarto quarto) {

    }
}

//Diagrama
/*
+------------------+
|      Util.Hotel       |
+------------------+
| - quartosDisponiveis: HashMap<Date, HashMap<String, List<Util.Quarto>>>
+------------------+

+------------------------+
|    HashMap<Date, ...>   |
+------------------------+
|   |                    |
|   +---[15/01/2024]-----> HashMap<String, List<Util.Quarto>>
|   |                    |
|   +---[16/01/2024]-----> HashMap<String, List<Util.Quarto>>
|   |                    |
|   +---[17/01/2024]-----> HashMap<String, List<Util.Quarto>>
|   |                    |
|   ...                  |
+------------------------+

+-------------------------------+
| HashMap<String, List<Util.Quarto>> |
+-------------------------------+
|   |                           |
|   +---["Single"]-----------> Lista de quartos Single
|   |                           |
|   +---["Duplo"]------------> Lista de quartos Duplos
|   |                           |
|   +---["Triplo"]-----------> Lista de quartos Triplos
|   |                           |
+-------------------------------+

*/
//--Exemplo--
/*Util.Hotel hotel = new Util.Hotel();

        // Inicializando quartos disponíveis para o mês de janeiro
        Calendar calendario = Calendar.getInstance();
        calendario.set(Calendar.MONTH, Calendar.JANUARY);
        calendario.set(Calendar.YEAR, 2024);

        for (int dia = 1; dia <= 31; dia++) {
            calendario.set(Calendar.DAY_OF_MONTH, dia);
            Date data = calendario.getTime();

            List<Util.Quarto> quartosSingle = new ArrayList<>();
            quartosSingle.add(new Util.Quarto("Single", 100.0, 10.0, true));
            quartosSingle.add(new Util.Quarto("Single", 100.0, 10.0, true));

            List<Util.Quarto> quartosDuplo = new ArrayList<>();
            quartosDuplo.add(new Util.Quarto("Duplo", 150.0, 15.0, false));
            quartosDuplo.add(new Util.Quarto("Duplo", 150.0, 15.0, false));

            List<Util.Quarto> quartosTriplo = new ArrayList<>();
            quartosTriplo.add(new Util.Quarto("Triplo", 200.0, 20.0, true));
            quartosTriplo.add(new Util.Quarto("Triplo", 200.0, 20.0, true));

            hotel.adicionarQuartosDisponiveis(data, "Single", quartosSingle);
            hotel.adicionarQuartosDisponiveis(data, "Duplo", quartosDuplo);
            hotel.adicionarQuartosDisponiveis(data, "Triplo", quartosTriplo);
        }

        // Acessando quartos disponíveis para uma data específica
        Date dataConsulta = new Date(); // Supondo que estamos consultando para a data atual
        List<Util.Quarto> quartosDisponiveisSingle = hotel.obterQuartosDisponiveis(dataConsulta, "Single");
        List<Util.Quarto> quartosDisponiveisDuplo = hotel.obterQuartosDisponiveis(dataConsulta, "Duplo");
        List<Util.Quarto> quartosDisponiveisTriplo = hotel.obterQuartosDisponiveis(dataConsulta, "Triplo");

        // Exibindo informações dos quartos disponíveis
        System.out.println("Quartos disponíveis para " + dataConsulta + ":");
        exibirQuartos(quartosDisponiveisSingle);
        exibirQuartos(quartosDisponiveisDuplo);
        exibirQuartos(quartosDisponiveisTriplo);
    }

    // Método para exibir informações dos quartos
    public static void exibirQuartos(List<Util.Quarto> quartos) {
        for (Util.Quarto quarto : quartos) {
            System.out.println("Tipo: " + quarto.getTipo() + ", Diária: " + quarto.getDiariaSemDesconto() +
                    ", Desconto: " + quarto.getDesconto() + ", Aceita Cancelamento: " + quarto.aceitaCancelamento());
        }
    }
}*/


//Exemplo de Data usando "date"

/*Criando um objeto Date com a data e hora atuais
                Date dataAtual = new Date();
                System.out.println("Data e hora atuais: " + dataAtual);

// Criando um objeto Date com uma data específica (21 de fevereiro de 2022)
                Date dataEspecifica = new Date(122, 1, 21); // Ano começa em 1900, mês é base 0
                System.out.println("Data específica: " + dataEspecifica);*/
