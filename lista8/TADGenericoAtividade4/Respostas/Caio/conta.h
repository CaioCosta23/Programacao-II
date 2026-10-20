#ifndef _CONTA_H_
#define _CONTA_H_

#include "vector.h"

typedef struct Conta tConta;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma conta;
 * 
 * @return tConta* Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados inicializados) de uma conta;
 */
tConta *CriaConta();

/**
 * @brief Lê os dados de uma conta;
 * 
 * @param conta Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (a serem lidas) de uma conta;
 */
void LeConta(tConta *conta);

/**
 * @brief Obtém o valor do saldo em dinheiro de uma conta;
 * 
 * @param conta Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de uma conta;
 * @return float Valor do saldo em dinheiro contido da conta;
 */
float GetSaldoConta(tConta *conta);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) uma conta;
 * 
 * @param conta (Ponteiro para) Tipo genérico de Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de uma conta;
 */
void DestroiConta(DataType conta);

#endif