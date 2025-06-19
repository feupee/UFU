package Classes;

import ExceptionsAndInterfaces.Imprimivel;
import ExceptionsAndInterfaces.ValorInvalidoException;

import java.io.Serializable;
import java.util.Date;

public class Cliente extends Pessoa implements Imprimivel{
    private static Agencia agencia; // Associação com a agência
    // CPF,
    // nome,
    // endereço completo,
    // estado civil,
    // escolaridade,
    // data de nascimento.

    public Cliente(String CPF, String nome, String endereco_completo, String estado_civil, String escolaridade, Date data_nascimento, Agencia agencia) throws ValorInvalidoException {
        super(CPF, nome, endereco_completo, estado_civil, escolaridade, data_nascimento);
        this.agencia = agencia;
    }

    public Cliente(String CPF, String nome) throws ValorInvalidoException {
        super(CPF, nome);
    }

    public Cliente(){
        super();

    }

    @Override
    public void imprimirDados() {
        System.out.println("Classes.Cliente:");
        System.out.println("Nome: " + getNome());
        System.out.println("CPF: " + getCPF());
        System.out.println("Endereço: " + getEndereco_completo());
    }

    public static Agencia getAgencia() {
        return agencia;
    }

    public void setAgencia(Agencia agencia) {
        this.agencia = agencia;
    }
}
