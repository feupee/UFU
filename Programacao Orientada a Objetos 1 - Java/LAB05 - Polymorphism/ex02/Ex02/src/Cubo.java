class Cubo extends FormaTridimensional {
    private double lado;

    public Cubo(double lado) {
        this.lado = lado;
    }

    @Override
    public double obterArea() {
        return 6 * lado * lado;
    }

    @Override
    public double obterVolume() {
        return lado * lado * lado;
    }

    @Override
    public String descricao() {
        return "Cubo de lado " + lado;
    }
}