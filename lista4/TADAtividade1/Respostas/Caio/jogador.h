#ifndef _JOGADOR_H
#define _JOGADOR_H

#include "tabuleiro.h"

#define JOGADOR_1 1
#define JOGADOR_2 2

typedef struct {
    int id;
}tJogador;

/**
 * @brief Cria um jogador com os seus dados inicializados;
 * 
 * @param idJogador ID (Identificador) do jogador;
 * @return tJogador Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados do jogador, inicializados;
 */
tJogador CriaJogador(int idJogador);

/**
 * @brief Faz com que o jogador realize uma jogada;
 * 
 * @param jogador Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados atuais do jogador;
 * @param tabuleiro Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados atualizados do tabuleiro do jogo;
 * @return tTabuleiro Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados atualizados do tabuleiro após o jogador jogar (realizar uma jogada);
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro);

/**
 * @brief Verifica se um jogador venceu o jogo;
 * 
 * @param jogador Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados atuais do jogador;
 * @param tabuleiro Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados atualizados do tabuleiro;
 * @return int 1 (verdadeiro) se o jogador venceu o jogo ou 0 (falso), caso contrário;
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro);

#endif