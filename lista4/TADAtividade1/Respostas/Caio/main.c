#include <stdio.h>
#include <stdlib.h>

#include "jogo.h"

/**
 * @brief Programa que simula um jogo da velha;
 * 
 * @return int Programa principal;
 */
int main() {
    tJogo jogo;

    jogo = CriaJogo();

    do {
        ComecaJogo(jogo);
    }while((!AcabouJogo(jogo)));

    return 0;
}