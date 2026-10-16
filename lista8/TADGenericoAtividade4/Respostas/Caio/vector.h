#ifndef _DATA_STRUCTURES_VECTOR_H_
#define _DATA_STRUCTURES_VECTOR_H_

typedef void *DataType; // Ponteiro para um tipo vazio;
typedef struct Vector Vector;

/**
 * @brief Cria (aloca a memória dinamicamente para) um vetor vazio;
 * 
 * @return Vector* Ponteiro para Tipo Abstrato de Dados da estrutura que contém as informções (dados inicializados) vetor;
 */
Vector *VectorConstruct();

/**
 * @brief Adiciona um elemento ao final do vetor;
 * 
 * @param v Ponteiro para Tipo Abstrato de Dados da estrutura que contém as informções (dados atualizados) vetor;
 * @param val (Ponteiro para o) Dado que será adicionado no vetor;
 */
void VectorPushBack(Vector *v, DataType val);

/**
 * @brief Obtém um dado do vetor;
 * 
 * @param v Ponteiro para Tipo Abstrato de Dados da estrutura que contém as informções (dados atualizados) vetor;
 * @param i Índice da posição onde está o elemento que será obtido;
 * @return DataType (Ponteiro para o) Dado que será obtido;
 */
DataType VectorGet(Vector *v, int i);

/**
 * @brief Obtém o tamanho do vetor;
 * 
 * @param v Ponteiro para Tipo Abstrato de Dados da estrutura que contém as informções (dados atualizados) vetor;
 * @return int Tamanho do vetor;
 */
int VectorSize(Vector *v);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) um vetor;
 * 
 * @param v Ponteiro para Tipo Abstrato de Dados da estrutura que contém as informções (dados atualizados) vetor;
 * @param destroy Ponteiro para função ("callback") que libera/desaloca dinamicamente a memória do vetor;
 */
void VectorDestroy(Vector *v, void (*destroy)(DataType));

#endif