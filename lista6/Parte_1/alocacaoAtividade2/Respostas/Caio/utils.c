#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int **CriaMatriz(int linhas, int colunas){
    int **matriz;

    // A fazer;

    return matriz;
}

void LeMatriz(int **matriz, int linhas, int colunas) {
    // A fazer;
}

void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas) {
    int l, c;

    for(l = 0; l < linhas; l++) {
        for(c = 0; c < colunas; c++) {
            //printf("%d ", *(*(matriz + c)));
        }
        printf("\n");
    }
}

void LiberaMatriz(int **matriz, int linhas) {
    int l;

    for(l = 0; l < linhas; l++) {
        free(matriz + l);
    }
    free(matriz);
}