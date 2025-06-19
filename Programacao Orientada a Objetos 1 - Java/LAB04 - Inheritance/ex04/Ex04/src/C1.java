public class C1 {
    int A;
    private int B;
    protected int C;

    public C1(int a, int b, int c){
        System.out.println("Classe C1: chamada do construtor com parametros");
        this.A = a;
        this.B = b;
        this.C = c;
    }
    public C1(){
        System.out.println("Classe C1: chamada do construtor sem parametros");
    }

    public void mostrar_informacoes(){
        System.out.println("A: " + this.A);
        System.out.println("B: " + this.B);
        System.out.println("C: " + this.C);

    }

}
