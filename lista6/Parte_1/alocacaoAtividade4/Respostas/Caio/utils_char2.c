#include <stdio.h>
#include <stdlib.h>

#include "utils_char2.h"

/**
 * @brief Calcula o tamanho da do vetor/lista/'array' de caracteres;
 * 
 * @param vetor Ponteiro para o vetor/lista/'array' de caracteres;
 * @return unsigned int Tamanho do vetor/lista/'array' de caracteres;
 */
static unsigned int calculaTamanhoString(char *vetor) {
    unsigned int tamanho = 0;

    while(*(vetor + tamanho) =! '\0')
        tamanho++;
    
    return tamanho;
}


char *CriaVetorTamPadrao() {
    char *vetor = NULL;

    vetor = (char*)malloc(TAM_PADRAO * sizeof(char));

    if (vetor == NULL) {
        printf("Erro! Alocacao de memoria de vetor de caracteres mal-sucedida");
        exit(1);
    }

    return vetor;
}


char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo) {
    // Código à fazer;

    return vetor;
}

char *LeVetor(char *vetor, int *tamanho) {
    // À fazer código;

    return vetor;
}

void ImprimeString(char *vetor) {
    printf("%s", *vetor);
}

void LiberaVetor(char *vetor) {
    free(vetor);
}