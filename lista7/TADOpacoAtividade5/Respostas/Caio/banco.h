#ifndef _BANCO_H_
#define _BANCO_H_

typedef struct Banco tBanco;

/**
 * @brief Cria (aloca a memória dinamicamente de) um banco;
 * 
 * @return tBanco* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados inicializados) de um banco;
 */
tBanco *CriaBanco();

/**
 * @brief Abre uma conta em um banco;
 * 
 * @param banco Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) do banco;
 */
void AbreContaBanco(tBanco *banco);

/**
 * @brief Realiza um saque em uma conta de um banco;
 * 
 * @param banco Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) do banco;
 */
void SaqueContaBanco(tBanco *banco);

/**
 * @brief Realiza o depósito em uma conta de um banco;
 * 
 * @param banco Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) do banco;
 */
void DepositoContaBanco(tBanco *banco);

/**
 * @brief Realiza uma transferência de um valor de uma conta do banco para outra;
 * 
 * @param banco Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) do banco;
 */
void TransferenciaContaBanco(tBanco *banco);

/**
 * @brief Imprime as informações/dados de um banco em forma de um relatório;
 * 
 * @param banco Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) do banco;
 */
void ImprimeRelatorioBanco(tBanco *banco);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) um banco;
 * 
 * @param banco Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) do banco;
 */
void DestroiBanco(tBanco *banco);

#endif