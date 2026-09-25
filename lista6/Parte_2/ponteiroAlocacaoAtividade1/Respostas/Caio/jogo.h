#ifndef _JOGO_H
#define _JOGO_H

#include "tabuleiro.h"
#include "jogador.h"

typedef struct {
    tTabuleiro *tabuleiro;
    tJogador *jogador1, *jogador2;
}tJogo;


/**
 * @brief Cria/Inicializa (aloca a memória dinamicamente de) um jogo;
 * 
 * @return tJogo* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações do jogo que terá seus dados inicialzados;
 */
tJogo *CriaJogo();

/**
 * @brief Começa uma partida do jogo (e o jogo em si);
 * 
 * @param jogo Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações do jogo (com os dados inicializados);
 */
void ComecaJogo(tJogo *jogo);

 
/**
 * @brief Verifica se o jogo deve continuuar ( uma nova partida deve começar);
 * 
 * @return int 1 (verdadeiro) se o jogo deve continuar, ou 0 (falso), caso contrário;
 */
int ContinuaJogo();


/**
 * @brief Verifica se o jogo acabou (se um dos jogadores venceu ou terminou em empate);
 * 
 * @param jogo Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações do jogo (com os dados atualizados);
 * @return int 1 (verdadeiro) see o jogo acabou ou 0 (falso), caso contrário;
 */
int AcabouJogo(tJogo *jogo);

/**
 * @brief "Destrói" (desaloca a memória dinamicamente de) um jogo;
 * 
 * @param jogo Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações do jogo (com os dados atualizados);
 */
void DestroiJogo(tJogo *jogo);

#endif