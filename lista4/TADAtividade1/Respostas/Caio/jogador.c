#include <stdio.h>
#include <stdlib.h>

#include "jogador.h"

#include "jogada.h"

tJogador CriaJogador(int idJogador) {
    tJogador jogador;

    jogador.id = idJogador;

    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    tJogada jogada;

    printf("Jogador %d\n", jogador.id);

    jogada = LeJogada();
    
    if (FoiJogadaBemSucedida(jogada)) {
        if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))){
            unsigned short int adversario;

            if (jogador.id == PECA_1)
                adversario = PECA_2;
            else
                adversario = PECA_1;
            
            if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada), adversario))) {
                if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada), jogador.id))) {
                    printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }else {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
            }else {
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            }
        }else {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d %d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        }
    }
    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    unsigned int l, c, dp, lds, cds;
    unsigned short int coluna, linha, diagonalPrincipal, diagonalSecundaria;

    linha = 1;
    
    for(l = 0; l < TAM_TABULEIRO; l++) {
        coluna = 1;
        for(c = 0; c < TAM_TABULEIRO; c++) {
            // Verifica se a coluna está completa ou não
            if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, l, c, jogador.id))) {
                coluna = 0;
                break;
            }
        }
        if (coluna)
            return 1;
        // Verifica se a linha está completa ou não;
        if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, l, c, jogador.id)))
            linha = 0;
    }
    if (linha) 
        return 1;
    
    diagonalPrincipal = 1;

    for(dp = 0; dp < TAM_TABULEIRO; dp++) {
        if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, dp, dp, jogador.id))) {
            diagonalPrincipal = 0;
            break;
        }
    }
    if (diagonalPrincipal)
        return 1;
    
    diagonalSecundaria = 1;
    for(lds = 0, cds = (TAM_TABULEIRO - 1); lds < TAM_TABULEIRO && cds >= 0; lds++, cds--){
        if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, lds, cds, jogador.id))) {
            diagonalSecundaria = 0;
            break;
        }
    }
    // Como é a última verificação, podemos retornar diretamente;
    return diagonalSecundaria;
}