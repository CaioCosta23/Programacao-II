#ifndef _DATA_STRUCTURES_VECTOR_H_
#define _DATA_STRUCTURES_VECTOR_H_

typedef void *data_type; // Ponteiro para tipo "vazio";

typedef struct Vector Vector;

/**
 * @brief Cria (aloca a memória dinamicamente de) um vetor;
 * 
 * @return Vector* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados inicializados) do vetor;
 */
Vector *VectorConstruct();

/**
 * @brief Adicionan um elemento no final do vetor;
 * 
 * @param v Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do vetor;
 * @param val Elemento que será adicionando no vetor;
 */
void VectorPushBack(Vector *v, data_type val);

/**
 * @brief Obtém um dado do vetor;
 * 
 * @param v Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do vetor;
 * @param i Índice (posição) do elemento no vetor;
 * @return data_type Elemento que será obtido, do vetor;
 */
data_type VectorGet(Vector *v, int i);

/**
 * @brief Obtém o tamanho (quantidade de elementos) de um vetor;
 * 
 * @param v Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do vetor;
 * @return int Tamanho (quantidade de dados) do vetor;
 */
int VectorSize(Vector *v);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) um vetor;
 * 
 * @param v Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do vetor;
 * @param destroy Ponteiro para função ('callback') que destruirá (dealocará a memória dinamicamente de) um vetor;
 */
void VectorDestroy(Vector *v, void (*destroy)(data_type));

#endif