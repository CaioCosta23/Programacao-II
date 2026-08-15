#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

/**
 * @brief Lê dos dados (elementos) de uma matriz;
 * 
 * @param rows Quantidade de linhas da matriz;
 * @param cols Quantidade de colunas da matriz;
 * @param matrix Matriz a ser lida;
 */
void matrix_read(int rows, int cols, int matrix[rows][cols]);

/**
 * @brief Imprime (os dados de) uma matriz;
 * 
 * @param rows Quantidade de linhas da matriz;
 * @param cols Quantidade de colunas da matriz;
 * @param matrix Matriz a ser imprimida;
 */
void matrix_print(int rows, int cols, int matrix[rows][cols]);

/**
 * @brief Verifica se é possível somar uma matriz com outra;
 * 
 * @param rows1 Quantidade de linhas da matriz 1;
 * @param cols1 Quantidade de colunas da matriz 1;
 * @param rows2 Quantidade de linhas da matriz 2;
 * @param cols2 Quantidade de colunas da matriz 2;
 * @return int 1 (verdadeiro) se for possível somar um matriz com outra, ou 0 (falso), caso contrário;
 */
int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2);

/**
 * @brief Verifica se é possível subtrair uma matriz de outra;
 * 
 * @param rows1 Quantidade de linhas da matriz 1;
 * @param cols1 Quantidade de colunas da matriz 1;
 * @param rows2 Quantidade de linhas da matriz 2;
 * @param cols2 Quantidade de colunas da matriz 2;
 * @return int 1 (verdadeiro), se for possível subtrair uma matriz de outra, ou 0 (falso), caso contrário;
 */
int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2);

/**
 * @brief Verifica se é possível multiplicar uma matriz por outra;
 * 
 * @param cols1 Quantidade de colunas da matriz 1;
 * @param rows2 Quantidade de linhas da matriz 2;
 * @return int 1 (verdadeiro) se for possível multiplicar uma matriz com outra, ou 0 (falso), caso contrário;
 */
int possible_matrix_multiply(int cols1, int rows2);

/**
 * @brief Soma uma matriz com outra;
 * 
 * @param rows1 Quantidade de linhas da matriz 1;
 * @param cols1 Quantidade de colunas da matriz 1;
 * @param matrix1 Matriz 1;
 * @param rows2 Quantidade de linhas da matriz 2;
 * @param cols2 Quantidade de colunas da matriz 1;
 * @param matrix2 Matriz 2;
 * @param result Matriz resultado da soma de duas matrizes;
 */
void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]);

/**
 * @brief Subtrai uma matriz de outra;
 * 
 * @param rows1 Quantidade de linhas da matriz 1;
 * @param cols1 Quantidade de colunas da matriz 1;
 * @param matrix1 Matriz 1;
 * @param rows2 Quantidade de linhas da matriz 2;
 * @param cols2 Quantidade de colunas da matriz 2;
 * @param matrix2 Matriz 2;
 * @param result Matriz resultado da subtração de duas matrizes;
 */
void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]);

/**
 * @brief Multiplica uma matriz por outra;
 * 
 * @param rows1 Quantidade de linhas da matriz 1;
 * @param cols1 Quantidade de colunas da matriz 1;
 * @param matrix1 Matriz 1;
 * @param rows2 Quantidade de linhas da matriz 2;
 * @param cols2 Quantidade de colunas da matriz 2;
 * @param matrix2 Matriz 2;
 * @param result Matriz resultado da multiplicação de duas matrizes;
 */
void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2,int matrix2[rows2][cols2], int result[rows1][cols1]);

/**
 * @brief Transforma uma matriz em sua respectiva matriz transposta;
 * 
 * @param rows Quantidade de linhas da matriz;
 * @param cols Quantidade de colunas da matriz;
 * @param matrix Matriz a ser transposta;
 * @param result Matriz transposta;
 */
void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]);

/**
 * @brief Multiplica uma matriz (nesse caso, todos os seus elementos) por um 'escalar' (valor constante);
 * 
 * @param rows Quantidade de linhas da matriz;
 * @param cols Quantidade de colunas da matriz;
 * @param matrix Matriz que será multiplicada (neste caso, todos os seus elementos);
 * @param scalar Escalar (valor constante) pelo qual será multiplicada a matriz (seus elementos);
 */
void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar);

#endif