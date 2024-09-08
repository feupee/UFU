#include "ListaDupla.c"

int main() {
    Lista* listaAlunos = criar(); // Crie uma lista de alunos

    // Inserir alunos na lista (exemplo)

    cadastrarAluno(listaAlunos);
    cadastrarAluno(listaAlunos);
    cadastrarAluno(listaAlunos);
    cadastrarAluno(listaAlunos);

    printf("Lista de Alunos (antes de remover repeticoes):\n");
    mostrar(listaAlunos);

    removerRepeticoes(listaAlunos);

    printf("\nLista de Alunos (depois de remover repeticoes):\n");
    mostrar(listaAlunos);

    // Lembre-se de liberar a memória da lista e dos alunos quando terminar
    limpar(listaAlunos);

    return 0;
}