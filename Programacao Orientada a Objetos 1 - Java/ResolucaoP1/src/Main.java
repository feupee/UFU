import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Musico musico1 = new Musico("João", "Guitarrista", 5, 120.50f);
        Musico musico2 = new Musico("Maria", "Vocalista", 8, 150.75f);
        Musico substituto = new Musico("Carlos", "Baterista", 3, 100.00f);

        Musico[] titulares = {musico1, musico2};

        Dueto duetoComSubstituto = new Dueto("Dupla Musical", substituto, titulares);
        System.out.println("### Dueto com Substituto ###");
        duetoComSubstituto.mostrar_informacoes();

        Dueto duetoSemSubstituto = new Dueto("Dupla Acústica", titulares);
        System.out.println("\n### Dueto sem Substituto ###");
        duetoSemSubstituto.mostrar_informacoes();


        /*Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o número de duetos: ");
        int n = scanner.nextInt();
        scanner.nextLine();

        Dueto[] duetos = new Dueto[n];

        for (int i = 0; i < n; i++) {
            System.out.println("\nDigite as informações do " + (i + 1) + "º dueto:");

            System.out.print("Nome do dueto: ");
            String nomeDueto = scanner.nextLine();

            System.out.println("Informe os músicos titulares:");

            System.out.print("Nome do Músico 1: ");
            String nomeMusico1 = scanner.nextLine();
            System.out.print("Papel do Músico 1: ");
            String papelMusico1 = scanner.nextLine();
            System.out.print("Experiência do Músico 1 (anos): ");
            int experienciaMusico1 = scanner.nextInt();
            System.out.print("Remuneração por hora do Músico 1: ");
            float remuneracaoMusico1 = scanner.nextFloat();
            scanner.nextLine(); // Consumindo a linha em branco

            System.out.print("Nome do Músico 2: ");
            String nomeMusico2 = scanner.nextLine();
            System.out.print("Papel do Músico 2: ");
            String papelMusico2 = scanner.nextLine();
            System.out.print("Experiência do Músico 2 (anos): ");
            int experienciaMusico2 = scanner.nextInt();
            System.out.print("Remuneração por hora do Músico 2: ");
            float remuneracaoMusico2 = scanner.nextFloat();
            scanner.nextLine(); // Consumindo a linha em branco

            Musico musico1 = new Musico(nomeMusico1, papelMusico1, experienciaMusico1, remuneracaoMusico1);
            Musico musico2 = new Musico(nomeMusico2, papelMusico2, experienciaMusico2, remuneracaoMusico2);

            System.out.print("Deseja adicionar um substituto? (s/n): ");
            String resposta = scanner.nextLine();
            Musico substituto = null;

            if (resposta.equalsIgnoreCase("s")) {
                System.out.print("Nome do substituto: ");
                String nomeSubstituto = scanner.nextLine();
                System.out.print("Papel do substituto: ");
                String papelSubstituto = scanner.nextLine();
                System.out.print("Experiência do substituto (anos): ");
                int experienciaSubstituto = scanner.nextInt();
                System.out.print("Remuneração por hora do substituto: ");
                float remuneracaoSubstituto = scanner.nextFloat();
                scanner.nextLine(); // Consumindo a linha em branco

                substituto = new Musico(nomeSubstituto, papelSubstituto, experienciaSubstituto, remuneracaoSubstituto);
            }

            Musico[] musicosTitulares = {musico1, musico2};

            Dueto dueto = (substituto != null) ? new Dueto(nomeDueto, substituto, musicosTitulares) : new Dueto(nomeDueto, musicosTitulares);
            duetos[i] = dueto;
        }

        System.out.println("\n### Informações dos Duetos ###");
        for (int i = 0; i < n; i++) {
            System.out.println("\nDueto " + (i + 1) + ":");
            duetos[i].mostrar_informacoes();
        }

        Dueto duetoComMaiorMedia = duetos[0];
        for (int i = 1; i < n; i++) {
            if (duetos[i].MediaRemuneracao() > duetoComMaiorMedia.MediaRemuneracao()) {
                duetoComMaiorMedia = duetos[i];
            }
        }

        System.out.println("\n### Dueto com a Maior Média de Remuneração ###");
        duetoComMaiorMedia.mostrar_informacoes();

        scanner.close();

        for (int i = 0; i < n; i++) {
            duetos[i] = null;
        }*/

    }
}