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
    char peca;

    while(1) {
        LeJogada(jogada);

        printf("Jogador %d\n", (*jogador).id);

        if (!(FoiJogadaBemSucedida(jogada))) {
            printf("Formato invalido!\n");
            continue;
        }

        if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
            if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada), (*jogador).id))
                if (EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))){
                    MarcaPosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada), (*jogador).id);
                    break;
                }else{
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
            else
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        else
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    }
}

int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro) {
    unsigned short int linha, coluna, diagonalPrincipal, diagonalSecundaria; // Variáveis lógicas;
    unsigned short int l, c, d, s;
    char pecaComparada;

    if ((*jogador).id == PECA_1)
        pecaComparada = (*tabuleiro).peca1;
    else
        pecaComparada = (*tabuleiro).peca2;

    // Verifica se alguma linha ou coluna possui uma sequência;
    for(l = 0; l < TAM_TABULEIRO; l++){
        linha = 1;
        coluna = 1;
        for(c = 0; c < TAM_TABULEIRO; c++) {
            // Caso a sequência de peças do mesmo tipo seja quebrada, indica que ela não existe (verifica na linha e na coluna);
            if ((*tabuleiro).posicoes[l][c] != pecaComparada)
                linha = 0;
            if ((*tabuleiro).posicoes[c][l] != pecaComparada)
                coluna = 0; 
        }
        if ((linha) || coluna)
            return 1;
    }

    diagonalPrincipal = 1;
    diagonalSecundaria = 0;

    // Verifica se a diagonal principal ou a secundária possuem uma sequência;
    for(d = 0, s = (TAM_TABULEIRO - 1); (d < TAM_TABULEIRO && s >= 0); d++, d--){
        // Caso a sequência de peças do mesmo tipo seja quebrada, indica que ela não existe (verifica na diagonal principal e na secundária);
        if ((*tabuleiro).posicoes[d][d] != pecaComparada)
            diagonalPrincipal = 0;
        if ((*tabuleiro).posicoes[d][s] != pecaComparada)
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