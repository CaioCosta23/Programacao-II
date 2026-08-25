#ifndef _JOGADA_H
#define _JOGADA_H

typedef struct {
    int x, y;
    int sucesso; // Variável lógica;
}tJogada;


/**
 * @brief Lê uma jogada do jogo;
 * 
 * @return tJogada Tipo Abstrato de Dado (T.A.D) estruturado que contém os dados (inicializados/atualizados) da jogo;
 */
tJogada LeJogada();

/**
 * @brief 
 * 
 * @param jogada tJogada Tipo Abstrato de Dado (T.A.D) estruturado que contém os atuais dados do tabuleiro do jogo;
 * @return int valor do da coordenada X
 */
int ObtemJogadaX(tJogada jogada);

/**
 * @brief Busca/Obtém o valor da coordenada Y no tabuleiro;
 * 
 * @param jogada tJogada Tipo Abstrato de Dado (T.A.D) estruturado que contém os atuais dados do tabuleiro do jogo;
 * @return int valor de coordenda do jogo
 */
int ObtemJogadaY(tJogada jogada);

/**
 * @brief Verifica se uma jogada foi bemsucedida;
 * 
 * @param jogada tJogada Tipo Abstrato de Dado (T.A.D) estruturado que contém os atuais dados do tabuleiro do jogo;
 * @return int 1 (verdadeiro) se a jogada for bem sucedida, ou 0 (casonrário);
 */
int FoiJogadaBemSucedida(tJogada jogada);

#endif