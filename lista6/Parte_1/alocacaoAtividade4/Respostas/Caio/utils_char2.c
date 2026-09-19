#include <stdio.h>
#include <stdlib.h>

#include "utils_char2.h"

#define CARACTERE_PADRAO '_'

char *CriaVetorTamPadrao() {
    char *vetor = NULL;

    vetor = (char*)malloc((TAM_PADRAO + 1) * sizeof(char));

    if (vetor == NULL) {
        printf("Erro! Alocacao de memoria de vetor de caracteres mal-sucedida");
        exit(1);
    }

    unsigned int v;

    for(v = 0; v < TAM_PADRAO; v++)
        *(vetor + v) = CARACTERE_PADRAO;

    *(vetor + TAM_PADRAO) = '\0';

    return vetor;
}


char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo) {
    unsigned int novoTamanho;

    novoTamanho = tamanhoantigo + TAM_PADRAO;

    vetor = (char*)realloc(vetor, (novoTamanho + 1) * sizeof(char));

    if (vetor == NULL) {
        printf("Erro! Realocacao de memoria do vetor mal-sucedida.\n");
        LiberaVetor(vetor);
        exit(1);
    }

    unsigned int v;

    for(v = tamanhoantigo; v < novoTamanho; v++)
        *(vetor + v) = CARACTERE_PADRAO;
    
    *(vetor + novoTamanho) = '\0';

    return vetor;
}

char *LeVetor(char *vetor, int *tamanho) {
    int v = 0;
    char letra;

    while(1) {
        scanf("%c", &letra);

        if (letra == '\n') {
            break;
        }

        if (v == *tamanho){
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho = (*tamanho) + TAM_PADRAO;
        }
        
        *(vetor + v) = letra;
        v++;
    }

    return vetor;
}

void ImprimeString(char *vetor) {
    printf("%s\n", vetor);
}

void LiberaVetor(char *vetor) {
    if (vetor != NULL)
        free(vetor);
}