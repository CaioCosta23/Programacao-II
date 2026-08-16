#include <stdio.h>
#include <stdlib.h>

#include "matrix_utils.h"

#define SOMA 1
#define SUBTRACAO 2
#define MULTIPLICACAO 3
#define MULTIPLICACAO_ESCALAR 4
#define TRANSPOSTA 5
#define ENCERRAR 6

void imprimeMenu() {
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");
}


/**
 * @brief Programa que Calcula: A soma, e/ou subtração, e/ou multiĺicação de duas matrizes, e/ou as traspostas das matrizes
 * e a multiplicação de uma das matrizes passadas, por um escalar. Devem ser feitas as verificações se é possível ou não realizar
 * as operações e informar caso não seja possível;
 * 
 * @OBS: Verificar os casos de testes para mais detalhes;
 * 
 * @return int Programa Principal;
 */
int main() {
    // Variável lógica (verdadeiro = 1, falso = 0);
    unsigned short int opcao;
    const unsigned short int OPCAO_MATRIZ_1 = 1, OPCAO_MATRIZ_2 = 2;
    const unsigned short int  FALSO = 0, VERDADEIRO = 1;
    unsigned short int parada = FALSO;
    int linhas1, colunas1, linhas2, colunas2;

    scanf("%d %d", &linhas1, &colunas1);

    int matriz1[linhas1][colunas1];
    
    matrix_read(linhas1, colunas1, matriz1);

    scanf("%d %d", &linhas2, &colunas2);

    int matriz2[linhas2][colunas2];

    matrix_read(linhas2, colunas2, matriz2);

    // A declaração teve de ser feita neste local devido ao fato da estrutura "switch" não aceitar matrizes de tamanho 'variável' dentro da estrutura;
    int matrizResultante[linhas1][colunas1];

    int matriz1Transposta[colunas1][linhas1], matriz2Transposta[colunas2][linhas2], matrizMultiplicacao[linhas1][colunas2];

    do {
        imprimeMenu();
        scanf("%hd", &opcao);
        printf("\n");
        
        switch(opcao) {
            case SOMA:
                if (possible_matrix_sum(linhas1, colunas1, linhas2, colunas2)){
                    matrix_add(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizResultante);
                    matrix_print(linhas1, colunas1, matrizResultante);
                }else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;

            case SUBTRACAO:
                if (possible_matrix_sub(linhas1, colunas1, linhas2, colunas2)){
                    matrix_sub(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizResultante);
                    matrix_print(linhas1, colunas1, matrizResultante);
                }else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;

            case MULTIPLICACAO:
                if (possible_matrix_multiply(colunas1, linhas2)){
                    matrix_multiply(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizResultante);
                    matrix_print(linhas1, colunas2, matrizResultante);
                }else {
                    printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
                }
                break;

            case MULTIPLICACAO_ESCALAR:
                int escalar;
                unsigned short int opcaoMatriz;

                scanf("%d %hd", &escalar, &opcaoMatriz);
                
                if (opcaoMatriz == OPCAO_MATRIZ_1){
                    scalar_multiply(linhas1, colunas1, matriz1, escalar);
                    matrix_print(linhas1, colunas1, matriz1);
                }else if (opcaoMatriz == OPCAO_MATRIZ_2) {
                    scalar_multiply(linhas2, colunas2, matriz2, escalar);
                    matrix_print(linhas2, colunas2, matriz2);
                }else {
                    printf("ERRO! Nao foi possivel multiplicar a matriz %hd pelo escalar %d.", opcaoMatriz, escalar);
                }
                break;

            case TRANSPOSTA:
                transpose_matrix(linhas1, colunas1, matriz1, matriz1Transposta);
                matrix_print(colunas1, linhas1, matriz1Transposta);
                transpose_matrix(linhas2, colunas2, matriz2, matriz2Transposta);
                matrix_print(colunas2, linhas2, matriz2Transposta);
                
                break;

            case ENCERRAR:
                parada = VERDADEIRO;
                break;
            default:
                printf("ERRO! Escolha invalida de opcao de operacao!");
                parada = VERDADEIRO;
                break;
        }

    }while(!(parada));

    return 0;
}