public class C3 extends C2{
    int G;
    private int H;
    protected int I;

    public C3(int a, int b, int c, int d, int e, int f, int g, int h, int i){
        super();
        System.out.println("Classe C3: chamada do construtor C3 com parâmetros");
        this.G = G;
        this.H = H;
        this.I = I;
    }
    public C3(){
        System.out.println("Classe C3: chamada do construtor sem parametros");
    }

    public void mostrar_informacoes(){
        System.out.println("A: " + this.A);
        System.out.println("B: " + this.B);
        System.out.println("C: " + this.C);
        System.out.println("D: " + this.D);
        System.out.println("E: " + this.E);
        System.out.println("F: " + this.F);
        System.out.println("G: " + this.G);
        System.out.println("H: " + this.H);
        System.out.println("I: " + this.I);
    }

    public void mostrar_atributos_super(){
        super.mostrar_informacoes();
        System.out.println("G: " + this.G);
        System.out.println("H: " + this.H);
        System.out.println("I: " + this.I);
    }
}
