package PostgreSQL;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.util.Date;

public class Insere_Registro {
    public static void inserirCliente_Banco(String nome, String cpf, String endereco, String email, String senha, Date datanascimento) {
        Connection connection = null;
        PreparedStatement preparedStatement = null;

        try {
            // Carregar o driver JDBC
            Class.forName("org.postgresql.Driver");

            // Estabelecer conexão com o banco de dados
            String url = "jdbc:postgresql://localhost:5432/postgres";
            String usuario = "postgres";
            String senhaBanco = "159753";
            connection = DriverManager.getConnection(url, usuario, senhaBanco);

            // Query SQL para inserção de dados
            String query = "INSERT INTO cliente (nome, cpf, endereco, email, senha, datanascimento) VALUES (?, ?, ?, ?, ?, ?)";

            // Preparar a declaração SQL
            preparedStatement = connection.prepareStatement(query);

            // Substituir os parâmetros na consulta SQL pelos valores passados como argumentos
            preparedStatement.setString(1, nome);
            preparedStatement.setString(2, cpf);
            preparedStatement.setString(3, endereco);
            preparedStatement.setString(4, email);
            preparedStatement.setString(5, senha);
            preparedStatement.setDate(6, new java.sql.Date(datanascimento.getTime()));

            // Executar a declaração SQL para inserir os dados
            int linhasAfetadas = preparedStatement.executeUpdate();

            // Verificar se a inserção foi bem-sucedida
            if (linhasAfetadas > 0) {
                System.out.println("Dados inseridos com sucesso!");
            } else {
                System.out.println("Nenhum dado foi inserido.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            // Fechar recursos
            try {
                if (preparedStatement != null) preparedStatement.close();
                if (connection != null) connection.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}