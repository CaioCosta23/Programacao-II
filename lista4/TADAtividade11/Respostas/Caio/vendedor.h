#ifndef _VENDEDOR_H_
#define _VENDEDOR_H_

typedef struct Vendedor {
    char nome[50];
    float valor_vendido, salario, prct_comissao;
}tVendedor;

/**
 * @brief Registra (cria) um vendedor;
 * 
 * @param nome NOme do vendedor
 * @param salario Salário (base) do vendedor;
 * @param prct_comissao Porcentagem de comissão do valor de cada venda a ser recebido pelo vendedor;
 * @return tVendedor Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de um vendedor (com seus dados inicializados);
 */
tVendedor RegistraVendedor(char nome[], float salario, float prct_comissao);

/**
 * @brief Verifica (compara) o nome de um vendedor com outro nome recebido;
 * 
 * @param vendedor Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações (atualizadas) de um vendedor;
 * @param nome Nome que será comparado ao do vendedor;
 * @return int 1 (verdadeiro) se os nomes forem iguais ou 0 (falso), caso contrário
 */
int VerificaNomeVendedor(tVendedor vendedor, char nome[]);

/**
 * @brief Contabiliza uma venda realizada por um vendedor; 
 * 
 * @param vendedor Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações (atualizadas) de um vendedor;
 * @param valor Valor da venda do vendedor;
 * @return tVendedor Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de um vendedor, já com o valor de vendas atualizado com a última venda;
 */
tVendedor ContabilizaVenda(tVendedor vendedor, float valor);

/**
 * @brief Obtém o valor do salário (base) de um vendedor;
 * 
 * @param vendedor Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações (atualizadas) de um vendedor;
 * @return float Valor do salário (base) do vendedor;
 */
float GetSalario(tVendedor vendedor);

/**
 * @brief Obtémm o valor da comissão de uma venda recebida de um vendedor;
 * 
 * @param vendedor Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações (atualizadas) de um vendedor;
 * @return float Valor da comissão e uma venda, recebida pelo vendedor;
 */
float GetComissao(tVendedor vendedor);

/**
 * @brief Obtém o valor total vendido por um vendedor;
 * 
 * @param vendedor Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações (atualizadas) de um vendedor;
 * @return float Valor total vendido pelo vendedor;;
 */
float GetTotalVendido(tVendedor vendedor);

/**
 * @brief Obtém o vvalor total recebido por um vededor, referente a vlor do seu salário junto a comissão(ões) de venda(s) feitas pelo mesmo;
 * 
 * @param vendedor Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações (atualizadas) de um vendedor;
 * @return float Valor total recebido pelo vendedor (em salários e comissões);
 */
float GetTotalRecebido(tVendedor vendedor);

/**
 * @brief Imprime os dados de um vendedor;
 * 
 * @param vendedor Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações (atualizadas) de um vendedor;
 */
void ImprimeRelatorioVendedor(tVendedor vendedor);

#endif