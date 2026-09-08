#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/**
 * @brief Programa que lê o número de intervalos e dois valores representando o início e o fim de um intervalo (respectivamente),
 * verifica quais números desse intervalo são inteiros e imprime o maior e o menor número primo do intervalo;
 * 
 * @return int Programa principal;
 */
int main(){
    int casos;

    scanf("%d\n", &casos);

    while(casos) {
        int m, n, menor, maior;

        LeIntervalo(&m, &n);

        ObtemMaiorEMenorPrimo(m, n, &menor, &maior);

        printf("%d %d\n", menor, maior);

        casos--;
    }

    return 0;
}