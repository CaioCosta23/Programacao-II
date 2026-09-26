#include <stdio.h>
#include <stdlib.h>

#include "jogador.h"

#include "jogada.h"

tJogador *CriaJogador(int idJogador) {
    tJogador *jogador = NULL;

    jogador = (tJogador*)malloc(sizeof(tJogador));

    if (jogador == NULL) {
        printf("Erro! Alocacao de memoria do jogador mal-sucedida.\n");
        exit(1);
    }
    jogador->id =  idJogador;

    return jogador;
}

void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro) {
    tJogada *jogada;
    
    jogada = CriaJogada();

    while(1) {
        printf("Jogador %d\n", (*jogador).id);
        LeJogada(jogada);

        if (!(FoiJogadaBemSucedida(jogada))) {
            printf("Formato invalido!\n");
            continue;
        }
        
        if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
            if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada), (*jogador).id)))
                if (EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
                    printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    MarcaPosicaoTabuleiro(tabuleiro, (*jogador).id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    break;
                }else{
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
            else
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        else
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    }
    DestroiJogada(jogada);
}

int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro) {
    unsigned short int l, c, d, s;
    unsigned short int linha, coluna, diagonalPrincipal, diagonalSecundaria;

    for(l = 0; l < TAM_TABULEIRO; l++) {
        linha = 1;
        coluna = 1;
        for(c = 0; c < TAM_TABULEIRO; c++) {
            if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, l, c, (*jogador).id)))
                linha = 0;
            if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, c, l, (*jogador).id)))
                coluna = 0;
            
        }
        if ((linha) || (coluna))
            return 1;
    }

    diagonalPrincipal = 1;
    diagonalSecundaria = 1;
    
    for(d = 0, s = (TAM_TABULEIRO - 1); (d < TAM_TABULEIRO && s >= 0); d++, s--) {
        if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, d, d, (*jogador).id)))
            diagonalPrincipal = 0;
        if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, d, s, (*jogador).id)))
            diagonalSecundaria = 0;
    }

    if ((diagonalPrincipal) || (diagonalSecundaria))
        return 1;
    return 0;
}

void DestroiJogador(tJogador *jogador) {
    if (jogador != NULL)
        free(jogador);
}