package Dados;

import Arquivos.LeitorVoos;
import Util.Cliente;
import Util.Hotel;
import Util.Quarto;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

public class InicializarDados {

    public static void inicializarDados() {
        inicializarHoteis();
        inicializarVoos();
        inicializarClientes();
        listarHoteis();
    }

    private static void inicializarHoteis() {
        // Criando instâncias de Calendar e SimpleDateFormat para trabalhar com datas
        Calendar calendar = Calendar.getInstance();


        // Hotel 1
        Hotel hotel1 = new Hotel("123456789", "Hotel A", "Hotel A", "Rua Exemplo, 123", "2000", "14:00", "12:00",
                "Um hotel aconchegante", "Cidade A", 4, 100, true);

        // Adicionando quartos disponíveis para o hotel 1
        adicionarQuartosDisponiveis(hotel1, calendar);

        // Hotel 2
        Hotel hotel2 = new Hotel("987654321", "Hotel B", "Hotel B", "Avenida Teste, 456", "1995", "15:00", "11:00",
                "Venha conhecer nosso hotel de luxo", "Cidade B", 5, 200, false);

        // Adicionando quartos disponíveis para o hotel 2
        adicionarQuartosDisponiveis(hotel2, calendar);

        // Hotel 3
        Hotel hotel3 = new Hotel("456123789", "Hotel C", "Hotel C", "Praça Modelo, 789", "2010", "12:00", "10:00",
                "O melhor lugar para relaxar", "Cidade C", 3, 80, true);

        // Adicionando quartos disponíveis para o hotel 3
        adicionarQuartosDisponiveis(hotel3, calendar);

        // Criando uma instância de DadosHotel
        DadosHotel dadosHotel = new DadosHotel();

        // Cadastrar hotéis no objeto DadosHotel
        DadosHotel.cadastrar(hotel1);
        DadosHotel.cadastrar(hotel2);
        DadosHotel.cadastrar(hotel3);
    }


    // Método para adicionar quartos disponíveis para um hotel
    private static void adicionarQuartosDisponiveis(Hotel hotel, Calendar calendar) {
        // Definindo datas para adicionar quartos disponíveis (vamos adicionar para os próximos 10 dias)
        for (int i = 0; i < 10; i++) {
            calendar.add(Calendar.DAY_OF_MONTH, 1); // Adiciona um dia
            Date data = calendar.getTime(); // Obtém a data

            // Criando quartos disponíveis para diferentes tipos
            List<Quarto> quartosSingle = criarQuartos("Single", false, 100.0, 10.0, 120.0, 110.0, true);
            List<Quarto> quartosDuplo = criarQuartos("Duplo", false, 150.0, 15.0, 180.0, 165.0, false);
            List<Quarto> quartosLuxo = criarQuartos("Luxo", true, 200.0, 20.0, 250.0, 240.0, true);

            // Adicionando quartos disponíveis para o hotel
            hotel.adicionarQuartosDisponiveis(data, "Single", quartosSingle);
            hotel.adicionarQuartosDisponiveis(data, "Duplo", quartosDuplo);
            hotel.adicionarQuartosDisponiveis(data, "Luxo", quartosLuxo);
        }
    }

    // Método para criar uma lista de quartos de um mesmo tipo
    private static List<Quarto> criarQuartos(String tipo, boolean deLuxo, double diariaSemDesconto, double desconto, double valor,double valorAposDesconto, boolean aceitaCancelamento) {
        List<Quarto> quartos = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            Quarto quarto = new Quarto(tipo, deLuxo, diariaSemDesconto, desconto, valor, valorAposDesconto, aceitaCancelamento);
            quartos.add(quarto);
        }
        return quartos;
    }

    private static void inicializarVoos() {
        DadosTrechoVoo dadosTrechoVoo = new DadosTrechoVoo();
        LeitorVoos.lerArquivo(dadosTrechoVoo);
    }

    private static void inicializarClientes() {
        DadosCliente dadosCliente = new DadosCliente();
        Cliente clienteDefault = new Cliente();
        dadosCliente.cadastrarCliente(clienteDefault);
    }

    private static void listarHoteis() {
        DadosHotel.listar();
    }


}