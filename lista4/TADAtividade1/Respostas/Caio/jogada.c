#include <stdio.h>
#include <stdlib.h>

#include "jogada.h"
#include "tabuleiro.h"

#define VALOR_PADRAO -1

/**
 * @brief Inicializa uma jogada com dados inicializados com valores padrões;
 * 
 * @param jogada Tipo Abstrato de Dados (T.A.D.) que representa a estrutra que possui os dados de uma jogada;
 * @return tJogada Tipo Abstrato de Dados (T.A.D.) que representa a esttrutra que possui os dados de uma jogada inicializada com valores 'padrões';
 */
static tJogada inicializaJogada(tJogada jogada) {
    jogada.x = VALOR_PADRAO;
    jogada.y = VALOR_PADRAO;

    return jogada;
}


tJogada LeJogada() {
    tJogada jogada;

    jogada = inicializaJogada(jogada);
    
    printf("Digite uma posicao (x e y):\n");

    if (scanf("%d %d", &jogada.x, &jogada.y) == 2)
        jogada.sucesso = 1;
    else
        jogada.sucesso = 0;

    return jogada;
}


int ObtemJogadaX(tJogada jogada) {
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada) {
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada) {
    return jogada.sucesso;
}