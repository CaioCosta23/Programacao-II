#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "relatorio.h"

/**
 * @brief Programa que lê os dados de aluno, mostra a média das notas de todos os alunos, porcentagem de aprovações,
 * e a porcentagem de pessoas por gênero na turma;
 * 
 * @return int Programa principal;
 */
int main() {
    int quantidadeAlunos, a;
    Vector *vector;
    tAluno *aluno;
    
    scanf("%d\n", &quantidadeAlunos);

    vector = VectorConstruct();

    for(a = 0; a < quantidadeAlunos; a++)  {
        aluno = CriaAluno();

        LeAluno(aluno);
        VectorPushBack(vector, (data_type)aluno);
    }

    ImprimeRelatorio(vector);
    VectorDestroy(vector, DestroiAluno);

    return 0;
}