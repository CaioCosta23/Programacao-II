#include <stdio.h>
#include <stdlib.h>

#include "jogo.h"

tJogo *CriaJogo() {
    tJogo *jogo = NULL;

    jogo = (tJogo*)malloc(sizeof(tJogo));

    if (jogo == NULL){
        printf("Erro! Alocacao de memoria do jogo mal sucedida.\n");
        exit(1);
    }

    jogo->tabuleiro = CriaTabuleiro();
    
    if ((*jogo).tabuleiro == NULL)
        DestroiJogo(jogo);
    
    jogo->jogador1 = CriaJogador(PECA_1);

    if ((*jogo).jogador1 == NULL)
        DestroiJogo(jogo);
    
    jogo->jogador2 = CriaJogador(PECA_2);

    if ((*jogo).jogador2 == NULL)
        DestroiJogo(jogo);

    return jogo;
}

void ComecaJogo(tJogo *jogo) {
    unsigned short int jogadas = 0;

    do {
        if (jogadas % 2 == 0)
            jogo->tabuleiro = JogaJogador((*jogo).jogador1, (*jogo).tabuleiro);
        else 
            jogo->tabuleiro = JogaJogador((*jogo).jogador2, (*jogo).tabuleiro);
        
        ImprimeTabuleiro((*jogo).tabuleiro);
    } while(!(AcabouJogo(jogo)));
}

int ContinuaJogo() {
    char resposta;
    const char CONTINUAR = 's', NAO_CONTINUAR = 'n';
    unsigned short int sair = 0; // Variável lógica;

    while(1) {
        scanf(" %c", &resposta);

        if ((resposta != CONTINUAR) && (resposta != NAO_CONTINUAR)) {
            printf("Resposta invalida! Por favor, digite 's' (minusculo) ou 'n' (minusculo).");
        }else {
            if (resposta == CONTINUAR)
                sair = 1;
            break;
        }
    }
    return sair;
}

int AcabouJogo(tJogo *jogo) {
    return ((VenceuJogador((*jogo).jogador1, (*jogo).tabuleiro)) || (VenceuJogador((*jogo).jogador2, (*jogo).tabuleiro)) || (!(TemPosicaoLivreTabuleiro((*jogo).tabuleiro))));
}

void DestroiJogo(tJogo *jogo) {
    if (jogo != NULL) {
        if ((*jogo).tabuleiro != NULL)
            free((*jogo).tabuleiro);
        if ((*jogo).jogador1 != NULL)
            free((*jogo).jogador1);
        if ((*jogo).jogador2 != NULL)
            free((*jogo).jogador2);
        
        free(jogo);
    }
}