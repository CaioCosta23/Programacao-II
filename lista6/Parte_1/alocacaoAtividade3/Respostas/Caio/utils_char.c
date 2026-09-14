#include <stdio.h>
#include <stdlib.h>

#include "utils_char.h"

char *CriaVetor(int tamanho) {
    char *vetor = NULL;

    vetor = (char*)malloc(tamanho * sizeof(char));

    if (vetor == NULL)
        printf("Erro! Alocacao de memoria na criacao do vetor mal-sucedido.");
    
    return vetor;
}

void LeVetor(char *vetor, int tamanho) {
    int v;

    for(v = 0; v < tamanho; v++)
        scanf("%c", (vetor + v));
}

void ImprimeString(char *vetor, int tamanho){
    int v;

    for(v = 0; v < tamanho; v++) 
        printf("%c", *(vetor + v));
}


void LiberaVetor(char *vetor) {
    free(vetor);
}