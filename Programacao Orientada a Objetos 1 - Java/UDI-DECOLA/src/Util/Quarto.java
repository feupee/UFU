package Util;

public class Quarto {
    private String tipo; // Tipo de quarto (single, duplo, triplo)
    private boolean deLuxo; // Informa se o quarto é de luxo
    private double diariaSemDesconto; // Valor da diária sem desconto
    private double desconto; // Valor do desconto
    private double valor_do_quarto; //Valor sem desconto
    private double valorAposDesconto; // Valor da diária após aplicar o desconto
    private boolean aceitaCancelamento; // Se aceita ou não cancelamento


    public double getValor_do_quarto() {
        return valor_do_quarto;
    }

    public void setValor_do_quarto(double valor_do_quarto) {
        this.valor_do_quarto = valor_do_quarto;
    }

    //Construtor
    public Quarto(String tipo, boolean deLuxo, double diariaSemDesconto, double desconto, double valor,double valorAposDesconto, boolean aceitaCancelamento) {
        this.tipo = tipo;
        this.deLuxo = deLuxo;
        this.diariaSemDesconto = diariaSemDesconto;
        this.desconto = desconto;
        this.valor_do_quarto = valor;
        this.valorAposDesconto = valorAposDesconto;
        this.aceitaCancelamento = aceitaCancelamento;
    }

    //Getters And Setters

    public boolean isDeLuxo() {
        return deLuxo;
    }

    public void setDeLuxo(boolean deLuxo) {
        this.deLuxo = deLuxo;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public double getDiariaSemDesconto() {
        return diariaSemDesconto;
    }

    public void setDiariaSemDesconto(double diariaSemDesconto) {
        this.diariaSemDesconto = diariaSemDesconto;
    }

    public double getDesconto() {
        return desconto;
    }

    public void setDesconto(double desconto) {
        this.desconto = desconto;
    }

    public double getValorAposDesconto() {
        return valorAposDesconto;
    }

    public void setValorAposDesconto(double valorAposDesconto) {
        this.valorAposDesconto = valorAposDesconto;
    }

    public boolean isAceitaCancelamento() {
        return aceitaCancelamento;
    }

    public void setAceitaCancelamento(boolean aceitaCancelamento) {
        this.aceitaCancelamento = aceitaCancelamento;
    }

}