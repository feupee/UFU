package Arquivos;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Escrita_Registro {
    public static void salvarCliente(String nome, String cpf, String endereco, String email, String senha, Date dataNascimento) {
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
        String dataNascimentoString = dateFormat.format(dataNascimento);

        try {
            FileWriter fileWriter = new FileWriter("Arquivos/clientes.txt", true); // O segundo argumento "true" indica que você deseja acrescentar ao arquivo, não substituir
            PrintWriter printWriter = new PrintWriter(fileWriter);

            // Escrever os dados no arquivo
            printWriter.println("Nome: " + nome);
            printWriter.println("CPF: " + cpf);
            printWriter.println("Endereço: " + endereco);
            printWriter.println("E-mail: " + email);
            printWriter.println("Senha: " + senha);
            printWriter.println("Data de Nascimento: " + dataNascimentoString);
            printWriter.println(); // Adiciona uma linha em branco para separar os registros

            printWriter.close();
            fileWriter.close();

            System.out.println("Dados salvos em clientes.txt.");
        } catch (IOException e) {
            System.out.println("Erro ao salvar os dados: " + e.getMessage());
        }
    }
}