#include <stdio.h>
#include <stdlib.h>

#include "matrix_utils.h"

#define SOMAR 1
#define SUBTRAIR 2
#define MULTIPLICAR 3
#define MULTIPLICACAO_ESCALAR 4
#define TRANSPOSTA 5
#define ENCERRAR 6

/**
 * @brief Imprime um menu de opções na tela;
 * 
 */
void imprimeMenu() {
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multipĺicar matrizes\n");
    printf("4 - Multiplicação de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");

    printf("Opcao escolhida: ");
}

/**
 * @brief Cria e lê as informações de dusas matrizes e realiza operaçções matemticas entre elas;
 * 
 * @return int Programa principal;
 */
int main() {
    int quantidadeLinhas, quantidadeColunas;
    tMatrix matriz1, matriz2, resultante;
    unsigned short int opcao;
    
    scanf("%d %d\n", &quantidadeLinhas, &quantidadeColunas);

    matriz1 = MatrixCreate(quantidadeLinhas, quantidadeColunas);
    matriz1 = MatrixRead(matriz1);

    scanf("%d %d\n", &quantidadeLinhas, &quantidadeColunas);

    matriz2 = MatrixCreate(quantidadeLinhas, quantidadeColunas);
    matriz2 = MatrixRead(matriz2);
    
    do {
        imprimeMenu();

        scanf("%hd\n", &opcao);

        switch(opcao) {
            case SOMAR:
                if (PossibleMatrixSum(matriz1, matriz2))
                    resultante = MatrixAdd(matriz1, matriz2);
                    MatrixPrint(resultante);
                    break;
            case SUBTRAIR:
                if (PossibleMatrixSub(matriz1, matriz2))
                    resultante = MatrixSub(matriz1, matriz2);
                    MatrixPrint(resultante);
                    break;
            case MULTIPLICAR:
                if (PossibleMatrixMultiply(matriz1, matriz2))
                    resultante = MatrixMultiply(matriz1, matriz2);
                    MatrixPrint(resultante);
                    break;
            case MULTIPLICACAO_ESCALAR:
                int escalar;

                scanf("%d\n", &escalar);
                resultante = MatrixMultiplyByScalar(matriz1, escalar);
                MatrixPrint(resultante);
                break;
            case TRANSPOSTA:
                resultante = TransposeMatrix(matriz1);
                MatrixPrint(resultante);
                break;
            case ENCERRAR:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

    }while((opcao > 0) && (opcao < 6));

    return 0;
}