#ifndef _UTILS_CHAR_H_
#define _UTILS_CHAR_H_

/**
 * @brief Cria (aloca dinamicamente as posições de) um vetor; 
 * 
 * @param tamanho Tamanho do vetor/lista/'array';
 * @return char* Ponteiro para o vetor/lista/'array';
 */
char *CriaVetor(int tamanho);

/**
 * @brief Lê os dados de um vetor/lista/'array';
 * 
 * @param vetor Ponteiro para o vetor/lista/array;
 * @param tamanho Tamanho do vetor/lista/'array';
 */
void LeVetor(char *vetor, int tamanho);

/**
 * @brief Imprime uma string (vetor/lista/'array' de caracteres);
 * 
 * @param vetor Ponteiro para o vetor/lista/'array';
 * @param tamanho Tamanho do vetor/lista/'array';
 */
void ImprimeString(char *vetor, int tamanho);

/**
 * @brief Destrói/Libera (desaloca dinamicamente) um vetor;
 * 
 * @param vetor Ponteiro para o vetor/lista/'array';
 */
void LiberaVetor(char *vetor);

#endif