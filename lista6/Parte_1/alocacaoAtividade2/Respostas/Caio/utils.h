#ifndef _UTILS_H_
#define _UTILS_H_

/**
 * @brief Cria (aloca dinâmicamente as posições de) uma matriz;
 * 
 * @param linhas Número de linhas da martiz;
 * @param colunas Número de colunas da matriz;
 * @return int** Ponteiro para um ponteiro que guarda os dados dos elementos da matriz;
 */
int **CriaMatriz(int linhas, int colunas);

/**
 * @brief Lê os dados de uma matriz;
 * 
 * @param matriz Ponteiro para um ponteiro que contém os dados da matriz (de forma contígua, com um vetor - de vetores);
 * @param linhas Número de linhas da matriz;
 * @param colunas Numero de colunas da matriz;
 */
void LeMatriz(int **matriz, int linhas, int colunas);

/**
 * @brief Imprime a trasnposta de uma matriz;
 * 
 * @param matriz Ponteiro para um ponteiro que contém os dados da matriz (de forma contígua, com um vetor - de vetores);
 * @param linhas Número de linhas da matriz;
 * @param colunas Numero de colunas da matriz;
 */
void imprimeMatrizTransposta(int **matriz, int linhas, int colunas);

/**
 * @brief Destrói/Libera (a memória dinâmicamente da) matriz; 
 * 
 * @param matriz Ponteiro para um ponteiro que contém os dados da matriz (de forma contígua, com um vetor - de vetores);
 * @param linhas Número de linhas da matriz;
 */
void LiberaMatriz(int **matriz, int linhas);

#endif