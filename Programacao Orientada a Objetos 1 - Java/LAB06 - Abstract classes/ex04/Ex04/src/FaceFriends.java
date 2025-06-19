import java.util.Scanner;

public class FaceFriends {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Contato[] contatos = new Contato[100]; // Vetor fixo com capacidade para 100 contatos
        int totalContatos = 0;

        while (true) {
            System.out.println("\nMENU:");
            System.out.println("1. Inserir contato");
            System.out.println("2. Imprimir todos os contatos");
            System.out.println("3. Imprimir familiares");
            System.out.println("4. Imprimir amigos");
            System.out.println("5. Imprimir colegas de trabalho");
            System.out.println("6. Imprimir contatos especiais");
            System.out.println("7. Imprimir um contato por índice");
            System.out.println("0. Sair");
            System.out.print("Escolha: ");
            int escolha = scanner.nextInt();
            scanner.nextLine(); // Limpar o buffer

            if (escolha == 0) break;

            switch (escolha) {
                case 1:
                    if (totalContatos >= contatos.length) {
                        System.out.println("Limite de contatos atingido!");
                        break;
                    }
                    System.out.print("Subtipo (1-Familia, 2-Amigos, 3-Trabalho): ");
                    int tipo = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Apelido: ");
                    String apelido = scanner.nextLine();
                    System.out.print("Nome: ");
                    String nome = scanner.nextLine();
                    System.out.print("Email: ");
                    String email = scanner.nextLine();
                    System.out.print("Aniversário: ");
                    String aniversario = scanner.nextLine();

                    if (tipo == 1) {
                        System.out.print("Parentesco: ");
                        String parentesco = scanner.nextLine();
                        contatos[totalContatos++] = new Familia(apelido, nome, email, aniversario, parentesco);
                    } else if (tipo == 2) {
                        System.out.print("Grau de amizade (1- Melhor amigo, 2- Amigo, 3- Conhecido): ");
                        int grau = scanner.nextInt();
                        scanner.nextLine();
                        contatos[totalContatos++] = new Amigos(apelido, nome, email, aniversario, grau);
                    } else if (tipo == 3) {
                        System.out.print("Tipo de relação (ex: chefe, colega): ");
                        String relacao = scanner.nextLine();
                        contatos[totalContatos++] = new Trabalho(apelido, nome, email, aniversario, relacao);
                    }
                    break;

                case 2:
                    for (int i = 0; i < totalContatos; i++) {
                        contatos[i].imprimirContato();
                    }
                    break;

                case 3:
                    for (int i = 0; i < totalContatos; i++) {
                        if (contatos[i] instanceof Familia) {
                            contatos[i].imprimirContato();
                        }
                    }
                    break;

                case 4:
                    for (int i = 0; i < totalContatos; i++) {
                        if (contatos[i] instanceof Amigos) {
                            contatos[i].imprimirContato();
                        }
                    }
                    break;

                case 5:
                    for (int i = 0; i < totalContatos; i++) {
                        if (contatos[i] instanceof Trabalho) {
                            contatos[i].imprimirContato();
                        }
                    }
                    break;

                case 6:
                    for (int i = 0; i < totalContatos; i++) {
                        if ((contatos[i] instanceof Amigos && ((Amigos) contatos[i]).getGrau() == 1) ||
                                (contatos[i] instanceof Familia && ((Familia) contatos[i]).getParentesco().equalsIgnoreCase("irmão")) ||
                                (contatos[i] instanceof Trabalho && ((Trabalho) contatos[i]).getTipo().equalsIgnoreCase("colega"))) {
                            contatos[i].imprimirContato();
                        }
                    }
                    break;

                case 7:
                    System.out.print("Informe o índice: ");
                    int indice = scanner.nextInt();
                    if (indice >= 0 && indice < totalContatos) {
                        Contato contato = contatos[indice];
                        if (contato instanceof Familia) System.out.println("Tipo: Familia");
                        else if (contato instanceof Amigos) System.out.println("Tipo: Amigos");
                        else if (contato instanceof Trabalho) System.out.println("Tipo: Trabalho");
                        contato.imprimirContato();
                    } else {
                        System.out.println("Índice inválido!");
                    }
                    break;

                default:
                    System.out.println("Opção inválida!");
            }
        }
        scanner.close();
    }
}