#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void LeIntervalo(int *m, int *n) {
    scanf("%d %d\n", m, n);
}

int EhPrimo(int n) {
    int p;
    int quantidadeDivisores = 0;

    for(p = 1; p <= n; p++) {
        if (n % p == 0)
            quantidadeDivisores += 1;
    }

    return (quantidadeDivisores == 2);
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    int p;

    *maior = m;
    *menor = m;

    for(p = m; p <= n; p++) {
        if (EhPrimo(p)) {
            if (p > *maior)
                *maior = p;
            
            if (p < *menor)
                *menor = p;
        }
    }
}