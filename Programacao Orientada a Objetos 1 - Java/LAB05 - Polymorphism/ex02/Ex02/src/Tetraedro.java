class Tetraedro extends FormaTridimensional {
    private double lado;

    public Tetraedro(double lado) {
        this.lado = lado;
    }

    @Override
    public double obterArea() {
        return lado * lado * Math.sqrt(3);
    }

    @Override
    public double obterVolume() {
        return (Math.pow(lado, 3) / (6 * Math.sqrt(2)));
    }

    @Override
    public String descricao() {
        return "Tetraedro de lado " + lado;
    }
}