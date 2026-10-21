#ifndef _tarefamultiplica
#define _tarefamultiplica

typedef struct mult tMult;

/**
 * @brief Cria (aloca a memória dinamicamente para) uma tarefa de multiplicação;
 * 
 * @param n1 Primeiro número, que será multiplicado com o segundo;
 * @param n2 Segundo nnúmero, que será multiplicado com o primeiro;
 * @return tMult* Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (inicialzados) de uma tarefa de multiplicação;
 */
tMult *CriaTarefaMultiplicar(float n1, float n2);

/**
 * @brief Executa a multiplicação de dois números;
 * 
 * @param muil Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualzados) de uma tarefa de multiplicação;
 */
void ExecutaTarefaMultiplicar(void *mult);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) uma multiplicação;
 * 
 * @param mult Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualzados) de uma tarefa de multiplicação;
 */
void DestroiTarefaMultiplicar(void *mult);

#endif