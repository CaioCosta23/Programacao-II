#include <stdio.h>
#include <stdlib.h>

#include "tarefasoma.h"

struct soma {
    float numero1, numero2, resultado;
};

tSoma *CriaTarefaSoma(float n1, float n2) {
    tSoma *adicao = NULL;

    adicao = (tSoma*)malloc(sizeof(tSoma));

    if (adicao == NULL) {
        printf("Erro! Alocacao de memoria de estrutura de soma mal-sucedida.\n");
        exit(1);
    }
    adicao->numero1 = n1;
    adicao->numero2 = n2;
    adicao->resultado = 0;

    return adicao;
}

void ExecutaTarefaSoma(void *sum) {
    tSoma *adicao = (tSoma*)sum;

    adicao->resultado = (*adicao).numero1 + (*adicao).numero2;
}

void DestroiTarefaSoma(void *sum) {
    tSoma *adicao = (tSoma*)sum;

    if (adicao != NULL)
        free(adicao);
}