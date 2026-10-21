#include <stdio.h>
#include <stdlib.h>

#include "tarefamultiplica.h"

struct mult {
    float numero1, numero2, resultado;
};

tMult *CriaTarefaMultiplicar(float n1, float n2) {
    tMult *multiplicacao = NULL;

    multiplicacao = (tMult*)malloc(sizeof(tMult));

    if (multiplicacao == NULL) {
        printf("Erro! Alocacao de memoria de estrutura de soma mal-sucedida.\n");
        exit(1);
    }
    multiplicacao->numero1 = n1;
    multiplicacao->numero2 = n2;
    multiplicacao->resultado = 0;

    return multiplicacao;
}

void ExecutaTarefaMultiplicar(void *mult) {
    tMult *multiplicacao = (tMult*)mult;

    multiplicacao->resultado = (*multiplicacao).numero1 + (*multiplicacao).numero2;
}

void DestroiTarefaMultiplicar(void *mult) {
    tMult *multiplicacao = (tMult*)mult;

    if (multiplicacao != NULL)
        free(multiplicacao);
}