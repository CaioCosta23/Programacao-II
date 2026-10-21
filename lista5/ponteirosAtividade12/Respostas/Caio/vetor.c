#include <stdio.h>
#include <stdlib.h>

#include "vetor.h"

void LeVetor(Vetor *vetor) {
    unsigned int e;
    unsigned short int ultrapassouLimite = 0; // Variável lógica que verifa se o número de dados é maior que o tamanho limite do vetor;

    scanf("%d", &vetor->tamanhoUtilizado);

    if ((*vetor).tamanhoUtilizado > TAMANHO_MAXIMO) {
        vetor->tamanhoUtilizado  = TAMANHO_MAXIMO;
        ultrapassouLimite = 1;
    }

    for(e = 0; e < (*vetor).tamanhoUtilizado; e++)
        scanf("%d", &vetor->elementos[e]);

    if (ultrapassouLimite){
        scanf("*%[^\n]");
        scanf("%*c");
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op) {
    unsigned int e;
    int resultado;

    resultado = (*vetor).elementos[0];

    for(e = 1; e < (*vetor).tamanhoUtilizado; e++)
        resultado = operacao(resultado, (*vetor).elementos[e]);
    
    return resultado;
}