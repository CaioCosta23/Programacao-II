#include <stdio.h>
#include <stdlib.h>

#include "tabuleiro.h"

tTabuleiro CriaTabuleiro() {
    tTabuleiro tabuleiro;
    unsigned int l, c;
    const char vazio = '-', peca1 = 'X', peca2 = '0';
    
    tabuleiro.peca1 = peca1;
    tabuleiro.peca2 = peca2;
    tabuleiro.pecaVazio = vazio;

    for(l = 0; l < TAM_TABULEIRO; l++) {
        for(c = 0; c < TAM_TABULEIRO; c++) {
            tabuleiro.posicoes[l][c] = vazio;
        }
    }
    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
    if (peca == PECA_1)
        tabuleiro.posicoes[y][x] = tabuleiro.peca1;
    else
        tabuleiro.posicoes[y][x] = tabuleiro.peca2;

    return tabuleiro;
}


int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
    unsigned int l, c;

    for(l = 0; l < TAM_TABULEIRO; l++) {
        for(c = 0; c < TAM_TABULEIRO; c++) {
            if (EstaLivrePosicaoTabuleiro(tabuleiro, l, c))
                return 1;
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca) {
    if (peca == PECA_1)
        return (tabuleiro.posicoes[y][x] == tabuleiro.peca1);
    else
        return (tabuleiro.posicoes[y][x] == tabuleiro.peca2);
}


int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
    return (tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio);
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    return (((x >= 0) && (x < TAM_TABULEIRO)) && ((y >= 0) && (y < TAM_TABULEIRO)));
}


void ImprimeTabuleiro(tTabuleiro tabuleiro) {
    unsigned int l, c;

    for(l = 0; l < TAM_TABULEIRO; l++) {
        printf("\t");
        for(c = 0; c < TAM_TABULEIRO; c++) {
            if (tabuleiro.posicoes[l][c] == tabuleiro.pecaVazio)
                printf("%c", tabuleiro.pecaVazio);
            else if (tabuleiro.posicoes[l][c] == tabuleiro.peca1)
                printf("%c", tabuleiro.peca1);
            else if (tabuleiro.posicoes[l][c] == tabuleiro.peca2)
                printf("%c", tabuleiro.peca2);
        }
        printf("\n");
    }
}