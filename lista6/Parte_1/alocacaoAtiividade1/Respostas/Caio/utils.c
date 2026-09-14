#include <stdio.h>
#include <stdlib.h>


int *CriaVetor(int tamanho) {
    int *vetor = NULL;

    vetor = (int*)malloc(tamanho * sizeof(int));

    if (vetor == NULL)
        printf("Erro! Alocacao de memoria em craicao de vetor, mal sucedida.\n");

    return vetor;
}

void LeVetor(int *vetor, int tamanho) {
    int v;

    for(v = 0; v < tamanho; v++) 
        scanf("%d", (vetor + v));
}

float CalculaMedia(int *vetor, int tamanho) {
    int v;
    int soma = 0;

    for(v = 0; v < tamanho; v++)
        soma += *(vetor + v);

    return (float)soma / (float)tamanho;
}

void LiberaVetor(int *vetor) {
    free(vetor);
}