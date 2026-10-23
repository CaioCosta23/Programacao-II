#ifndef _CONTA_H_
#define _CONTA_H_

typedef struct Conta tConta;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma conta;
 * 
 * @return tConta* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados inicializados) de uma conta;
 */
tConta *CriaConta();

/**
 * @brief Lê as informações/dados de uma conta;
 * 
 * @param conta Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados à serem lidos) de uma conta;
 */
void LeConta(tConta *conta);

/**
 * @brief Compara um número com o ID (identificador) da conta e verifica se os dois são iguais;
 * 
 * @param conta Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) da conta;
 * @param numero Número que será comparado com o ID (identificador) da conta;
 * @return int 1 (veradeiro) se o número e o ID (identificador) da conta forem iguais ou 0 (falso), caso contrário;
 */
int VerificaConta(tConta *conta, int numero);

/**
 * @brief Realiza o saque de um valor de uma conta;
 * 
 * @param conta Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) da conta;
 * @param valor Valor que será sacado (retirado) da conta;
 */
void SaqueConta(tConta *conta, float valor);

/**
 * @brief Deposita (adiciona) um determinado valor em uma conta;
 * 
 * @param conta Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) da conta;
 * @param valor Valor à ser depoistado (adicionado) na conta;
 */
void DepositoConta(tConta *conta, float valor);

/**
 * @brief Realiza uma transferência de um valor de uma conta para outra;
 * 
 * @param destino Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) da conta de destino de onde o dinheiro sairá;
 * @param origem Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) da conta no qual receberá o valor da transferência;
 * @param valor Valor que será transferido de uma conta para outra;
 */
void TransferenciaConta(tConta *destino, tConta *origem, float valor);

/**
 * @brief Imprime as informações/dados de uma conta;
 * 
 * @param conta Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) da conta;
 */
void ImprimeConta(tConta *conta);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) uma conta;
 * 
 * @param conta Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) da conta;
 */
void DestroiConta(tConta *conta);

#endif