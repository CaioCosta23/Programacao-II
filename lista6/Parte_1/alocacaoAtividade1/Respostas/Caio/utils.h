#ifndef _UTILS_H_
#define _UTILS_H_

/**
 * @brief Cria (aloca dinamicamente) um vetor/lista/'array'
 * 
 * @param tamanho Tamanho do vetor/lista/'array'
 * @return int* Ponteiro para o vetor/lista/'array'
 */
int *CriaVetor(int tamanho);

/**
 * @brief Lê os dados de um vetor/lista/'array';
 * 
 * @param vetor Ponteiro para o vetor/lista/'array';
 * @param tamanho Tamanho do vetor;
 */
void LeVetor(int *vetor, int tamanho);

/**
 * @brief Calcula a média dos valores do vetor/lista/'arraay';
 * 
 * @param vetor Ponteior para o vetor/lista/'array';
 * @param tamanho Tamanho do vetor;
 * @return float Média dos valores do vetor/lista/'array';
 */
float CalculaMedia(int *vetor, int tamanho);

/**
 * @brief Destrói/libera (desaloca dinamicamente) o vetor/lista/'array';
 * 
 * @param vetor Ponteiro para o vetor/lista/'array';
 */
void LiberaVetor(int *vetor);

#endif