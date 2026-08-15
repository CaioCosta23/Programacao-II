#include <stdio.h>
#include <stdlib.h>

#include "matrix_utils.h"

void matrix_read(int rows, int cols, int matrix[rows][cols]) {
    int r, c;

    for(r = 0; r < rows; r++) {
        for(c = 0; c < cols; c++) {
            scanf("%d", &matrix[r][c]);
        }
    }
}


int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2) {
    return ((rows1 == rows2) && (cols1 == cols2));
}


int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2) {
    // A mesma verificação para ver se é pssível subtrair uma matriz da outra é feita para saber se é possível somar uma com a outra;
    return possible_matrix_sum(rows1, cols1, rows2, cols2);
}


int possible_matrix_multiply(int cols1, int rows2) {
    // Propriedade necessária para a multiplicação de matrizes;
    return (rows2 == cols1);
}


void matrix_add(int rows1,int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]) {
    int r, c;

    for (r = 0; r < rows1; r++) {
        for(c = 0; c < cols1; c++) {
            result[r][c] = matrix1[r][c] + matrix2[r][c];
        }
    }
}


void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]) {
    int r, c;

    for (r = 0; r < rows1; r++) {
        for(c = 0; c < cols1; c++) {
            result[r][c] = matrix1[r][c] - matrix2[r][c];
        }
    }
}


void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {
    int r1, c2, s;

    /**
     * Calcula-se uma linha da matriz 1 com uma coluna por vez da matriz 2.
     * Em seguida, faz-se o mesmo pocesso para a pŕoxima linha da matriz 1 com todas as colunas da matriz 2;
     * 
     * Lembre-se sempre que enquanto a matriz um varia o elemento da coluna na multiplicação,
     * a matriz 2 varia o elemento da linha;
     */
    for (r1 = 0; r1 < rows1; r1++) {
        for(c2 = 0; c2 < cols2; c2++) {
            result[r1][c2] = 0;

            // Neste caso, poderia usar-se como ponto de parada ou as colunas da matriz 1 ou as linhas da matriz 2 (pois ambas são iguais);
            for (s = 0; s < cols1; s++) {
                result[r1][c2] += matrix1[r1][s] * matrix2[s][c2];
            }
        }
    }
    // A matriz resultante sempre será uma matriz com o número de linhas da primeira e com o número de colunas da segunda
}


void transpose_matrix(int rows ,int cols, int matrix[rows][cols], int result[cols][rows]) {
    int r, c;

    for (r = 0; r < rows; r++) {
        for(c = 0; c < cols; c++) {
            result[c][r] = matrix[r][c];
        }
    }    
}


void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar){
    int r, c;

    for(r = 0; r < rows; r++) {
        for(c = 0; c < cols; c++) {
            matrix[r][c] = matrix[r][c] * scalar;
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]) {
    int r, c;

    for(r = 0; r < rows; r++) {
        printf("|");
        
        for(c = 0; c < cols; c++) {
            if (c < (cols - 1))
                printf("%d ", matrix[r][c]);
            else
                printf("%d", matrix[r][c]);
        }
        printf("|\n");
    }
    printf("\n");
}
