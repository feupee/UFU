class Triangulo extends FormaBidimensional {
    private double base, altura;

    public Triangulo(double base, double altura) {
        this.base = base;
        this.altura = altura;
    }

    @Override
    public double obterArea() {
        return (base * altura) / 2;
    }

    @Override
    public String descricao() {
        return "Triângulo de base " + base + " e altura " + altura;
    }
}