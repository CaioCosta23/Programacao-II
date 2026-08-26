#ifndef _CONTA_H_
#define _CONTA_H_

#include "usuario.h"

typedef struct Conta {
    int numero;
    tUsuario user;
    float saldo;
}tConta;

/**
 * @brief Cria uma conta;
 * 
 * @param numero Número que a conta possuirá;
 * @param user Tipo de Dados Abstrato (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um usuário;
 * @return tConta Tipo de Dados Abstrato (T.A.D.) que representa a estrutura que contém os dados de uma conta inicializada;
 */
tConta CriaConta(int numero, tUsuario user);

/**
 * @brief Verfica se a conta existe;
 * 
 * @param conta Tipo de Dados Abstrato (T.A.D.) que representa a estrutura que contém os dados (atualizados) de uma conta;
 * @param numero Número da conta a ser verificada/procurada;
 * @return int 1 (verdadeiro) se a conta existir (o número ser igual ao número da conta) ou 0 (falso), caso contrário;
 */
int VerificaConta(tConta conta, int numero);

/**
 * @brief Saca (retira) um valor da conta;
 * 
 * @param conta Tipo de Dados Abstrato (T.A.D.) que representa a estrutura que contém os dados (atualizados) de uma conta;
 * @param valor  Valor que será sacado da conta;
 * @return tConta Conta com o valor sacado (retirado) da mesma e seus dados atualizados;
 */
tConta SaqueConta(tConta conta, float valor);

/**
 * @brief Deposita um valor na conta;
 * 
 * @param conta Tipo de Dados Abstrato (T.A.D.) que representa a estrutura que contém os dados (atualizados) de uma conta;
 * @param valor Valor que será depositado na conta;
 * @return tConta Conta com o valor depositado e seus dados atualizados;
 */
tConta DepositoConta(tConta conta, float valor);

/**
 * @brief Imprime os dados de uma conta;
 * 
 * @param conta Tipo de Dados Abstrato (T.A.D.) que representa a estrutura que contém os dados (atualizados) de uma conta;
 */
void ImprimeConta(tConta conta);

#endif