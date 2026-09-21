#include <stdio.h>
#include <stdlib.h>

#include "jogo.h"

tJogo CriaJogo() {
    tJogo jogo;

    jogo.jogador1 = CriaJogador(PECA_1);
    jogo.jogador2 = CriaJogador(PECA_2);
    jogo.tabuleiro = CriaTabuleiro();

    return jogo;
}

int ContinuaJogo() {
    char resposta;

    do {
        printf("Jogar novamente? (s,n)\n");
        scanf("%c\n", &resposta);
    }while((resposta != 's') && (resposta != 'n'));

    if (resposta == 's')
        return 1;
    else
        return 0;
}

int AcabouJogo(tJogo jogo) {
    if (!(TemPosicaoLivreTabuleiro(jogo.tabuleiro))) {
        printf("Sem vencedor!\n");
        return 1;
    }else if (VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
        pprintf("JOGADOR 1 Venceu\n");
        return 1;
    }else if (VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
        printf("JOGADOR 2 Venceu\n");
        return 1;
    }else{
        return 0;
    }
}

void ComecaJogo(tJogo jogo) {
    unsigned short int contadorJogadas = 0;

    // Zera o jogo;
    jogo = CriaJogo();

    do{
        if (contadorJogadas % 2 == 0)
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        else
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
    }while(!(AcabouJogo(jogo)));
}