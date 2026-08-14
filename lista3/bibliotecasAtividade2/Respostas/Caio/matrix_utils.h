#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

/**
 * @brief 
 * 
 * @param rows 
 * @param cols 
 * @param matrix 
 */
void matrix_read(int rows, int cols, int matrix[rows][cols]);

/**
 * @brief 
 * 
 * @param rows 
 * @param cols 
 * @param matrix 
 */
void matrix_print(int rows, int cols, int matrix[rows][cols]);

/**
 * @brief 
 * 
 * @param rows1 
 * @param cols1 
 * @param rows2 
 * @param cols2 
 * @return int 
 */
int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2);

/**
 * @brief 
 * 
 * @param rows1 
 * @param cols1 
 * @param rows2 
 * @param cols2 
 * @return int 
 */
int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2);

/**
 * @brief 
 * 
 * @param cols1 
 * @param rows2 
 * @return int 
 */
int possible_matrix_multiply(int cols1, int rows2);

/**
 * @brief 
 * 
 * @param rows1 
 * @param cols1 
 * @param matrix1 
 * @param rows2 
 * @param cols2 
 * @param matrix2 
 */
void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2]);

/**
 * @brief 
 * 
 * @param rows1 
 * @param cols1 
 * @param matrix1 
 * @param rows2 
 * @param cols2 
 * @param matrix2 
 */
void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2]);

/**
 * @brief 
 * 
 * @param rows1 
 * @param cols1 
 * @param matrix1 
 * @param rows2 
 * @param cols2 
 * @param matrix2 
 */
void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2,int matrix2[rows2][cols2]);

/**
 * @brief 
 * 
 * @param rows 
 * @param cols 
 * @param matrix 
 * @param result 
 */
void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]);

/**
 * @brief 
 * 
 * @param rows 
 * @param cols 
 * @param matrix 
 * @param scalar 
 */
void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar);

#endif