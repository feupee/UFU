import java.util.Scanner;

public class principal {

    public static void ex01(){
        Scanner sc = new Scanner(System.in);
        int val1,val2,val3,val4,val5,val6;

        System.out.println("<< Listando um vetor >>");
        System.out.println("Entre com o número 1:");
        val1 = sc.nextInt();

        System.out.println("Entre com o número 2:");
        val2 = sc.nextInt();

        System.out.println("Entre com o número 3:");
        val3 = sc.nextInt();

        System.out.println("Entre com o número 4:");
        val4 = sc.nextInt();

        System.out.println("Entre com o número 5:");
        val5 = sc.nextInt();

        System.out.println("Entre com o número 6:");
        val6 = sc.nextInt();

        System.out.println("Os valores lidos são:");
        System.out.printf("%d %d %d %d %d %d ", val1, val2, val3, val4, val5, val6);
    }

    public static void ex02(){
        Scanner sc = new Scanner(System.in);
        int[] vet = new int[6];
        System.out.println("<< Listando um vetor >>");

        for (int i = 0; i < 6; i++){
            System.out.printf("Entre com o número %d:\n",i+1);
            vet[i] = sc.nextInt();
        }

        System.out.println("Os valores lidos são:");
        for (int i = 0; i < 6; i++){
            System.out.printf("%d ",vet[i]);
        }
    }

    public static void ex03() {
        Scanner sc = new Scanner(System.in);

        // Declarando o vetor para armazenar os 6 números
        int[] numeros = new int[6];

        // Exercício 1: Lendo os números sem loop
        System.out.println("Exercício 1: Digite 6 números (sem loop):");
        System.out.print("Digite o 1º número: ");
        numeros[0] = sc.nextInt();
        System.out.print("Digite o 2º número: ");
        numeros[1] = sc.nextInt();
        System.out.print("Digite o 3º número: ");
        numeros[2] = sc.nextInt();
        System.out.print("Digite o 4º número: ");
        numeros[3] = sc.nextInt();
        System.out.print("Digite o 5º número: ");
        numeros[4] = sc.nextInt();
        System.out.print("Digite o 6º número: ");
        numeros[5] = sc.nextInt();

        // Mostrando os números lidos
        System.out.println("\nNúmeros digitados (Exercício 1):");
        for (int i = 0; i < 6; i++) {
            System.out.print(numeros[i] + " ");
        }
        System.out.println("\n");

        // Exercício 2: Lendo os números com loop for
        System.out.println("Exercício 2: Digite novamente 6 números (com loop):");
        for (int i = 0; i < 6; i++) {
            System.out.print("Digite o " + (i + 1) + "º número: ");
            numeros[i] = sc.nextInt();
        }

        // Mostrando os números lidos
        System.out.println("\nNúmeros digitados (Exercício 2):");
        for (int i = 0; i < 6; i++) {
            System.out.print(numeros[i] + " ");
        }
        System.out.println("\n");

        // Exercício 3: Mostrando os números na ordem inversa
        System.out.println("Exercício 3: Números em ordem inversa:");
        for (int i = 5; i >= 0; i--) {
            System.out.print(numeros[i] + " ");
        }

        sc.close();
        // Exercício 4: Aceitar apenas números pares
        int[] pares = new int[6];
        int i = 0;
        System.out.println("Exercício 4: Digite 6 números pares:");
        while (i < 6) {
            System.out.print("Digite o " + (i + 1) + "º número: ");
            int num = sc.nextInt();
            if (num % 2 == 0) {
                pares[i] = num;
                i++;
            } else {
                System.out.println("Apenas números pares são permitidos!");
            }
        }
        System.out.println("Números pares digitados:");
        for (int num : pares) {
            System.out.print(num + " ");
        }
        System.out.println("\n");

        // Exercício 5: Maior, menor e média
        int[] valores = new int[5];
        int maior = Integer.MIN_VALUE, menor = Integer.MAX_VALUE, soma = 0;
        System.out.println("Exercício 5: Digite 5 valores:");
        for (i = 0; i < 5; i++) {
            valores[i] = sc.nextInt();
            soma += valores[i];
            if (valores[i] > maior) maior = valores[i];
            if (valores[i] < menor) menor = valores[i];
        }
        double media = soma / 5.0;
        System.out.println("Valores digitados:");
        for (int valor : valores) {
            System.out.print(valor + " ");
        }
        System.out.println("\nMaior: " + maior + ", Menor: " + menor + ", Média: " + media);
        System.out.println();

        // Exercício 6: Índices do maior e menor
        int indiceMaior = 0, indiceMenor = 0;
        for (i = 0; i < 5; i++) {
            if (valores[i] == maior) indiceMaior = i;
            if (valores[i] == menor) indiceMenor = i;
        }
        System.out.println("Índice do maior: " + indiceMaior + ", Índice do menor: " + indiceMenor);
        System.out.println();

        // Exercício 7: Normalizar notas
        double[] notas = new double[5];
        double maxNota = 0;
        System.out.println("Exercício 7: Digite as notas de 5 alunos:");
        for (i = 0; i < 5; i++) {
            notas[i] = sc.nextDouble();
            if (notas[i] > maxNota) maxNota = notas[i];
        }
        System.out.println("Notas normalizadas:");
        for (i = 0; i < 5; i++) {
            notas[i] = (notas[i] / maxNota) * 100;
            System.out.printf("%.2f ", notas[i]);
        }
        System.out.println("\n");

        // Exercício 8: Média e desvio padrão amostral
        soma = 0;
        double somaQuadrados = 0;
        System.out.println("Exercício 8: Digite 5 números:");
        for (i = 0; i < 5; i++) {
            valores[i] = sc.nextInt();
            soma += valores[i];
        }
        media = soma / 5.0;
        for (i = 0; i < 5; i++) {
            somaQuadrados += Math.pow(valores[i] - media, 2);
        }
        double desvioPadrao = Math.sqrt(somaQuadrados / 4); // Desvio amostral
        System.out.printf("Média: %.2f, Desvio Padrão: %.2f\n\n", media, desvioPadrao);

        // Exercício 9: Média das notas de até 100 alunos
        System.out.print("Exercício 9: Quantos alunos (máx 100)? ");
        int qtdAlunos = sc.nextInt();
        if (qtdAlunos > 100) {
            System.out.println("Erro: Máximo de 100 alunos.");
            return;
        }
        double[] notasAlunos = new double[qtdAlunos];
        soma = 0;
        for (i = 0; i < qtdAlunos; i++) {
            System.out.print("Nota do aluno " + (i + 1) + ": ");
            notasAlunos[i] = sc.nextDouble();
            soma += notasAlunos[i];
        }
        media = soma / (double) qtdAlunos;
        System.out.printf("Média da turma: %.2f\n\n", media);

        // Exercício 10: C = A - B
        int[] A = new int[3], B = new int[3], C = new int[3];
        System.out.println("Exercício 10: Digite 3 valores para A e B:");
        for (i = 0; i < 3; i++) A[i] = sc.nextInt();
        for (i = 0; i < 3; i++) B[i] = sc.nextInt();
        for (i = 0; i < 3; i++) C[i] = A[i] - B[i];
        System.out.println("Vetor C = A - B:");
        for (int num : C) System.out.print(num + " ");
        System.out.println("\n");

        // Exercício 11: Separar pares e ímpares
        int[] v = new int[5], v1 = new int[5], v2 = new int[5];
        int p = 0, imp = 0;
        System.out.println("Exercício 11: Digite 5 números:");
        for (i = 0; i < 5; i++) {
            v[i] = sc.nextInt();
            if (v[i] % 2 == 0) v2[p++] = v[i];
            else v1[imp++] = v[i];
        }
        System.out.println("Ímpares em v1:");
        for (i = 0; i < imp; i++) System.out.print(v1[i] + " ");
        System.out.println("\nPares em v2:");
        for (i = 0; i < p; i++) System.out.print(v2[i] + " ");
        System.out.println("\n");

        // Exercício 12: Probabilidade de bolinhas
        String[] cores = {"Azul", "Verde", "Amarela", "Vermelha"};
        int[] qtd = new int[4];
        int total = 0, maiorProb = 0;
        for (i = 0; i < 4; i++) {
            System.out.print("Quantidade de bolinhas " + cores[i] + ": ");
            qtd[i] = sc.nextInt();
            total += qtd[i];
            if (qtd[i] > qtd[maiorProb]) maiorProb = i;
        }
        for (i = 0; i < 4; i++) {
            System.out.printf("%s: %.2f%%\n", cores[i], (qtd[i] * 100.0) / total);
        }
        System.out.println("Maior probabilidade: " + cores[maiorProb]);

        // Exercício 13: Substituir negativos por zero
        System.out.println("\nExercício 13: Digite 5 valores:");
        for (i = 0; i < 5; i++) {
            valores[i] = sc.nextInt();
            if (valores[i] < 0) valores[i] = 0;
        }
        System.out.println("Vetor final:");
        for (int valor : valores) System.out.print(valor + " ");
        sc.close();
        System.out.print("Quantos alunos deseja cadastrar (máx 10000)? ");
        int numAlunos = sc.nextInt();
        if (numAlunos > 10000 || numAlunos <= 0) {
            System.out.println("Erro: Número inválido de alunos.");
            return;
        }

        Aluno[] alunos = new Aluno[numAlunos];

        for (int j = 0; j < numAlunos; j++) {
            System.out.println("\nCadastro do aluno " + (i + 1) + ":");
            System.out.print("Número de matrícula: ");
            int matricula = sc.nextInt();

            char classeSocial;
            while (true) {
                System.out.print("Classe social (A, B, C, D ou E): ");
                classeSocial = sc.next().toUpperCase().charAt(0);
                if ("ABCDE".indexOf(classeSocial) != -1) break;
                System.out.println("Classe inválida. Digite novamente.");
            }

            System.out.print("CRA: ");
            double cra = sc.nextDouble();

            alunos[i] = new Aluno(matricula, classeSocial, cra);
        }

        System.out.println("\nLista de alunos cadastrados:");
        for (Aluno aluno : alunos) {
            aluno.exibirDados();
        }

        sc.close();
    }

    public static void main(String[] args) {
        //ex01();
        //ex02();
        //ex03();
    }


}
