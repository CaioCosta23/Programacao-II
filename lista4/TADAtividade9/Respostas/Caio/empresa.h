#ifndef _empresa
#define _empresa

#include "funcionario.h"

typedef struct empresa {
    int id, qtdFuncionarios;
    tFuncionario funcionarios[20];
}tEmpresa;

/**
 * @brief Cria uma empresa;
 * 
 * @param id ID (Identificador - único) de uma empresa;
 * @return tEmpresa Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma empresa (com dados inicializados);
 */
tEmpresa criaEmpresa(int id);

/**
 * @brief Lê os dados de uma empresa;
 * 
 * @return tEmpresa Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma empresa que terá seus dados lidos;
 */
tEmpresa leEmpresa();

/**
 * @brief 
 * 
 * @param empresa Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma empresa (com os dados atualizados);
 * @param funcionario Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um funcionário;
 * @return tEmpresa Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma empresa (que contratou/adicionou um funcionário em sua lista);
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario);

/**
 * @brief Imprime todos os dados de uma empresa;
 * 
 * @param empresa Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (atualizadas) de uma empresa;
 */
void imprimeEmpresa(tEmpresa empresa);

#endif