import java.util.Scanner;

class Aluno {
    private int matricula;
    private char classeSocial;
    private double cra;

    public Aluno(int matricula, char classeSocial, double cra) {
        this.matricula = matricula;
        this.classeSocial = classeSocial;
        this.cra = cra;
    }

    public void exibirDados() {
        System.out.printf("Matrícula: %d | Classe Social: %c | CRA: %.2f\n", matricula, classeSocial, cra);
    }
}