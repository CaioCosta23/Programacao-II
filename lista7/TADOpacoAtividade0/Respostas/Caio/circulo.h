#ifndef _CIRCULO
#define _CIRCULO

#include "ponto.h"

typedef struct circulo *tCirculo;

/**
 * @brief Cria (aloca dinamicamente a memória de) um círculo;
 * 
 * @param x Coordenada X do centro do círculo;
 * @param y Coordenada Y do centro do círculo;
 * @param r Raio do círculo;
 * @return tCirculo (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (inicializados) de um círculo;
 */
tCirculo Circulo_Cria(float x, float y, float r);

/**
 * @brief Atriui um ponto ao centro do círculo;
 * 
 * @param c (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um círculo;
 * @param p (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um ponto;
 */
void Circulo_Atribui_Centro(tCirculo c, tPonto p);

/**
 * @brief Atribui um valor ao raio do círculo;
 * 
 * @param c (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um círculo;
 * @param r Raio do círculo;
 */
void Circulo_Atribui_Raio(tCirculo c, float r);

/**
 * @brief Obtém o valor do raio do círculo;
 * 
 * @param c (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um círculo;
 * @return float Valor doraio do círculo;
 */
float Circulo_Acessa_Raio(tCirculo c);

/**
 * @brief Obtém o ponto (Tipo Abstrato de Dados - T.A.D. - que representa um ponto) que representa o centro do círculo;
 * 
 * @param c (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um círculo;
 * @return tPonto (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um ponto que representa o centro do círculo;
 */
tPonto Circulo_Acessa_Centro(tCirculo c);

/**
 * @brief Verifica se um ponto está dentro de fe um círculo;
 * 
 * @param c (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um círculo;
 * @param p (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um ponto;
 * @return int 1 (verdadeiro) se o ponto está dentro do círculo ou 0 (falso), caso contrário;
 */
int Circulo_Interior(tCirculo c, tPonto p);

/**
 * @brief Apaga (libera/desaloca a memória dinamicamente de) um círculo;
 * 
 * @param c (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um círculo;
 */
void Circulo_Apaga(tCirculo c);

#endif