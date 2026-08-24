#ifndef _JOGO_H
#define _JOGO_H

#include "jogador.h"
#include "tabuleiro.h"

typedef struct {
    tTabuleiro tabulero;
    tJogador jogador1;
    tJogador jogador2;
}tJogo;

/**
 * @brief Cria um jogo com todos os dados inicializados;
 * 
 * @return tJogo Tipo Abstrato de Dado (T.A.D) estruturado que contém os dados (inicializados/atualizados) do jogo;
 */
tJogo CriaJogo();

/**
 * @brief Verifica se o jogo deve continuar (reiniciar) ou não;
 * 
 * @return int 1 (verdadeiro) se o jogo deve continuar, ou 0 (falso), caso contrário;
 */
int ContinuaJogo();

/**
 * @brief Verifica se o jogo acabou;
 * 
 * @param jogo Tipo Abstrato de Dado (T.A.D) estruturado que contém os dados (atualizados) do jogo;
 * @return int 1 (verdadeiro) se o jogo acabou, ou 0 (falso), caso contrário;
 */
int AcabouJogo(tJogo jogo);

/**
 * @brief Começa e roda o jogo da velha;
 * 
 * @param jogo Tipo Abstrato de Dado (T.A.D) estruturado que contém os dados (atualizados) do jogo;
 */
void ComecaJogo(tJogo jogo);

#endif