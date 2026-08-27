#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#define MAX_MATRIX_SIZE 10

typedef struct Matrix {
    int rows, cols;
    int data[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
}tMatrix;

/**
 * @brief Cria uma (estrutura de dados - Tipo Abstrato de Dados - que representa) uma matriz;
 * 
 * @param rows Número de linhas da matriz;
 * @param cols Número de colunas da matriz;
 * @return tMatrix Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa uma matriz inicializada;
 */
tMatrix MatrixCreate(int rows, int cols);

/**
 * @brief Lê os dados de uma matriz;
 * 
 * @param matrix Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa uma matriz;
 * @return tMatrix Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa uma matriz com seus espaços que representam os elementos todos preenchidos e atualizados;
 */
tMatrix MatrixRead(tMatrix matrix);


/**
 * @brief Verifica se é possível somar uma matriz a outra;
 * 
 * @param matrix1 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a primeira matriz que será verificada;
 * @param matrix2 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a segunda matriz que será verificada;
 * @return int 1 (verdadeiro) caso as matrizes possam ser somadas uma com a outra ou 0 (falso), caso contrário;
 */
int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Verifica se é possível subtrair uma matriz da outra;
 * 
 * @param matrix1 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a primeira matriz que será verificada;
 * @param matrix2 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a segunda matriz que será verificada;
 * @return int 1 (verdadeiro) caso as matrizes possam ser subtraídas uma da outra ou 0 (falso), caso contrário;
 */
int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Verifica se é possível multiplicar uma matriz com a outra;
 * 
 * @param matrix1 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a primeira matriz que será verificada;
 * @param matrix2 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a segunda matriz que será verificada;
 * @return int 1 (verdadeiro) caso as matrizes possam ser multiplicadas uma com a outra ou 0 (falso), caso contrário;
 */
int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Soma uma matriz com a outra;
 * 
 * @param matrix1 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a primeira matriz que será somada com a segunda
 * @param matrix2 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a segunda matriz que será somada com a primeira;
 * @return tMatrix Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa uma matriz resultante da soma de outras duas matrizes;
 */
tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Subtrai uma matriz da outra;
 * 
 * @param matrix1 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a primeira matriz que será subtraída da segunda
 * @param matrix2 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a segunda matriz que será subtraída da primeira;
 * @return tMatrix Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa uma matriz resultante da subtração de outras duas matrizes;
 */
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Multiplica uma matriz com a outra;
 * 
 * @param matrix1 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a primeira matriz que será multiplicada com a segunda;
 * @param matrix2 Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a segunda matriz que será multiĺicada com a primeira;
 * @return tMatrix Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa uma matriz resultante da multiplicação de outras duas matrizes;
 */
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Transpõe uma matriz (o que era linha vira coluna e o que era coluna, vira linha);
 * 
 * @param matrix Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a matriz (com seus dados atualizados) que será transposta;
 * @return tMatrix Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a matriz que será transposta;
 */
tMatrix TransposeMatrix(tMatrix matrix);

/**
 * @brief Multiplica uma matriz (nesse caso, todos os seus elementos) por um valor escalar;
 * 
 * @param matrix Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a matriz com os seus dados atualizados;
 * @param scalar Valor escalar que multiplicará (todos os elementos) a matriz;
 * @return tMatrix Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a matriz (todos os elementos da mesma) multiplicada pelo escalar;
 */
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar);

/**
 * @brief Imprime (os dados de) uma matriz na tela;
 * 
 * @param matrix Tipo Abstrato de Dados (T.A.D.) que contém uma estrutura de dados que representa a matriz com os seus dados atualizados;
 */
void MatrixPrint(tMatrix matrix);

#endif