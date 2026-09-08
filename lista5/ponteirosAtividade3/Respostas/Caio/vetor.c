#include <stdio.h>
#include <stdlib.h>

#include "vetor.h"

void LeDadosParaVetor(int *vet, int tam) {
    int v;

    for(v = 0; v < tam; v++) {
        scanf("%d", (vet + v));
    }
}

void TrocaSeAchaMenor(int *vet, int tam, int *paraTrocar) {
    int v, inicio, menor;

    inicio = *paraTrocar;

    for(v = inicio; v < tam; v++) {
        if ((v == inicio) || (*(vet + v) < menor))
            menor = *(vet + v);
            *paraTrocar = v;
    }
}

void OrdeneCrescente(int *vet, int tam) {
    int v, valorAnalisado, auxiliar;

    for(v = 0; v < tam; v++) {
        valorAnalisado = v;
        TrocaSeAchaMenor(vet, tam, valorAnalisado);

        auxiliar = *(vet + v);
        *(vet + v) = *(vet + valorAnalisado);
        *(vet + valorAnalisado) = auxiliar;
    }
}

void ImprimeDadosDoVetor(int *n, int tam) {
    int v;

    for(v = 0; v < tam; v++) {
        printf("%d " , *(n + v));
    }
    printf("\n");
}