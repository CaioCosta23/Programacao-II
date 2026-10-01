#ifndef __gerpacotes
#define __gerpacotes

#include "pacote.h"

typedef struct gerenciadorpacotes tGerenciador;

/**
 * @brief Cria (aloca a memória dinamicamente de) um gerenciador (de pacotes);
 * 
 * @return tGerenciador* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (inicializados) de um gerenciador pacote;
 */
tGerenciador *CriaGerenciador();

/**
 * @brief Adiciona um pacote na lista/vetor/'array' gerenciador de pacortes;
 * 
 * @param geren Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um gerenciador pacote;
 * @param pac Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um pacote;
 */
void AdicionaPacoteNoGerenciador(tGerenciador *geren, tPacote *pac);

/**
 * @brief Imprime os dados de um pacote que está em uma posição especifica na lista/vetor/'array' de pacotes do gerenciador;
 * 
 * @param geren Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um gerenciador de pacote;
 * @param idx Índice do pacote na lista/vetor/'array' de pacotes do gerenciador;
 */
void ImprimirPacoteBoIndice(tGerenciador *geren, int idx);

/**
 * @brief Imprime todos os pacotes da lista/vetor/'array' de pacotes do gerenciador;
 * 
 * @param geren Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um gerenciador pacote;
 */
void ImprimirTodosPacotes(tGerenciador *geren);

/**
 * @brief Dddddestrói (libera/desaloca dinamicamente a memória de) um gerenciador (de pacotes);
 * 
 * @param geren Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um gerenciador pacote;
 */
void DestroiGerenciado(tGerenciador *geren);

#endif