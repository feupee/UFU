public class Main {

    public static void main(String[] args) {
/* A)
        Universidade universidade = new Universidade("Universidade XYZ");

        EstudanteGraduacao grad1 = new EstudanteGraduacao("João", "Rua 123", "TCC de Matemática");
        EstudanteMestrado mestrado1 = new EstudanteMestrado("Maria", "Avenida 456", "Engenharia", "Computação", "Acadêmico", "Dissertação sobre IA");
        EstudanteDoutorado doutorado1 = new EstudanteDoutorado("Carlos", "Rua 789", "Biologia", "Ecologia", "Título da Tese sobre Biodiversidade");

        universidade.adicionarEstudante(grad1);
        universidade.adicionarEstudante(mestrado1);
        universidade.adicionarEstudante(doutorado1);

        universidade.contarEstudantesPorTipo();
*/
/* B)
        Universidade universidade = new Universidade("Universidade XYZ");

        EstudanteGraduacao grad1 = new EstudanteGraduacao("João", "Rua 123", "TCC de Matemática");
        EstudanteMestrado mestrado1 = new EstudanteMestrado("Maria", "Avenida 456", "Engenharia", "Computação", "Acadêmico", "Dissertação sobre IA");
        EstudanteDoutorado doutorado1 = new EstudanteDoutorado("Carlos", "Rua 789", "Biologia", "Ecologia", "Título da Tese sobre Biodiversidade");


        universidade.adicionarEstudante(grad1);
        universidade.adicionarEstudante(mestrado1);
        universidade.adicionarEstudante(doutorado1);

        universidade.mostrarInformacoesAlunos();

 */
/* C)
        Universidade universidade = new Universidade("Universidade XYZ");

        EstudanteGraduacao grad1 = new EstudanteGraduacao("João", "Rua 123", "TCC de Matemática");
        EstudanteMestrado mestrado1 = new EstudanteMestrado("Maria", "Avenida 456", "Engenharia", "Computação", "Acadêmico", "Dissertação sobre IA");
        EstudanteDoutorado doutorado1 = new EstudanteDoutorado("Carlos", "Rua 789", "Biologia", "Ecologia", "Título da Tese sobre Biodiversidade");

        universidade.adicionarEstudante(grad1);
        universidade.adicionarEstudante(mestrado1);
        universidade.adicionarEstudante(doutorado1);

        universidade.copiarAlunosPosGrad();
*/
/* D)

        EstudanteGraduacao grad1 = new EstudanteGraduacao("João", "Rua 123", "TCC de Matemática");
        EstudanteMestrado mestrado1 = new EstudanteMestrado("Maria", "Avenida 456", "Engenharia", "Computação", "Acadêmico", "Dissertação sobre IA");
        EstudanteDoutorado doutorado1 = new EstudanteDoutorado("Carlos", "Rua 789", "Biologia", "Ecologia", "Título da Tese sobre Biodiversidade");

        grad1.print(true);
        mestrado1.print(true);
        doutorado1.print(true);

        System.out.println("\nImpressão com múltiplas linhas:");
        grad1.print(false);
        mestrado1.print(false);
        doutorado1.print(false);

 */
/* E)

        EstudanteGraduacao grad1 = new EstudanteGraduacao("João", "Rua 123", "TCC de Matemática");
        EstudanteMestrado mestrado1 = new EstudanteMestrado("Maria", "Avenida 456", "Engenharia", "Computação", "Acadêmico", "Dissertação sobre IA");
        EstudanteDoutorado doutorado1 = new EstudanteDoutorado("Carlos", "Rua 789", "Biologia", "Ecologia", "Título da Tese sobre Biodiversidade");

        Estudante[] alunos = {grad1, mestrado1, doutorado1};

        for (Estudante aluno : alunos) {
            aluno.print(true);  // Todos os prints serão feitos na mesma linha
            System.out.println(); // Para separar os prints dos alunos
            aluno.print(false); // Todos os prints serão feitos em múltiplas linhas
            System.out.println(); // Para separar os prints dos alunos

 */
        }
}