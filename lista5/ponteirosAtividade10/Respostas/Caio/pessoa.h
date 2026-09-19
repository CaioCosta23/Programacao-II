#ifndef _PESSOA_H_
#define _PESSOA_H_

typedef struct Pessoa tPessoa;

struct Pessoa {
    char nome[100];
    tPessoa *pai, *mae, *irmao;
};

/**
 * @brief Cria uma pessoa;
 * 
 * @return tPessoa Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma pessoa (com seus dados inicializados);
 */
tPessoa CriaPessoa();

/**
 * @brief Lê as infromações de uma pessoa;
 * 
 * @param pessoa Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma pessoa;
 */
void LePessoa(tPessoa *pessoa);

/**
 * @brief Verifica se a pessoa posusi pai e/ou mãe;
 * 
 * @param pessoa Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma pessoa (com os dados atualizados);
 * @return int 1 (verdadeiro) se a pessoa possui pai e/ou mãe ou 0 (falso), caso contrário;
 */
int VerificaSeTemPaisPessoa(tPessoa *pessoa);

/**
 * @brief Verifica se duas pessoas são irmãos(ãs) (se as duas pessoas tem o mesmo pai e/ou a mesma mãe);
 * 
 * @param pessoa1 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações da primeira pessoa a ser verificada (com os dados atualizados);
 * @param pessoa2 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações da segunda pessoa a ser verificada (com os dados atualizados);
 * @return int 1 (verdadeiro) se as duas pessoas são irmãos(ãs) ou 0 (falso), caso contrário;
 */
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2);

/**
 * @brief Associa o parentesco entre algumas pessoas;
 * 
 * @param pessoas Ponteiro para lista/vetor/'array' de  Tipos Abstratos de Dados (T.A.D.s) que representam as estruturas que contém as informações de pessoas (com os dados atualizados);
 * @param numPessoas Número de pessoas na lista/vetor/'array' de pessoas;
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas);

/**
 * @brief Imprime os dados de uma pessoa;
 * 
 * @param pessoa Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma pessoa (com os dados atualizados);
 */
void ImprimePessoa(tPessoa *pessoa);

#endif