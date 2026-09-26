#ifndef _TABULEIRO_H
#define _TABULEIRO_H

#define TAM_TABULEIRO 3

#define PECA_1 1
#define PECA_2 2

typedef struct {
    char **posicoes;
    char peca1, peca2, pecaVazio;
}tTabuleiro;

/**
 * @brief Cria (aloca a memŕória dinamicamente de) um tabuleiro;
 * 
 * @return tTabuleiro* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que retpresenta a estrutura que contém as informações de um tabuleiro (com dados inicializados);
 */
tTabuleiro *CriaTabuleiro();

/**
 * @brief Verifica se existe alguma posição livre no tabuleiro;
 * 
 * @param tabuleiro Ponteiro para Tipo Abstrato de Dados (T.A.D.) que retpresenta a estrutura que contém as informações de um tabuleiro (com dados atualizados);
 * @return int 1 (verdadeiro) se houver alguma posição livre no tabuleiro ou 0 (falso), caso contrário;
 */
int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro);

/**
 * @brief Verifica se a posição é válida (se a mesma existe) no tabuleiro;
 * 
 * @param x Coordenada X da posição;
 * @param y Coordenada Y da posição;
 * @return int 1 (veradeiro) se a posição é válida (existe no tabuleiro) ou 0 (falso), caso contrário;
 */
int EhPosicaoValidaTabuleiro(int x, int y);

/**
 * @brief Cerifica se a posição já está marcada no tabuleiro;
 * 
 * @param tabuleiro Ponteiro para Tipo Abstrato de Dados (T.A.D.) que retpresenta a estrutura que contém as informações de um tabuleiro (com dados atualizados);
 * @param x Coordenada X da posição;
 * @param y Coordenada Y da posição;
 * @param peca Valor que representa a peça (que é ligada ao jogador);
 * @return int 1 (veradeiro) se a posição estiver marcada ou 0 (falso) caso contrário;
 * 
 * @OBS: Essa função busca verificar se a posição está marcada com a peça do próprio jogador;
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca);

/**
 * @brief Verifica se uma posição está livre no tabuleiro;
 * 
 * @param tabuleiro Ponteiro para Tipo Abstrato de Dados (T.A.D.) que retpresenta a estrutura que contém as informações de um tabuleiro (com dados atualizados);
 * @param x Coordenada X da posição;
 * @param y Coordenada Y da posição;
 * @return int 1 (verdadeiro) se a posição estiver livre ou 0 (falso), caso contrário;
 * 
 * @OBS: Verifica se ou a peça do próprio jogador ou se a peça do adversário está na posição ou se a mesma está livre;
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y);

/**
 * @brief Marca uma posição no tabuleiro;
 * 
 * @param tabuleiro Ponteiro para Tipo Abstrato de Dados (T.A.D.) que retpresenta a estrutura que contém as informações de um tabuleiro (com dados atualizados);
 * @param peca Peça que representa o jogador, no qual será marcada no tabuleiro;
 * @param x Coordenada X da posição;
 * @param y Coordenada Y da posição;
 */
void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y);

/**
 * @brief Imprime os dados de um tabueleiro;
 * 
 * @param tabuleiro Ponteiro para Tipo Abstrato de Dados (T.A.D.) que retpresenta a estrutura que contém as informações de um tabuleiro (com dados atualizados);
 */
void ImprimeTabueiro(tTabuleiro *tabuleiro);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente) e um tabuleiro
 * 
 * @param tabuleiro Ponteiro para Tipo Abstrato de Dados (T.A.D.) que retpresenta a estrutura que contém as informações de um tabuleiro (com dados atualizados);
 */
void DestroiTabuleiro(tTabuleiro *tabuleiro);

#endif