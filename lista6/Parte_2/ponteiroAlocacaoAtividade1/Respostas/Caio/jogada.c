#include <stdio.h>
#include <stdlib.h>

#include "jogada.h"

tJogada *CriaJogada() {
    tJogada *jogada = NULL;
    const short int INICIALIZACAO_DADOS = -1;

    jogada = (tJogada*)malloc(sizeof(tJogada));

    if (jogada == NULL) {
        printf("Erro! Alocacaoo de memoria de jogada mal-sucedida.\n");
        exit(1);
    }
    jogada->x = INICIALIZACAO_DADOS;
    jogada->y = INICIALIZACAO_DADOS;
    jogada->sucesso = INICIALIZACAO_DADOS;

    return jogada;;
}

void LeJogada(tJogada *jogada) {
    if (scanf("%d %d\n", &jogada->x, &jogada->y) == 2)
        jogada->sucesso = 1;
    else
        jogada->sucesso = 0;
}

int ObtemJogadaX(tJogada *jogada) {
    return (*jogada).x;
}

int ObtemJogadaY(tJogada *jogada) {
    return (*jogada).y;
}

int FoiJogadaBemSucedida(tJogada *jogada) {
    return (*jogada).sucesso;
}

void DestroiJogada(tJogada *jogada) {
    if (jogada != NULL)
        free(jogada);
}