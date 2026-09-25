#include <stdio.h>
#include <stdlib.h>

#include "jogo.h"

/**
 * @brief Programma que simula um jogo da velha (com memória alocada dinamicamente);
 * 
 * @return int Programa prrincipal
 */
int main() {
    tJogo *jogo;

    do {
        jogo = CriaJogo();

        ComecaJogo(jogo);
        DestroiJogo(jogo);
    }while(ContinuaJogo());

    return 0;
}