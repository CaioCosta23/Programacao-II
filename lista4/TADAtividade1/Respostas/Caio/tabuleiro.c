#include <stdio.h>
#include <stdlib.h>

#include "tabuleiro.h"

#define SIMBOLO_PECA_1 'X'
#define SIMBOLO_PECA_2 '0'
#define SIMBOLO_PECA_VAZIO '-'

tTabuleiro CriaTabuleiro() {
    tTabuleiro tabuleiro;
    unsigned int l, c;
    const unsigned short vazio = 0;
    
    tabuleiro.peca1 = PECA_1;
    tabuleiro.peca2 = PECA_2;
    tabuleiro.pecaVazio = vazio;

    for(l = 0; l < TAM_TABULEIRO; l++) {
        for(c = 0; c < TAM_TABULEIRO; c++) {
            tabuleiro.posicoes[l][c] = vazio;
        }
    }
    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
    tabuleiro.posicoes[x][y] = peca;

    return tabuleiro;
}


int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
    unsigned int l, c;

    for(l = 0; l < TAM_TABULEIRO; l++) {
        for(c = 0; c < TAM_TABULEIRO; l++) {
            if (EstaLivrePosicaoTabuleiro(tabuleiro, l, c))
                return 1;
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca) {
    return (tabuleiro.posicoes[x][y] == peca);
}


int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
    return (tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio);
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    return (((x >= 0) && (x < TAM_TABULEIRO)) && ((y >= 0) && (y < TAM_TABULEIRO)));
}


void ImprimeTabuleiro(tTabuleiro tabuleiro) {
    unsigned int l, c;

    for(l = 0; l < TAM_TABULEIRO; l++) {
        for(c = 0; c < TAM_TABULEIRO; l++) {
            if (tabuleiro.posicoes[l][c] == tabuleiro.pecaVazio)
                printf("%c", SIMBOLO_PECA_VAZIO);
            else if (tabuleiro.posicoes[l][c] == tabuleiro.peca1)
                printf("%c", SIMBOLO_PECA_1);
            else if (tabuleiro.posicoes[l][c] == tabuleiro.peca2)
                printf("%c", SIMBOLO_PECA_2);
        }
    }
}