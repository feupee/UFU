package Classes;

public class Main {
    /*public static void main(String[] args) throws ExceptionsAndInterfaces.ValorInvalidoException {

        //As agências bancárias devem ser previamente cadastradas, sendo que cada agência possui um
        //número, um nome fictício e um endereço, sendo que os campos cidade, estado e bairro são
        //campos frequentemente usados para se realizar buscas por agências.

        // Datas necessárias
        Calendar dataNascGerente = Calendar.getInstance();
        dataNascGerente.set(1980, Calendar.MARCH, 15);

        Calendar dataIngressoGerencia = Calendar.getInstance();
        dataIngressoGerencia.set(2020, Calendar.JANUARY, 1);

        // Funcionários da agência (vazio por enquanto)
        Classes.Funcionario[] funcionarios = new Classes.Funcionario[0];

        Classes.Agencia agencia = new Classes.Agencia(
                "001",
                "Agência Central",
                "Av. Brasil, 500",
                "São Paulo",
                "SP",
                "Centro",
                null,
                funcionarios
        );

        // Instancia o gerente
        Classes.Gerente gerente = new Classes.Gerente(
                "999.999.999-99",
                "Ana Paula",
                "Rua do Classes.Gerente, 123",
                "Casada",
                "Superior Completo",
                dataNascGerente.getTime(),
                "123456",
                "MG-12.345.678",
                "Classes.Gerente Geral",
                "12000.00",
                "2010",
                "Feminino",
                dataIngressoGerencia.getTime(),
                agencia, // agencia_gerenciada (antes de vincular à agência)
                true
        );

        agencia.setGerente(gerente);

        // Criando a agência e associando ao gerente

        // Datas de nascimento dos clientes
        Calendar cal1 = Calendar.getInstance();
        cal1.set(1990, Calendar.JANUARY, 10);

        Calendar cal2 = Calendar.getInstance();
        cal2.set(1985, Calendar.JUNE, 25);

        Calendar cal3 = Calendar.getInstance();
        cal3.set(2000, Calendar.DECEMBER, 5);

        // Criando os clientes vinculados à agência
        Classes.Cliente cliente1 = new Classes.Cliente("111.111.111-11", "João Silva", "Rua A, 123", "Solteiro", "Ensino Médio", cal1.getTime(), agencia);
        Classes.Cliente cliente2 = new Classes.Cliente("222.222.222-22", "Maria Souza", "Av. B, 456", "Casada", "Superior", cal2.getTime(), agencia);
        Classes.Cliente cliente3 = new Classes.Cliente("333.333.333-33", "Carlos Lima", "Trav. C, 789", "Divorciado", "Pós-graduação", cal3.getTime(), agencia);

        System.out.println("3 clientes criados e associados à agência com sucesso!");

        Date dataHoje = new Date();

        Classes.ContaCorrente contaCorrente = new Classes.ContaCorrente(
                "CC123", 1000.00, dataHoje,
                500.00, 15.00, "CC123", "1234", true,
                agencia, cliente1
        );

        // Conta Poupança para cliente2
        Classes.ContaPoupanca contaPoupanca = new Classes.ContaPoupanca(
                "CP456", 2000.00, dataHoje,
                0.5, "5678", true,
                agencia, cliente2
        );

        // Conta Salário para cliente3
        Classes.ContaSalario contaSalario = new Classes.ContaSalario(
                "CS789", 1500.00, dataHoje,
                1000.00, 500.00, "91011", true,
                agencia, cliente3
        );

        try {
            contaPoupanca.depositar( 500, "internet Banking");
            contaCorrente.sacar(200, "Caixa Eletrônico");
            contaSalario.consultarSaldo("Caixa Eletrônico");
            contaCorrente.efetuarPagamento(150, contaCorrente, "internet Banking");

            // Exibir histórico de transações
            contaSalario.exibirTransacoes();

        } catch (ExceptionsAndInterfaces.ValorInvalidoException e) {
            System.out.println("Erro: " + e.getMessage());


        }
    }*/
}