#ifndef _agendatarefas
#define _agendatarefas

typedef struct agendatarefas tAgendaTarefas;

/**
 * @brief Cria (aloca a memória dinamicamente para) uma agenda de tarefas;
 * 
 * @param Quantidade de tarefas armazenadas na agenda;

 * @return tAgendaTarefas* Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (inicialzados) de uma agenda de tarefas;
 */
tAgendaTarefas *CriaAgendaDeTarefas(int numElem);

/**
 * @brief Adiciona uma tarefa na agenda de tarefas;
 * 
 * @param tar Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualzados) de uma agenda de tarefas;
 * @param prioridade Prioridade da tarefa dentro da agenda de tarefas;
 * @param tarefa Ponteiro (genérico) para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de uma tarefa (soma ou multiplicação ou impressão);
 * @param executa Ponteiro para função ('callback') de execução de uma determinada tarefa;
 * @param destroi  Ponteiro para função ('callback') de destruição (liberação/desalocação da memória dinamicamdente) de uma determinada tarefa;
 */
void CadastrarTarefaNaAgenda(tAgendaTarefas *tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*));

/**
 * @brief Executa as tarefas que setão armaazenadas na agenda de tarefas;
 * 
 * @param tar Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualzados) de uma agenda de tarefas;
 */
void ExecutaTarefasDaAgenda(tAgendaTarefas *tar);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) uma agenda de tarefas;
 * 
 * @param tar Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualzados) de uma agenda de tarefas;
 */
void DestroiAgendaDeTarefas(tAgendaTarefas *tar);

#endif