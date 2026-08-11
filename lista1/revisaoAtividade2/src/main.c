#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Programa que forma o "triângulo de Floyd";
 * 
 * @return int Programa principal;
 */
int main() {
    int quantidadeNumeros, l, n;
    int numero = 1;

    scanf("%d", &quantidadeNumeros);

    for(l = 1; l <= quantidadeNumeros; l++) {
        for(n = 1; n <= l; n++) {
            printf("%d ", numero);
            numero++;
        }
        printf("\n");
    }
    return 0;
}