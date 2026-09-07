#ifndef _LOHA_H_
#define _LOJA_H_

#include "vendedor.h"

#define MAX_VENDEDORES 10

typedef struct Loja {
    int id, totalVendedores;
    float aluguel, lucro;
    tVendedor vendedores[MAX_VENDEDORES];
}tLoja;

/**
 * @brief Abre (cria) uma loja;
 * 
 * @param id ID (Identificador - único) da loja;
 * @param aluguel Valorrr do aluguel pago pela loja;
 * @return tLoja Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de uma loja (com dados inicializados);
 */
tLoja AbreLoja(int id, float aluguel);

/**
 * @brief Verifica se uma loja possui o mesmo ID (Identificador - único) da outra (ou seja, verifica se é a mesma loja);
 * 
 * @param loja Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de uma loja (atualizada);
 * @param id ID (Identificador - único) de uma loja, que será comparado a da outra loja;
 * @return int 1 (verdadeiro) se o ID (identificador - único) da loja é igual ao referenciado;
 */
int VerificaIdLoja(tLoja loja, int id);

/**
 * @brief Registra uma nova venda de um vendedor da loja;
 * 
 * @param loja Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de uma loja (atualizada);
 * @param nome Nome do vendedor no qual será regsitrado a venda;
 * @param valor Valor da venda;
 * @return tLoja Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de uma loja  com as informações da venda adicionadas ao vendedor que a realizou;
 */
tLoja RegistraVenda(tLoja loja, char nome[50], float valor);

/**
 * @brief Registra um vendedor na loja;
 * 
 * @param loja Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de uma loja (atualizada);
 * @param vendedor Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de um vendedor que será adicionando à loja;
 * @return tLoja Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de uma loja com um novo vendedor adicionado a lista/vetor/'array' de vendedores (caso ele não esteja nessa lista/vetor/'array');
 */
tLoja ContrataVendedor(tLoja loja, tVendedor vendedor);

/**
 * @brief Calcula o valor do lucro de uma loja;
 * 
 * @param loja Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de uma loja (atualizada);
 * @return tLoja Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de uma loja com o valor do lucro obtido calculado;
 */
tLoja CalculaLucro(tLoja loja);

/**
 * @brief Imprime os dados de uma loja;
 * 
 * @param loja Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de uma loja (atualizada);
 */
void ImprimeRelatorioLoja(tLoja loja);

#endif