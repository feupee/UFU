package PostgreSQL;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Date;

public class Busca_Registro {

    public static String buscarSenhaCliente_Banco(String cpf) {
        Connection connection = null;
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;

        try {
            // Carregar o driver JDBC
            Class.forName("org.postgresql.Driver");

            // Estabelecer conexão com o banco de dados
            String url = "jdbc:postgresql://localhost:5432/postgres";
            String usuario = "postgres";
            String senhaBanco = "159753";
            connection = DriverManager.getConnection(url, usuario, senhaBanco);

            // Consulta SQL para buscar a senha do cliente com base no CPF
            String consulta = "SELECT senha FROM cliente WHERE cpf = ?";

            // Preparar a declaração SQL
            preparedStatement = connection.prepareStatement(consulta);
            preparedStatement.setString(1, cpf);

            // Executar a consulta SQL
            resultSet = preparedStatement.executeQuery();

            // Verificar se o resultado contém uma senha
            if (resultSet.next()) {
                // Retorna a senha do cliente
                return resultSet.getString("senha");
            } else {
                // Cliente não encontrado ou senha não cadastrada para o CPF fornecido
                return null;
            }

        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
            return null; // Retorna null em caso de erro
        } finally {
            // Fechar os recursos
            try {
                if (resultSet != null) resultSet.close();
                if (preparedStatement != null) preparedStatement.close();
                if (connection != null) connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
    public static ResultSet buscarClientes(String nome, String cpf, String endereco, String email, String senha, Date datanascimento) {
        Connection connection = null;
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;

        try {
            // Carregar o driver JDBC
            Class.forName("org.postgresql.Driver");

            // Estabelecer conexão com o banco de dados
            String url = "jdbc:postgresql://localhost:5432/postgres";
            String usuario = "postgres";
            String senhaBanco = "159753";
            connection = DriverManager.getConnection(url, usuario, senhaBanco);

            // Consulta SQL para buscar os dados na tabela cliente
            String consulta = "SELECT * FROM cliente WHERE nome = ? AND cpf = ? AND endereco = ? AND email = ? AND senha = ? AND datanascimento = ?";

            // Preparar a declaração SQL
            preparedStatement = connection.prepareStatement(consulta);
            preparedStatement.setString(1, nome);
            preparedStatement.setString(2, cpf);
            preparedStatement.setString(3, endereco);
            preparedStatement.setString(4, email);
            preparedStatement.setString(5, senha);
            preparedStatement.setDate(6, new java.sql.Date(datanascimento.getTime()));

            // Executar a consulta SQL
            resultSet = preparedStatement.executeQuery();

            // Retorna o ResultSet com os resultados
            return resultSet;

        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
            return null; // Retorna null em caso de erro
        } finally {
            // Não feche os recursos aqui, deixe a classe que chamar o método responsável por isso
        }
    }
}