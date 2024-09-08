#include "ListaDupla.c"

int main(){
    Lista *l = criar();
    if (l == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    // Adicione alguns alunos à lista
    cadastrarAluno(l); // Você pode chamar essa função várias vezes para adicionar vários alunos.
    cadastrarAluno(l);
    cadastrarAluno(l);

    // Mostre a lista atual
    mostrar(l);

    // Troque a posição de dois alunos (por exemplo, troque a posição 1 e 2)
    int resultado = trocarPosicoes(l, 1, 2);

    if (resultado == 0) {
        printf("Troca de posições realizada com sucesso.");
    } else if (resultado == -1) {
        printf("Erro: lista inválida.");
    } else if (resultado == -2) {
        printf("Erro: posições inválidas.");
    } else {
        printf("Erro desconhecido.\n");
    }

    // Mostre a lista atualizada após a troca
    mostrar(l);

    // Lembre-se de liberar a memória da lista quando não for mais necessária.
    limpar(l);

    return 0;
}