#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

// Troca as matrículas de lugar;
void TrocaLugarAlunos(tAluno alunos[], unsigned int indice1, unsigned int indice2) {
    tAluno auxiliar;

    auxiliar = alunos[indice1];
    alunos[indice1] = alunos[indice2];
    alunos[indice2] = auxiliar;
}

// Funão que ordena alunos por ordem de matrícula;
void ordenaAlunos(tAluno alunos[], unsigned int quantidadeAlunos) {
    int a1, a2;

    for (a1 = 0; a1 < quantidadeAlunos - 1; a1++) {
        for (a2 = a1 + 1; a2 < quantidadeAlunos; a2++) {
            if (ComparaMatricula(alunos[a1], alunos[a2]) == 1)
                TrocaLugarAlunos(alunos, a1, a2);
        }
    }
}


/**
 * @brief Pograma que verifica quais alunos foram aprovados e os ordena em ordem (crescente) de matrícula;
 * 
 * @return int Programa principal
 */
int main() {
    unsigned int quantidadeAlunos;
    int a;

    scanf("%d", &quantidadeAlunos);

    tAluno alunos[quantidadeAlunos];

    for(a = 0; a < quantidadeAlunos; a++) {
        alunos[a] = LeAluno();
    }

    OrdenaAlunos(alunos, quantidadeAlunos);

    for(a = 0; a < quantidadeAlunos; a++) {
        if (VerificaAprovacao(alunos[a]))
            ImprimeAluno(alunos[a]);
    }

    return 0;
}