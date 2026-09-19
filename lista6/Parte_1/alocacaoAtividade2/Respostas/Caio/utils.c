#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int **CriaMatriz(int linhas, int colunas){
    int **matriz = NULL;
    unsigned int l, c;

    matriz = (int**)malloc(linhas * sizeof(int*));

    if (matriz == NULL) {
        printf("Erro! Alocacao geral da matriz mal-sucedida.\n");
        exit(1);
    }

    // Inicializando cada ponteiro de vetor da matriz;
    for(l = 0; l < linhas; l++)
        *(matriz + l) = NULL;
    
    for(l = 0; l < linhas; l++) {
            *(matriz + l) = (int*)calloc(colunas, sizeof(int));
            
            if (*(matriz + l) == NULL) {
                printf("Erro! Alocacao de memoria nas linhas da matriz mal sucedida.\n");
                LiberaMatriz(matriz, linhas);
                exit(1);
            }
    }

    return matriz;
}

void LeMatriz(int **matriz, int linhas, int colunas) {
    unsigned int l, c;

    for(l = 0; l < linhas; l++) {
        for(c = 0; c < colunas; c++) {
            scanf("%d", ((*(matriz + l)) + c));
        }
    }
}

void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas) {
    int l, c;

    for(c = 0; c < colunas; c++) {
        for(l = 0; l< linhas; l++) {
            printf("%d ", *((*(matriz + l)) + c));
        }
        printf("\n");
    }
}

void LiberaMatriz(int **matriz, int linhas) {
    if (matriz != NULL) {
        unsigned int l;
        
        for(l = 0; l < linhas; l++) {
            if (*(matriz + l) != NULL)
                free((*(matriz + l)));
        }
        free(matriz);
    }
}