#include "ListaDupla.c"

int main() {
    Lista *l = criar();

    int escolha, mat;
    do {
        printf("1 - Cadastrar Aluno\n2 - Remover Aluno\n3 - Listar alunos cadastrados\n4 - Mostrar dados do aluno com maior nota\n5 - Remover todos os alunos\n7 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarAluno(l);
                break;
            case 2:
                printf("Digite a matricula do aluno para remover: ");
                scanf("%d", &mat);
                RemoverAluno(l, mat);
                break;
            case 3:
                mostrar(l);
                break;
            case 4:
                maiorNota(l);
                break;
            case 5:
                removerTodos(l);
                break;
            case 7:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 6);

    return 0;
}