#include <stdio.h>
#include <stdlib.h>

#include "eleicao.h"

/**
 * @brief Programa que simula uma eleição (para presidente e para governador);
 * 
 * @return int Programa principal;
 */
int main() {
    tEleicao *eleicao;

    eleicao = InicializaEleicao(eleicao);

    RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    ApagaEleicao(eleicao);
    
    return 0;
}