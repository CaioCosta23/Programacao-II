#ifndef _funcionario
#define _funcionario

typedef struct funcionario {
    int id;
    float salario;
}tFuncionario;

/**
 * @brief Cria um funcionário com seus dados inicializados;
 * 
 * @param id ID (Identificador - único) do funcionário;
 * @param salario Salário de um funcionário;
 * @return tFuncionario Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui as informações de um funcionário (com os dados inicializados);
 */
tFuncionario criaFuncionario(int id, float salario);

/**
 * @brief Lê os dados de um funcionário;
 * 
 * @return tFuncionario Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui as informações de um funcionário que teve seus dados lidos;
 */
tFuncionario leFuncionario();

/**
 * @brief Obtém o ID (Identificador - único) de um funcionário;
 * 
 * @param funcionario Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui as informações de um funcionário;
 */
int getIdFuncionário(tFuncionario funcionario);

/**
 * @brief Imprime todos os dados de um funcionário;
 * 
 * @param funcionario Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que possui as informações de um funcionário;
 */
void imprimeFuncionario(tFuncionario funcionario);

#endif