#ifndef _AGENCIA_H_
#define _AGENCIA_H_

#include "conta.h"
#include "vector.h"

typedef struct Agencia tAgencia;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma agência;
 * 
 * @return tAgencia* Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados inicializados) de uma agência;
 */
tAgencia *CriaAgencia();

/**
 * @brief Lêe os dados de uma agência;
 * 
 * @param agencia Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (a serem lidas) de uma agência;
 */
void LeAgencia(tAgencia *agencia);

/**
 * @brief Adiciona uma conta à agência;
 * 
 * @param agencia Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de uma agência;
 * @param conta Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de uma conta;
 */
void AdicionaConta (tAgencia *agencia, tConta *conta);

/**
 * @brief Compara duas agências (pelo número identificador - 'ID') e veriffica se é a mesma agência;
 * 
 * @param numAgencia Número que será comparado com o de uma agência;
 * @param agencia2 Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de uma agência;
 * @return int 1 (verdadeiro) se o número passado como parâmetro for igual ao da agência analisada ou 0 (falso), caso contrário;
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2);

/**
 * @brief Calcula e obtém a média do valor do saldo de todas as contas da agência;
 * 
 * @param agencia Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de uma agência;
 * @return float Média dos valores dos saldos das contas das agências;
 */
float GetSaldoMedioAgencia(tAgencia *agencia);

/**
 * @brief Imprime os dados de uma agência;
 * 
 * @param agencia Ponteiro para Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de uma agência;
 */
void ImprimeDadosAgencia(tAgencia *agencia);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) uma agência;
 * 
 * @param agencia (Ponteiro para) Tipo genérico de Tipo Abstrato de Daados (T.A.D.) que repre4senta a estrutura que contém as informações (dados atualizados) de uma agência;
 */
void DestroiAgencia(DataType agencia);

#endif