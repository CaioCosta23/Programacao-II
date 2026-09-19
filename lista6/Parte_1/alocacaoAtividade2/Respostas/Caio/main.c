#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/**
 * @brief Programa que lê os dados  de uma matriz e impreme-a na tela no seu formato transposto;
 * 
 * @OBS: Tudo usando alocação dinâmica de ponteiros;
 * @return int Programa principal;
 */
int main() {
    unsigned int linhas, colunas;
    int **matriz;

    scanf("%d %d\n", &linhas, &colunas);

    matriz = CriaMatriz(linhas, colunas);
    
    LeMatriz(matriz, linhas, colunas);
    ImprimeMatrizTransposta(matriz, linhas, colunas);
    LiberaMatriz(matriz, linhas);

    return 0;
}