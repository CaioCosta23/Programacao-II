#ifndef _UTILS_H_
#define _UTILS_H_

/**
 * @brief Lê uma sequência de números (inteiros) e os armazena no 'array'/vetor/lista;
 * 
 * @param array Ponteiro para o 'array'/lista/vetor de inteiros;
 * @param tamanho Tamanho do 'array'/lista/vetor;
 */
void LeNumeros(int *array, int tamanho);

/**
 * @brief Encontra o maior e o menor  valor e a média dos valores do 'array'/lista/vetor;
 * 
 * @param array Ponteiro para o 'array'/lista/vetor de inteiros;
 * @param tamanho Taanho do 'array'/lista/vetor;
 * @param maior Ponteiro para o maior valor do 'array'/lsita/vetor;
 * @param menor Ponteiro para o menor valor do 'array'/lista/vetor;
 * @param media Ponteiro para a média dos valores do 'array'/lista/vetor;
 */
void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media);

#endif