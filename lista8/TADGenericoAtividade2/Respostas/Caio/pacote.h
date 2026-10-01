#ifndef __pacote
#define __pacote

typedef enum {
    INT = 1,
    CHAR = 0
} Type;

typedef struct pacote tPacote;

/**
 * @brief Cria (aloca a memória dinamicamente de) um pacote;
 * 
 * @param type Tipo do(s) dado(s) do pacote;
 * @param numElem Número de elementos que um pacote possui;
 * @return tPacote* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (inicializados) de um pacote;
 */
tPacote *CriaPacote (Type type, int numElem);

/**
 * @brief Lê os dados de um pacote;
 * 
 * @param pac Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados lidos de um pacote;
 */
void LePacote(tPacote *pac);

/**
 * @brief Calcula a soma dos valores de um pacote;
 * 
 * @param pac Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um pacote;
 */
void CalculaSomaVerificacaoPacote(tPacote *pac);

/**
 * @brief Imprime os dados de um pacote;
 * 
 * @param pac Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um pacote;
 */
void ImprimePacote(tPacote *pac);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) um pacote;
 * 
 * @param pac Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um pacote;
 */
void DestroiPacote(tPacote *pac);

#endif