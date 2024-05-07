    package Util;

    import Util.Cliente;
    import Util.Companhia_Aerea;
    import Util.TrechoVoo;

    import java.util.Date;

    // Classe Compra
    public class Compras {
        private int quantidadePassagens;
        private int quantidadeDiariasHotel;
        private double valorTotal;
        private String formaPagamento;
        private Date dataHoraCompra;
        private double valorTotal_UdiDecola;
        private Cliente cliente;
        private String tipoCompra;

        // Construtor para compra de passagens
        public Compras(int quantidadePassagens, String formaPagamento, Date dataHoraCompra, Cliente cliente, TrechoVoo trechoVoo) {
            this.quantidadePassagens = quantidadePassagens;
            if(cliente.isClienteVIP()){
                this.valorTotal = (trechoVoo.getValorDoVoo() * quantidadePassagens) * cliente.getDescontoVIP();
            } else {
                this.valorTotal = trechoVoo.getValorDoVoo() * quantidadePassagens;
            }
            this.formaPagamento = formaPagamento;
            this.valorTotal_UdiDecola = Companhia_Aerea.valorFixoPorPassagemVendida * quantidadePassagens;
            this.dataHoraCompra = dataHoraCompra;
            this.cliente = cliente;
            this.tipoCompra = "Passagem";
        }

        // Construtor para compra de quarto em hotel
        public Compras(String formaPagamento, int quantidadeDiariasHotel, Date dataHoraCompra, Cliente cliente, Quarto quarto) {
            this.quantidadeDiariasHotel = quantidadeDiariasHotel;
            if(cliente.isClienteVIP()){
                this.valorTotal = (quarto.getValor_do_quarto() * quantidadeDiariasHotel) * cliente.getDescontoVIP();
            }else {
                this.valorTotal = quarto.getValor_do_quarto() * quantidadeDiariasHotel;
            }

            this.valorTotal_UdiDecola = Hotel.valorFixoPorDiariaVendida * quantidadeDiariasHotel;
            this.formaPagamento = formaPagamento;
            this.dataHoraCompra = dataHoraCompra;
            this.cliente = cliente;
            this.tipoCompra = "Hotel";
        }

        public String getTipoCompra() {
            return tipoCompra;
        }

        public void setTipoCompra(String tipoCompra) {
            this.tipoCompra = tipoCompra;
        }

        // Métodos getters e setters
        public int getQuantidadePassagens() {
            return quantidadePassagens;
        }

        public void setQuantidadePassagens(int quantidadePassagens) {
            this.quantidadePassagens = quantidadePassagens;
        }

        public int getQuantidadeDiariasHotel() {
            return quantidadeDiariasHotel;
        }

        public void setQuantidadeDiariasHotel(int quantidadeDiariasHotel) {
            this.quantidadeDiariasHotel = quantidadeDiariasHotel;
        }

        public double getValorTotal_UdiDecola() {
            return valorTotal_UdiDecola;
        }

        public void setValorTotal_UdiDecola(double valorTotal_UdiDecola) {
            this.valorTotal_UdiDecola = valorTotal_UdiDecola;
        }

        public double getValorTotal() {
            return valorTotal;
        }

        public void setValorTotal(double valorTotal) {
            this.valorTotal = valorTotal;
        }

        public String getFormaPagamento() {
            return formaPagamento;
        }

        public void setFormaPagamento(String formaPagamento) {
            this.formaPagamento = formaPagamento;
        }

        public Date getDataHoraCompra() {
            return dataHoraCompra;
        }

        public void setDataHoraCompra(Date dataHoraCompra) {
            this.dataHoraCompra = dataHoraCompra;
        }

        public Cliente getCliente() {
            return cliente;
        }

        public void setCliente(Cliente cliente) {
            this.cliente = cliente;
        }

    }