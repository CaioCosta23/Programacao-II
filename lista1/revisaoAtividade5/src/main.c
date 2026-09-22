#include <stdio.h>
#include <stdlib.h>

#define VAZIO 0
#define OCUPADOs 1
#define CAMINHO_EXPLORADO 2

#define BAIXO 'B'
#define CIMA 'C'
#define DIREITA 'D'
#define ESQUERDA 'E'

/**
 * @brief Programa que simula um labirinto que sai de uma posição inicial e busca chegar até uma posição final,
 * usando a prioridade de movimentos e espaços vazios ('0's) no mapa/tabuleiro/labirinto;
 * 
 * @return int Programa principal;
 */
int main() {
    unsigned int linhas, colunas, l, c, m;
    int coordenadaXInicial, coordenadaYInicial, coordenadaXFinal, coordenadaYFinal;
    const unsigned short int MAX_CARACTERES = 5;
    char caracteresMovimento[MAX_CARACTERES];
    unsigned short int semSaida; // Variável lógica;

    scanf("%d %d", &linhas, &colunas);

    int tabuleiro[linhas][colunas];

    for(l = 0; l < linhas; l++)
        for(c = 0; c < colunas; c++)
            scanf("%d", &tabuleiro[l][c]);

    scanf("%d %d", &coordenadaXInicial, &coordenadaYInicial);
    scanf("%d %d", &coordenadaXFinal, &coordenadaYFinal);

    coordenadaXInicial = coordenadaXInicial - 1;
    coordenadaYInicial = coordenadaYInicial - 1;
    coordenadaXFinal = coordenadaXFinal - 1;
    coordenadaYFinal = coordenadaYFinal - 1;

    tabuleiro[coordenadaXInicial][coordenadaYInicial] = CAMINHO_EXPLORADO;

    scanf("%5s", caracteresMovimento);

    printf("(%d,%d) ", (coordenadaXInicial + 1), (coordenadaYInicial + 1));

    do {
        semSaida = 1;
        
        // Até MAX_VCARACTERES -1 pelo '\0' no final da lista/vetor/'array' de caracteres (que foi lido como uma 'string');
        for(m = 0; m < (MAX_CARACTERES - 1); m++) {
            if (caracteresMovimento[m] == BAIXO) {
                if ((coordenadaXInicial + 1) < linhas) {
                    if (tabuleiro[coordenadaXInicial + 1][coordenadaYInicial] == VAZIO) {
                        coordenadaXInicial += 1;
                        semSaida = 0;
                        break;
                    }
                }
            }else if (caracteresMovimento[m] == CIMA) {
                if ((coordenadaXInicial - 1) >= 0) {
                    if (tabuleiro[coordenadaXInicial - 1][coordenadaYInicial] == VAZIO) {
                        coordenadaXInicial -= 1;
                        semSaida = 0;
                        break;
                    }
                }
            }else if (caracteresMovimento[m] == DIREITA) {
                if ((coordenadaYInicial + 1) < colunas) {
                    if (tabuleiro[coordenadaXInicial][coordenadaYInicial + 1] == VAZIO) {
                        coordenadaYInicial += 1;
                        semSaida = 0;
                        break;
                    }
                }
            }else if (caracteresMovimento[m] == ESQUERDA){
                if ((coordenadaYInicial - 1) >= 0) {
                    if (tabuleiro[coordenadaXInicial][coordenadaYInicial - 1] == VAZIO) {
                        coordenadaYInicial -= 1;
                        semSaida = 0;
                        break;
                    }
                }
            }else {
                printf("Erro! Movimento nao identificado.\n");
                continue;
            }
        }
        tabuleiro[coordenadaXInicial][coordenadaYInicial] = CAMINHO_EXPLORADO;

        if (semSaida)
            break;
        
        printf("(%d,%d) ", (coordenadaXInicial + 1), (coordenadaYInicial + 1));
    }while((coordenadaXInicial != coordenadaXFinal) || (coordenadaYInicial != coordenadaYFinal));
    
    return 0;
}