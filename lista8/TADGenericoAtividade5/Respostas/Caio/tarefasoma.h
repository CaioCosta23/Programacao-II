#ifndef _tarefasoma
#define _tarefasoma

typedef struct soma tSoma;

/**
 * @brief Cria (aloca a memória dinamicamente para) uma tarefa de soma;
 * 
 * @param n1 Primeiro número, que será somado com o segundo;
 * @param n2 Segundo nnúmero, que será somado com o primeiro;
 * @return tSoma* Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (inicialzados) de uma tarefa de soma;
 */
tSoma *CriaTarefaSoma(float n1, float n2);

/**
 * @brief Executa a soma de dois números;
 * 
 * @param sum Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualzados) de uma tarefa de soma;
 */
void ExecutaTarefaSoma(void *sum);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) uma soma;
 * 
 * @param sum Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualzados) de uma tarefa de soma;
 */
void DestroiTarefaSoma(void *sum);

#endif