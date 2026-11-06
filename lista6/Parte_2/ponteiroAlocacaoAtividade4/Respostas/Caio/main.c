#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

/**
 * @brief Troca as posições de dois alunos no vetor/lista/'array' de alunos;
 * 
 * @param alunos Vetor/lista/'array' de ponteiros para Tipos Abstratos de Dados (T.A.D.s) que representam as estruturas que contém as informações (atualizadas) dos alunos;
 * @param indice1 Índice da posição do primeiro aluno a ser ter a posição trocada com outro no vetor/lista/'array' de alunos;
 * @param indice2 Índice da posição do segundo aluno a ser ter a posição trocada com outro no vetor/lista/'array' de alunos;
 */
static void trocaPosicoesAlunos(tAluno *alunos[], unsigned int indice1, unsigned int indice2) {
    tAluno *auxiliar;

    auxiliar = alunos[indice1];
    alunos[indice1] = alunos[indice2];
    alunos[indice2] = auxiliar;
}

/**
 * @brief Ordena, de maneira crescente (por matrícula) os alunos no vetor/lista/'array' de alunos;
 * 
 * @param alunos Vetor/lista/'array' de ponteiros para Tipos Abstratos de Dados (T.A.D.s) que representam as estruturas que contém as informações (atualizadas) dos alunos;
 * @param quantidadeAlunos Quantidade de alunos no vetor/lista/'array' de alunos;
 */
static void ordenaAlunosPorMatricula(tAluno *alunos[], unsigned int quantidadeAlunos) {
    unsigned int a1, a2;

    for(a1 = 0; a1 < (quantidadeAlunos - 1); a1++)
        for(a2 = (a1 + 1); a2 < quantidadeAlunos; a2++)
            if (ComparaMatricula(alunos[a1], alunos[a2]) == 1)
                trocaPosicoesAlunos(alunos, a1, a2);
}

int main() {
    unsigned int quantidadeAlunos, a;

    scanf("%d\n", &quantidadeAlunos);

    tAluno *alunos[quantidadeAlunos];

    for(a = 0; a < quantidadeAlunos; a++) {
        alunos[a] = CriaAluno();
        
        LeAluno(alunos[a]);
    }

    ordenaAlunosPorMatricula(alunos, quantidadeAlunos);

    for(a = 0; a < quantidadeAlunos; a++) {
        if (VerificaAprovacao(alunos[a]))
            ImprimeAluno(alunos[a]);
    }

    for(a = 0; a < quantidadeAlunos; a++)
        ApagaAluno(alunos[a]);

    return 0;
}