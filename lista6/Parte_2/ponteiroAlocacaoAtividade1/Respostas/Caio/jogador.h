#ifndef _JOGADOR_H
#define _JOGADOR_H

#include "tabuleiro.h"

#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2

typedef struct {
    int id;
}tJogador;

/**
 * @brief Cria (aloca a memória dinamicamente de) um jogador;
 * 
 * @param idJogador ID (Identificador) do jogador;
 * @return tJogador* Ponteiro para Tipo Asbtrato de Dados (T.A.D.) que represneta a estrutura que contém as informações de um jogador (com seus dados inicializados);
 */
tJogador *CriaJogador(int idJogador);

/**
 * @brief Realiza a jogada do jogador no tabuleiro;
 * 
 * @param jogador Ponteiro para Tipo Asbtrato de Dados (T.A.D.) que represneta a estrutura que contém as informações de um jogador (com seus dados atualizados);
 * @param tabuleiro Ponteiro para Tipo Asbtrato de Dados (T.A.D.) que represneta a estrutura que contém as informações do tabuleiro (com seus dados atualizados); 
 */
void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro);

/**
 * @brief Verifica se um jogador venceu a partida;
 * 
 * @param jogador Ponteiro para Tipo Asbtrato de Dados (T.A.D.) que represneta a estrutura que contém as informações de um jogador (com seus dados atualizados);
 * @param tabuleiro Ponteiro para Tipo Asbtrato de Dados (T.A.D.) que represneta a estrutura que contém as informações do tabuleiro (com seus dados atualizados); 
 * @return int 1 (verdadeiro) se o jogador venceu a partida, ou 0 (falso), caso contrário;
 */
int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) um jogador;
 * 
 * @param jogador Ponteiro para Tipo Asbtrato de Dados (T.A.D.) que represneta a estrutura que contém as informações de um jogador (com seus dados atualizados);
 */
void DestroiJogador(tJogador *jogador);

#endif