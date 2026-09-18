#ifndef _PESSOA_H_
#define _PESSOA_H_

typedef struct Pessoa tPessoa;

struct Pessoa {
    char nome[100];
    tPessoa *pai, *mae;
};

/**
 * @brief Cria uma pessoa;
 * 
 * @return tPessoa Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma pessoa;
 */
tPessoa CriaPessoa();

/**
 * @brief Lê os dados de uma pessoa;
 * 
 * @param pessoa Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma pessoa (com os dados atualizados);
 */
void LePessoa(tPessoa *pessoa);

/**
 * @brief Verifica se uma pessoa possui ppais (pai e/ou mae);
 * 
 * @param pessoa Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma pessoa (com os dados atualizados);
 * @return int 1 (verdadeiro) se a pessoa possui pai e/ou mãe ou 0 (falso), caso contrário;
 */
int VerificaSeTemPaisPessoa(tPessoa *pessoa);

/**
 * @brief Associa o parentesco de uma pessoa à outra, por meio da leitura de dados da entrada de dados;
 * 
 * @param pessoas Ponteiro para um vetor/lista/'array' de Tipos Abstratos de Dados (T.A.D.s) que representa a estrutura que contém as informações de pessoas (com os dados atualizados);
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas);

/**
 * @brief Imprime as informações de uma pessoa (caso aaaa mesma possui pai e/ou mãe);
 * 
 * @param pessoa Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma pessoa (com os dados atualizados);
 * 
 * @OBS: Verifique também se a pessoa possui irmão e, caso possua, imprima na tela;
 */
void ImprimePessoa(tPessoa *pessoa);

#endif