package Dados;

import Util.Funcionario;

import java.util.ArrayList;
import java.util.List;

public class DadosFuncionarios {
    private List<Funcionario> funcionarios = new ArrayList<>();

    public void cadastrar(Funcionario funcionario) {
        this.funcionarios.add(funcionario);
    }

    public void listar() {
        for (Funcionario funcionario : this.funcionarios) {
            funcionario.mostrarDadosFuncionario();
        }
    }

    public Funcionario buscar(String cpf) {
        for (Funcionario funcionario : this.funcionarios) {
            if (funcionario.getCpf().equals(cpf)) {
                return funcionario;
            }
        }
        return null; // Retorna null se o funcionário não for encontrado
    }

    public boolean excluir(String cpf) {
        Funcionario funcionario = this.buscar(cpf);
        if (funcionario != null) {
            this.funcionarios.remove(funcionario);
            return true;
        } else {
            return false;
        }
    }
}