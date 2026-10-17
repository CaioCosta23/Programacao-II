#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

#define MAX_CARACTERES 51

struct Aluno {
    char nome[MAX_CARACTERES];
    char genero;
    float nota;
};

tAluno *CriaAluno() {
    tAluno *aluno = NULL;

    aluno = (tAluno*)malloc(sizeof(aluno));

    if (aluno == NULL) {
        printf("Erro! Alocacao de memoria de aluno mal-sucedida!!\n");
        exit(1);
    }
    aluno->genero = '\0';
    aluno->nota = 0;

    return aluno;
}

void LeAluno(tAluno *aluno) {
    scanf(" %[^;];%c;%f\n", aluno->nome, &aluno->genero, &aluno->nota);
}

char GetGeneroAluno(tAluno *aluno) {
    return (*aluno).genero;
}

float GetNotaAluno(tAluno *aluno) {
    return (*aluno).nota;
}

void DestroiAluno(data_type aluno) {
    tAluno *ponteiroAluno = (tAluno*)aluno;

    if (ponteiroAluno != NULL)
        free(ponteiroAluno);
}