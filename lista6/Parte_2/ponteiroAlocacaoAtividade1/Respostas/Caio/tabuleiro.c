#include <stdio.h>
#include <stdlib.h>

#include "tabuleiro.h"

#define SIMBOLO_PECA_1 'X'
#define SIMBOLO_PECA_2 '0'
#define SIMBOLO_VAZIO '-'

tTabuleiro *CriaTabuleiro() {
    tTabuleiro *tabuleiro = NULL;

    tabuleiro = (tTabuleiro*)malloc(sizeof(tTabuleiro));

    if (tabuleiro == NULL) {
        printf("Erro! Alocacao de memoria para tabuleiro mal-sucedida.\n");
        exit(1);
    }
    
    tabuleiro->posicoes = NULL;

    tabuleiro->posicoes = (char**)malloc(TAM_TABULEIRO * sizeof(char*));
    if (((*tabuleiro).posicoes == NULL)){
        printf("Erro! Alocacao da matriz de posicoes mal-sucedida.\n");
        DestroiTabuleiro(tabuleiro);
        exit(1);
    }
    
    unsigned short int l;

    for(l = 0; l < TAM_TABULEIRO; l++) {
        tabuleiro->posicoes[l] = NULL;

        tabuleiro->posicoes[l] = (char*)malloc(TAM_TABULEIRO * sizeof(char));

        if ((*tabuleiro).posicoes[l] == NULL) {
            printf("Erro! Alocacao de memoria do vetor %d da matriz mal-sucedida.\n", l);
            DestroiTabuleiro(tabuleiro);
            exit(1);
        }
    }
    tabuleiro->peca1 = SIMBOLO_PECA_1;
    tabuleiro->peca2 = SIMBOLO_PECA_2;
    tabuleiro->pecaVazio = SIMBOLO_VAZIO;

    unsigned short int c;

    for(l = 0; l < TAM_TABULEIRO; l++)
        for(c = 0; c < TAM_TABULEIRO; c++)
            tabuleiro->posicoes[l][c] = (*tabuleiro).pecaVazio;

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro) {
    unsigned short int l, c;

    for(l = 0; l < TAM_TABULEIRO; l++)
        for(c = 0; c < TAM_TABULEIRO; c++)
            if (EstaLivrePosicaoTabuleiro(tabuleiro, l, c));
                return 1;

    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    return (((x >= 0) && (x < TAM_TABULEIRO)) && ((y >= 0) && (y < TAM_TABULEIRO)));
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca) {
    if (peca == PECA_1) {
        return ((*tabuleiro).posicoes[y][x] == (*tabuleiro).peca1);
    }else if (peca == PECA_2){
        return ((*tabuleiro).posicoes[y][x] == (*tabuleiro).peca2);
    }else {
        printf("Erro! Peca/Jogador nao existente.\n");
        exit(1);
    }
}

int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y) {
    return ((*tabuleiro).posicoes[y][x] == (*tabuleiro).pecaVazio);
}

void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y) {
    if (peca == PECA_1) {
        tabuleiro->posicoes[y][x] = (*tabuleiro).peca1;
    }else if (peca == PECA_2){
        tabuleiro->posicoes[y][x] = (*tabuleiro).peca2;
    }else {
        printf("Erro! Peca/Jogador nao existente.\n");
        exit(1);
    }
}

void ImprimeTabuleiro(tTabuleiro *tabuleiro) {
    unsigned short int l, c;

    for(l = 0; l < TAM_TABULEIRO; l++) {
        printf("\t");
        for(c = 0; c < TAM_TABULEIRO; c++) {
            printf("%c", (*tabuleiro).posicoes[l][c]);
        }
        printf("\n");
    }
}

void DestroiTabuleiro(tTabuleiro *tabuleiro) {
    if (tabuleiro != NULL) {
        if ((*tabuleiro).posicoes != NULL){
            unsigned short int l;

            for(l = 0; l < TAM_TABULEIRO; l++)
                if ((*tabuleiro).posicoes[l] != NULL)
                    free((*tabuleiro).posicoes[l]);
            free((*tabuleiro).posicoes);
        }
        free(tabuleiro);
    }
}