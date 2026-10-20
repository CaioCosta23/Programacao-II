#ifndef _BANCO_H_
#define _BANCO_H_

#include "agencia.h"
#include "vector.h"

typedef struct Banco tBanco;

/**
 * @brief Cria (aloca a memória dinamicamente de) um banco;
 * 
 * @return tBanco* Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados inicializados) de um banco;
 */
tBanco *CriaBanco();

/**
 * @brief Lê os dados/informações de um banco;
 * 
 * @param banco Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (a serem lidas) de uma banco;
 */
void LeBanco(tBanco *banco);

/**
 * @brief Adiciona uma agência à um banco;
 * 
 * @param banco Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de um banco;
 * @param agencia Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de uma agência;
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia);

/**
 * @brief Imprime os dados/informações de um banco;
 * 
 * @param banco Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de um banco;
 */
void ImprimeRelatorioBanco(tBanco *banco);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) um banco;
 * 
 * @param banco Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de um banco;
 */
void DestroiBanco(tBanco *banco);

#endif