#include <stdio.h>
#include <stdlib.h>

#include "utils_char2.h"


/**
 * @brief Programa que cria (aloca - memória - dinamicamente) um vetor de caracteres, 
 * lê uma 'string' para ocupar esse vetor/lista/'array' realoca o tamanho do mesmo dinamicamente,
 *  para se adequar ao tamanho da 'string' lida, imprime na tela e o libera (desaloca a memória dinamicamente);
 * 
 * @return int Programa principal;
 */
int main() {
    char *vetor;
    int tamanho;

    tamanho = TAM_PADRAO;

    vetor = CriaVetorTamPadrao();
    //vetor = AumentaTamanhoVetor(vetor, TAM_PADRAO);
    vetor = LeVetor(vetor, &tamanho);

    ImprimeString(vetor);
    LiberaVetor(vetor);

    
    return 0;
}