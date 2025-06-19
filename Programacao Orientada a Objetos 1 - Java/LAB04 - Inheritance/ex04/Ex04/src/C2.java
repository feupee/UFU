public class C2 extends C1{
    int D;
    private int E;
    protected int F;

    public C2(int a, int b, int c, int d, int e, int f){
        System.out.println("Classe C2: chamada do construtor C2 com parametros");
        this.A = a;
        this.B = b;
        this.C = c;
        this.D = d;
        this.E = e;
        this.F = f;
    }
    public C2(){
        System.out.println("Classe C2: chamada do construtor sem parametros");
    }

    public void mostrar_informacoes(){
        System.out.println("A: " + this.A);
        System.out.println("B: " + this.B);
        System.out.println("C: " + this.C);
        System.out.println("D: " + this.D);
        System.out.println("E: " + this.E);
        System.out.println("F: " + this.F);
    }

    public void mostrar_atributos_super() {
        super.mostrar_informacoes();
        System.out.println("D: " + this.D);
        System.out.println("E: " + this.E);
        System.out.println("F: " + this.F);
    }
}
