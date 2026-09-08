#include <stdio.h>
#include <stdlib.h>

#include "vetor.h"

/**
 * @brief Programa que lê um vetor e oordena em ordem crescente;
 * 
 * @return int Programa principal;
 */
int main() {
    int casos;

    scanf("%d\n", &casos);

    while(casos) {
        int tam;

        scanf("%d\n", &tam);

        int vet[tam];

        LeDadosParaVetor(vet, tam);
        OrdeneCrescente(vet, tam);
        ImprimeDadosDoVetor(vet, tam);

        casos--;
    }

    return 0;
}