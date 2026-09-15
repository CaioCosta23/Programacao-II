#include <stdio.h>
#include <stdlib.h>

#include "utils_char.h"

char *CriaVetor(int tamanho) {
    char *vetor = NULL;

    vetor = (char*)malloc(tamanho * sizeof(char));

    if (vetor == NULL){
        printf("Erro! Alocacao de memoria na criacao do vetor mal-sucedido.");
        exit(1);
    }
    
    int v;
    const char caractereInicial = '_';

    for(v = 0; v < tamanho; v++)
        *(vetor + v) = caractereInicial;
    
    return vetor;
}

void LeVetor(char *vetor, int tamanho) {
    int v = 0;
    char letra;

    while(v < tamanho) {
        scanf("%c", &letra);

        if (letra == '\n')
            break;

        *(vetor + v) = letra;

        v++;
    }
}

void ImprimeString(char *vetor, int tamanho){
    int v;

    for(v = 0; v < tamanho; v++) 
        printf("%c", *(vetor + v));
    
    printf("\n");
}


void LiberaVetor(char *vetor) {
    free(vetor);
}