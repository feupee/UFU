#include <stdio.h>
#include "ListaEncad.c"

int main() {
    Lista* listaAlunos = criar();

    // Inserindo alunos com notas
    Aluno aluno1 = {1, "Felipe", 9.5};
    Aluno aluno2 = {2, "Jose", 8.0};
    Aluno aluno3 = {3, "Caio", 7.5};
    Aluno aluno4 = {4, "Henrique", 8.5};

    inserirInicio(listaAlunos, aluno1);
    inserirFim(listaAlunos, aluno2);
    inserirFim(listaAlunos, aluno3);
    inserirFim(listaAlunos, aluno4);

    // Chamando a função para encontrar o aluno com a maior nota
    alunoComMaiorNota(listaAlunos);

    return 0;
}