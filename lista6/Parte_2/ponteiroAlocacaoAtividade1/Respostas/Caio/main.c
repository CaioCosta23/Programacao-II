#include <stdio.h>
#include <stdlib.h>

#include "jogo.h"

int main() {
    tJogo *jogo;

    jogo = CriaJogo();

    do {
        ComecaJogo(jogo);
    }while(ContinuaJogo());

    DestroiJOgo(jogo);

    return 0;
}