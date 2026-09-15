#include <stdio.h>
#include <stdlib.h>

#include "utils_char.h"

#define INICIALIZACAO '_'

/**
 * @brief Verifica se o vetor/lista/'array' está vazio;
 * 
 * @param vetor Ponteiro para o vetor/lista/'array' de caracteres (alocados dinamicamente);
 * @param tamanho Tamano do vetor/lista/'array';
 * @return int 1 (verdadeiro) se o vetor estiver "vazio" (ou seja, sem nenhum caractere lido, apenas com o caractere de inicialização) ou 0 (falso), caso contrário;
 */
int verificaVetorVazio(char *vetor, int tamanho) {
    int v;
    unsigned short int vazio = 1;// Variável lógica;

    for(v = 0; v < tamanho; v++) {
        if (*(vetor +  v) != INICIALIZACAO) {
            vazio = 0;
            break;
        }
    }
    return vazio;
}

/**
 * @brief Programa que lê o tamanho de um vetor/lista/'array' de caracteres,
 * os aloca dinamicamente e imprime-os em formato de 'string' e, em seguida,
 * os desaloca dinamicamente;
 * 
 * @return int Programa principal;
 */
int main() {
    int tamanhoVetor;
    char *vetor;

    scanf("%d", &tamanhoVetor);

    
    vetor = CriaVetor(tamanhoVetor);
    
    while(1) {
        LeVetor(vetor, tamanhoVetor);
        ImprimeString(vetor, tamanhoVetor);

        if (!(verificaVetorVazio(vetor, tamanhoVetor)))
            break;
    }
    LiberaVetor(vetor);
    
    return 0;
}