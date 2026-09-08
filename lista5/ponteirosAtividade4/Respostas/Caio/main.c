#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/**
 * @brief Programa que lê um 'array'/lista/vetor de números inteiros e procura o maior e o menor valor e calcula a média dos valores;
 * 
 * @return int Programa principal;
 */
int main() {
    int tamanho, maior, menor;
    float media;

    scanf("%d\n", &tamanho);

    int numeros[tamanho];

    LeNumeros(numeros, tamanho);
    EncontraMaiorMenorMedia(numeros, tamanho, &maior, &menor, &media);

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Media dos elementos: %.2f\n", media);

    return 0;
}