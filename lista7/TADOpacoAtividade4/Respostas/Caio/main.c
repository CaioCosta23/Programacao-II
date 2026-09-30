#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

/**
 * @brief Troca dois alunos de posição em uma lista//vetor/'array' de alunos;
 * 
 * @param alunos Ponteiro para lista/vetor/'array' de Tiipos Abstratos de Dados (T.A.D.s) que representam a estrutura que contém os dados (atualizados) dos alunos;
 * @param indice1 Indícce da posição do primeiro aluno a ser trocado por outro na lista/vetor/'array' de alunos;
 * @param indice2 Indícce da posição do segundo aluno a ser trocado por outro na lista/vetor/'array' de alunos;
 */
static void trocaAlunos(tAluno *alunos[], unsigned indice1, unsigned indice2) {
    tAluno *auxiliar;

    auxiliar = alunos[indice1];
    alunos[indice1] = alunos[indice2];
    alunos[indice2] = auxiliar;
}

/**
 * @brief Orrdena uma lista/vetor/'array' de alunos, por matrícula, e em ordem decrescente;
 * 
 * @param alunos Ponteiro para lista/vetor/'array' de Tiipos Abstratos de Dados (T.A.D.s) que representam a estrutura que contém os dados (atualizados) dos alunos;
 * @param quantidadeAlunos Quantidade de alunos na lista/vetor/'array' de alunos;
 */
static void OrdenaAlunos(tAluno *alunos[], unsigned int quantidadeAlunos) {
    unsigned int a1, a2;

    for(a1 = 0; a1 < (quantidadeAlunos - 1); a1++) {
        for(a2 = (a1 + 1); a2 < quantidadeAlunos; a2++){
            if (ComparaMatricula(alunos[a1], alunos[a2]) == 1)
                trocaAlunos(alunos, a1, a2);
        }
    }
}

/**
 * @brief Programa que registra o nome, matrícula e, (inicialmente) 3 notas de alunos, calcula a média
 * das notas de cada um e imprime na tela o nome daqueles que foram aprovados (mmédia maior ou igual a 7);
 * 
 * @return int Programa principal;
 */
int main() {
    unsigned int quantidadeAlunos, a;

    scanf("%d", &quantidadeAlunos);

    tAluno *alunos[quantidadeAlunos];

    for(a = 0; a < quantidadeAlunos; a++) {
        alunos[a] = CriaAluno();
        LeAluno(alunos[a]);
    }
    OrdenaAlunos(alunos, quantidadeAlunos);

    for(a = 0; a < quantidadeAlunos; a++)
        if (VerificaAprovacao(alunos[a]))
            ImprimeAluno(alunos[a]);

    for(a = 0; a < quantidadeAlunos; a++)
        ApagaAluno(alunos[a]);

    return 0;
}