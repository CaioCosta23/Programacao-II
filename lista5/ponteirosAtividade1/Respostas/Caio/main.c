#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/**
 * @brief Programa que verifica se um número é menor que o outro e troca-os de lugar se for o caso;
 * 
 * @return int Programa principal;
 */
int main() {
    int n1, n2;

    while(scanf("%d %d", &n1, &n2) == 2) {
        if (TrocaInterios(&n1, &n2)) {
            printf("TROCADO: %d %d\n", n1, n2);
        } else {
            printf("ORIGINAL: %d %d\n", n1, n2);
        }
    }

    return 0;
}