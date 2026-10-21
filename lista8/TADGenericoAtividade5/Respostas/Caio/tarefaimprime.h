#ifndef _tarefaimprime
#define _tarefaimprime

typedef struct impr tImpr;

/**
 * @brief Cria (aloca a memória dinamicamente para) uma tarefa de impressão;
 * 
 * @param msg (Ponteiro) Lista/Vetor/'Array' de caracteres a ser impresso na tela;

 * @return tMult* Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (inicialzados) de uma tarefa de impressão;
 */
tImpr *CriaTarefaImprimir(char *msg);

/**
 * @brief Executa a impressão de uma mensagem na tela;
 * 
 * @param imp Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualzados) de uma tarefa de impressão;
 */
void ExecutaTarefaImprimir(void *imp);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) uma impressão;
 * 
 * @param imp Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualzados) de uma tarefa de impressão;
 */
void DestroiTarefaImprimir(void *imp);

#endif