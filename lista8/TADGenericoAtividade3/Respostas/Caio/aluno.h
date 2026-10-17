#ifndef _ALUNO_H_
#define _ALUNO_H_

#include "vector.h"

typedef struct Aluno tAluno;

/**
 * @brief Cria (aloca a memória dinamicamente de) um aluno;
 * 
 * @return tAluno* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados inicializados) de um aluno;
 */
tAluno *CriaAluno();

/**
 * @brief Lê as informações (dados) de um aluno;
 * 
 * @param aluno Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um aluno;
 */
void LeAluno(tAluno *aluno);

/**
 * @brief Obtém a informação (dado) de qual é o gênero do aluno;
 * 
 * @param aluno Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um aluno;
 * @return char Caractere que representa o gênero do aluno;
 */
char GetGeneroAluno(tAluno *aluno);

/**
 * @brief Obtém a informação (dado) da nota de um aluno;
 * 
 * @param aluno Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um aluno;
 * @return float Nota do aluno;
 */
float GetNotaAluno(tAluno *aluno);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) um aluno;
 * 
 * @param data_type (Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a) Estrutura que contém as informações (dados atualizados) de um aluno;
 */
void DestroiAluno(data_type aluno);

#endif