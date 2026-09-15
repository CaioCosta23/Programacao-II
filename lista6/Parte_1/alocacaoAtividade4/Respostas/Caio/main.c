#include <stdio.h>
#include <stdlib.h>

#include "utils_char2.h"


/**
 * @brief Obtém o tamanho de uma 'string' (vetor/lista/'array' de caracteres);
 * 
 * @param string Ponteiro para a 'string' (vetor/lista/'array' de caracteres);
 * @return unsigned int Tamanho da 'string' (vetor/lista/'array' de caracteres);
 */
unsigned int obtemTamanhoString(char *string) {
    unsigned int tamanho = 0;

    while(*(string + tamanho) != '\0')
        tamanho++;
    
    return tamanho;
}

/**
 * @brief Programa que cria (aloca - memória - dinamicamente) um vetor de caracteres, 
 * lê uma 'string' para ocupar esse vetor/lista/'array' realoca o tamanho do mesmo dinamicamente,
 *  para se adequar ao tamanho da 'string' lida, imprime na tela e o libera (desaloca a memória dinamicamente);
 * 
 * @return int Programa principal;
 */
int main() {
    char *string, *vetor;
    unsigned int tamanho;


    vetor = CriaVetorTamPadrao();

    scanf("%s", string);

    tamanho = obtemTamanhoString(string);

    AumentaTamanhoVetor(vetor, tamanho);

    vetor = LeVetor(string, tamanho);

    ImprimeString(vetor);

    LiberaVetor(vetor);

    
    return 0;
}