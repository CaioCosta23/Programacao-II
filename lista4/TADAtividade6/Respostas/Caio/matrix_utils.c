#include <stdio.h>
#include <stdlib.h>

#include "matrix_utils.h"

tMatrix MatrixCreate(int rows, int cols) {
    int l, c;
    tMatrix matriz;

    matriz.rows = rows;
    matriz.cols = cols;

    for(l = 0; l < matriz.rows; l++) {
        for(c = 0; c < matriz.cols; c++) {
            matriz.data[l][c] = 0;
        }
    }
    return matriz;
}

tMatrix MatrixRead(tMatrix matrix) {
    int l, c;

    for(l = 0; l < matrix.rows; l++) {
        for(c = 0; c < matrix.cols; c++) {
            scanf("%d", &matrix.data[l][c]);
        }
    }
    return matrix;
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2) {
    return ((matrix1.rows == matrix2.rows) && (matrix1.cols == matrix2.cols));
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2) {
    return ((matrix1.rows == matrix2.rows) && (matrix1.cols == matrix2.cols));
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
    return (matrix1.cols == matrix2.rows);
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2) {
    int l, c;
    tMatrix matriz;

    matriz = MatrixCreate(matrix1.rows, matrix2.cols);

    for(l = 0; l < matriz.rows; l++) {
        for(c = 0; c < matriz.cols; c++) {
            matriz.data[l][c] = matrix1.data[l][c] + matrix2.data[l][c];
        }
    }
    return matriz;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2) {
    int l, c;
    tMatrix matriz;

    matriz = MatrixCreate(matrix1.rows, matrix2.cols);

    for(l = 0; l < matriz.rows; l++) {
        for(c = 0; c < matriz.cols; c++) {
            matriz.data[l][c] = matrix1.data[l][c] - matrix2.data[l][c];
        }
    }
    return matriz;
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
    int l, c, lc;
    tMatrix matriz;

    matriz = MatrixCreate(matrix1.rows, matrix2.cols);

    for(l = 0; l < matriz.rows; l++) {
        for(c = 0; c < matriz.cols; c++) {
            for (lc = 0; lc < matrix1.cols; lc++){
                matriz.data[l][c] += matrix1.data[l][lc] * matrix2.data[lc][c];
            }
        }
    }
    return matriz;
}

tMatrix TransposeMatrix(tMatrix matrix) {
    int l, c;
    tMatrix matriz;

    matriz = MatrixCreate(matrix.cols, matrix.rows);

    for(l = 0; l < matriz.rows; l++) {
        for(c = 0; c < matriz.cols; c++) {
            matriz.data[l][c] = matrix.data[c][l];
        }
    }
    return matriz;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar) {
    int l, c;

    for(l = 0; l < matrix.rows; l++) {
        for(c = 0; c < matrix.cols; c++) {
            matrix.data[l][c] *= scalar;
        }
    }
    return matrix;
}

void MatrixPrint(tMatrix matrix) {
    int l, c;

    for(l = 0; l < matrix.rows; l++) {
           printf("|");
        for(c = 0; c < matrix.cols; c++) {
            printf("%d", matrix.data[l][c]);

            if (c < (matrix.cols - 1))
                printf(" ");
        }
        printf("|\n");
    }
    printf("\n");
}