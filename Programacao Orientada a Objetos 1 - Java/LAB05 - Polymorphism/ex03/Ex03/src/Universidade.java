public class Universidade {
    private String nome;
    private Estudante[] estudantes;
    private int quantidadeEstudantes;

    public Universidade(String nome) {
        this.nome = nome;
        this.estudantes = new Estudante[100];  // Capacidade máxima de 100 estudantes
        this.quantidadeEstudantes = 0;
    }

    public String getNome() {
        return nome;
    }

    public void adicionarEstudante(Estudante estudante) {
        if (quantidadeEstudantes < 100) {
            estudantes[quantidadeEstudantes] = estudante;
            quantidadeEstudantes++;
        } else {
            System.out.println("Número máximo de estudantes atingido.");
        }
    }

    public void contarEstudantesPorTipo() {
        int countGraduacao = 0;
        int countMestrado = 0;
        int countDoutorado = 0;

        for (int i = 0; i < quantidadeEstudantes; i++) {
            if (estudantes[i] instanceof EstudanteGraduacao) {
                countGraduacao++;
            } else if (estudantes[i] instanceof EstudanteMestrado) {
                countMestrado++;
            } else if (estudantes[i] instanceof EstudanteDoutorado) {
                countDoutorado++;
            }
        }

        System.out.println("Estudantes de Graduação: " + countGraduacao);
        System.out.println("Estudantes de Mestrado: " + countMestrado);
        System.out.println("Estudantes de Doutorado: " + countDoutorado);
    }

    public void mostrarInformacoesAlunos() {
        for (int i = 0; i < quantidadeEstudantes; i++) {
            Estudante aluno = estudantes[i];
            System.out.println("Nome: " + aluno.getNome());

            if (aluno instanceof EstudanteDoutorado) {
                EstudanteDoutorado doutorado = (EstudanteDoutorado) aluno;
                System.out.println("  Título da Tese: " + doutorado.getTituloTese());
                System.out.println("  Linha de Pesquisa: " + doutorado.getLinhaDePesquisa());
            }
        }
    }
    public void copiarAlunosPosGrad() {
        Estudante[] posGradAlunos = new Estudante[100];
        int countPosGrad = 0;

        for (int i = 0; i < quantidadeEstudantes; i++) {
            if (estudantes[i] instanceof EstudantePosGrad) {
                posGradAlunos[countPosGrad] = estudantes[i];
                countPosGrad++;
            }
        }

        System.out.println("Informações dos alunos de Pós-Graduação:");
        for (int i = 0; i < countPosGrad; i++) {
            Estudante aluno = posGradAlunos[i];
            aluno.print();
        }
    }

}