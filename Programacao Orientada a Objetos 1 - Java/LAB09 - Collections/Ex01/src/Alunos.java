import java.util.ArrayList;
import java.util.Collections;

public class Alunos{
    public static void criarAlunos() {
        ArrayList<Estudante> alunos = new ArrayList<>();
        Estudante e1 = new Estudante ("José", "Rua do joca");
        Estudante e2 = new EstudanteGraduacao("João", "RUssia", "baboi");
        Estudante e3 = new EstudantePosGrad("Carla", "Tim Maia", "macarrao", "tigela");
        Estudante e4 = new EstudanteMestrado("Cleber", "B", "T", "Y", "U", "TR");
        Estudante e5 = new EstudanteDoutorado("Maria", "C", "C", "C", "C");
        alunos.add(e1);
        alunos.add(e2);
        alunos.add(e3);
        alunos.add(e4);
        alunos.add(e5);
        for(Estudante e : alunos){
          e.print();
        }
        /*for (int i = 0; i < alunos.size(); i++){
            alunos.get(i).print();
        }*/
        //alunos.remove(1);

        Estudante e6 = new Estudante("Ana", "Rua Nova");
        alunos.add(e6);

        System.out.println("Total de alunos: " + alunos.size());

        Collections.sort(alunos);
        System.out.println("\nLista Ordenada por Nome");
        for (Estudante e : alunos) {
            e.print();
            System.out.println();
        }
    }

    public static void main (String args []){
        criarAlunos();
    }
}
