#ifndef _TABULEIRO_H
#define _TABULEIRO_H

#define TAM_TABULEIRO 3
#define PECA_1 1
#define PECA_2 2

typedef struct {
    char posicoes[TAM_TABULEIRO][TAM_TABULEIRO];
    char peca1, peca2, pecaVazio;
}tTabuleiro;

/**
 * @brief Cria um tabuleiro cm todos os seus dados inicializados;
 * 
 * @return tTabuleiro Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados do tabuleiro, inicializados;
 */
tTabuleiro CriaTabuleiro();

/**
 * @brief 
 * 
 * @param tabuleiro Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados atualizados do tabuleiro;
 * @param peca Peça que representa o jogador (1 ou 2);
 * @param x Coordenada X de uma posição do tabuleiro;
 * @param y Coordenada Y de uma posição do tabuleiro;
 * @return tTabuleiro Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados atualizados do tabuleiro após a jogada;
 */
tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y);

/**
 * @brief 
 * 
 * @param tabuleiro Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados atualizados do tabuleiro;
 * @param peca Peça que representa o jogador;
 * @param x Coordenada X do tabuleiro;
 * @param y Coordenada Y do tabuleiro;
 * @return int 1 (verdadeiro) se tem osição livre no tabuleiro ou 0 (falso), caso contrário;
 */
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y);

/**
 * @brief Verifica se a posição do tabuleiro está marcada;
 * 
 * @param tabuleiro Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados atualizados do tabuleiro;
 * @param x Coordenada X do tabuleiro;
 * @param y Coordenada Y do tabuleiro;
 * @param peca Peça que representa o jogador;
 * @return int 1 (verdadeiro) se a posição está marcada ou 0, caso contrário;
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca);

/**
 * @brief 
 * 
 * @param tabuleiro Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados atualizados do tabuleiro;
 * @param x Coordenada X do tabuleiro;
 * @param y Coordenada Y do tabuleiro;
 * @return int 1 (verdadeiro) se a posição está livre;
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y);

/**
 * @brief Verifica se posição do tabuleiro é válida;
 * 
 * @param x Coordenada X do tabuleiro;
 * @param y Coordenada Y do tabuleiro;
 * @return int 1 (Verdadeiro) se a posição é válida ou 0 (falso), caso contrário;
 */
int EhPosicaoValidaTabuleiro(int x, int y);

/**
 * @brief Imprime o tabuleiro;
 * 
 * @param tabuleiro Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui os dados atualizados do tabuleiro;
 */
void ImprimeTabuleiro(tTabuleiro tabuleiro);

#endif