#ifndef _JOGADA_H
#define _JOGADA_H

typedef struct{
    int x, y;
    int sucesso;
}tJogada;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma jogada;
 * 
 * @return tJogada* Ponteiro para o Tipo Abstrato de Dados (T.A.D.) queeee represnesta a estrutura que contém as informações de uma jogada (com seus dados inicializados);
 */
tJogada *CriaJogada();

/**
 * @brief Lê os dados de uma jogada;
 * 
 * @param jogada Ponteiro para o Tipo Abstrato de Dados (T.A.D.) queeee represnesta a estrutura que contém as informações de uma jogada (com seus dados inicializados) e que serão lidas;
 */
void LeJogada(tJogada *jogada);

/**
 * @brief Obtém o valor da coordenada X da jogada;
 * 
 * @param jogada Ponteiro para o Tipo Abstrato de Dados (T.A.D.) queeee represnesta a estrutura que contém as informações de uma jogada (com seus dados atualizados);
 * @return int Valor da coordenada X da jogada;
 */
int ObtemJogadaX(tJogada *jogada);

/**
 * @brief Obtém o valor da coordenada Y da jogada;
 * 
 * @param jogada Ponteiro para o Tipo Abstrato de Dados (T.A.D.) queeee represnesta a estrutura que contém as informações de uma jogada (com seus dados atualizados);
 * @return Valor da coordenada Y da jogada;
 */
int ObtemJogadaY(tJogada *jogada);

/**
 * @brief Verifica se uma jogada foi bem sucedida (se seus dados foram lidos corretamente);
 * 
 * @param jogada Ponteiro para o Tipo Abstrato de Dados (T.A.D.) queeee represnesta a estrutura que contém as informações de uma jogada (com seus dados atualizados);
 * @return int 1 (verdadeiro) se a jogada foi be sucedida ou 0 (falso), caso contrário;
 */
int FoiJogadaBemSucedida(tJogada *jogada);

/**
 * @brief Destrói (desaloca/libera a memória dinamicamente de) uma jogada;
 * 
 * @param jogada Ponteiro para o Tipo Abstrato de Dados (T.A.D.) queeee represnesta a estrutura que contém as informações de uma jogada (com seus dados atualizados);
 */
void DestroiJogada(tJogada *jogada);

#endif