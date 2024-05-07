#include "ListaDupla.c"

int main() {
    Lista* lista1 = criar();
    Lista* lista2 = criar();

    cadastrarAluno(lista1);
    cadastrarAluno(lista2);
    cadastrarAluno(lista1);
    cadastrarAluno(lista2);

    int resultado = compararListas(lista1, lista2);

    if (resultado == 0) {
        printf("As listas sao iguais.\n");
    } else if (resultado == 1) {
        printf("As listas sao diferentes.\n");
    } else if (resultado == -1) {
        printf("Erro: uma ou ambas as listas sao invalidas.\n");
    }

    // Lembre-se de liberar a memória das listas e dos alunos, se necessário.

    return 0;
}