public class Musico {
    private String nome;
    private String papel;
    private int experiencia;
    float remuneracao_hora;

    public Musico(String nome, String papel, int experiencia, float remuneracao_hora) {
        this.nome = nome;
        this.papel = papel;
        this.experiencia = experiencia;
        this.remuneracao_hora = remuneracao_hora;
    }

    public void mostrar_informacoes(){
        System.out.println("Nome: " + nome);
        System.out.println("Papel: " + papel);
        System.out.println("Experiencia: " + experiencia);
        System.out.println("Remuneracao hora: " + remuneracao_hora);
    }
}
