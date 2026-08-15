// Bibliotecas "<stdio.h>" e "<stdlib.h>" já incluidas na biblioteca de utilidades de matrizes;
#include "matrix_utils.h"

void imprimeMenu() {
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar programa\n");
    printf("Opcao escolhida: ");
}

int main() {
    // Variável lógica (verdadeiro = 1, falso = 0);
    unsigned short int opcao;
    const unsigned short int SOMA = 1, SUBTRACAO = 2, MULTIPLICACAO = 3,
                             MULTIPLICACAO_ESCALAR = 4, TRANSPOSTA = 5, ENCERRAR = 6;
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

    do {
        imprimeMenu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case SOMA:
                if (possible_matrix_sum(linhas1, colunas1, linhas2, colunas2)){
                    matrix_add(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizResultante);
                    matrix_print(linhas1, colunas1, matrizResultante);
                }else {
                    printf("ERRO! Nao foi possivel realizar a adicao de matrizes.");
                }
                break;

            case SUBTRACAO:
                if (possible_matrix_sub(linhas1, colunas1, linhas2, colunas2)){
                    matrix_sub(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizResultante);
                    matrix_print(linhas1, colunas1, matrizResultante);
                }else {
                    printf("ERRO! Nao foi possivel realizar a subtracao de matrizes.");
                }
                break;

            case MULTIPLICACAO:
                if (possible_matrix_multiply(colunas1, linhas2)){
                    matrix_sub(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizResultante);
                    matrix_print(linhas1, colunas1, matrizResultante);
                }else {
                    printf("ERRO! Nao foi possivel realizar a multiplicacao de matrizes.");
                }
                break;

            case MULTIPLICACAO_ESCALAR:
                const unsigned short int OPCAO_MATRIZ_1 = 1, OPCAO_MATRIZ_2 = 2;
                unsigned short int opcaoMatriz;
                int escalar;

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
                const unsigned short int OPCAO_MATRIZ_1 = 1, OPCAO_MATRIZ_2 = 2;
                unsigned short int opcaoMatriz;

                scanf("%hd", &opcaoMatriz);

                if (opcaoMatriz == OPCAO_MATRIZ_1){
                    transpose_matrix(linhas1, colunas1, matriz1, escalar);
                    matrix_print(linhas1, colunas1, matriz1);
                }else if (opcaoMatriz == OPCAO_MATRIZ_2) {
                    transpose_matrix(linhas2, colunas2, matriz2 , escalar);
                    matrix_print(linhas2, colunas2, matriz2);
                }else {
                    printf("ERRO! Nao foi possivel multiplicar a matriz %hd pelo escalar %d.", opcaoMatriz, escalar);
                }
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