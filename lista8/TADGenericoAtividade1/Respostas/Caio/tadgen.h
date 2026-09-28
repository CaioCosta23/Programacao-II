#ifndef _tadgen
#define _tadgen

typedef enum {
    FLOAT = 0,
    INT = 1
}Type;

typedef struct generic tGeneric;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma estrutura com tipo genérico (não definidos/específicos);
 * 
 * @param type Tipo a ser definido na estrutura genérica;
 * @param numElem Número de elementos da estrutura genérica;
 * @return tGeneric* (Ponteiro para) Vetor/lista/'array' de um Tipo Abstrato de Dados (T.A.D.) que represneta a estrutura que contém as informações (inicializados) de um a estrutura com dados genéericos (não definidos/específicos);
 */
tGeneric *CriaGenerico (Type type, int numElem);

/**
 * @brief Lê os dados de uma estrutura genérica (não definida/específica);
 * 
 * @param gen (Ponteiro para) Vetor/lista/'array' de um Tipo Abstrato de Dados (T.A.D.) que represneta a estrutura que contém as informações (atualizados) de um a estrutura com dados genéericos (não definidos/específicos);
 */
void LeGenerico(tGeneric *gen);

/**
 * @brief Imprime os dados de uma estrutura 
 * 
 * @param gen (Ponteiro para) Vetor/lista/'array' de um Tipo Abstrato de Dados (T.A.D.) que represneta a estrutura que contém as informações (atualizados) de um a estrutura com dados genéericos (não definidos/específicos);
 */
void ImprimeGenerico(tGeneric *gen);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) uma estrutura genérica (não definida/específica);
 * 
 * @param gen (Ponteiro para) Vetor/lista/'array' de um Tipo Abstrato de Dados (T.A.D.) que represneta a estrutura que contém as informações (atualizados) de um a estrutura com dados genéericos (não definidos/específicos);
 */
void DestroiGenerico(tGeneric *gen);

#endif