#include <stdio.h>
#include <stdlib.h>

#include "vetor.h"

/**
 * @brief Soma dois valores;
 * 
 * @param numero1 Primeiro número que será usado no cálculo;
 * @param numero2 Segundo número que será usado no cálculo;
 * @return int Resultado da soma entre os dois os números;
 */
int soma(int numero1, int numero2) {
    return (numero1 + numero2);
}

/**
 * @brief Multiplica dois valores;
 * 
 * @param numero1 Primeiro número que será usado no cálculo;
 * @param numero2 Segundo número que será usado no cálculo;
 * @return int Resultado da soma entre os dois os números;
 */
int multiplicacao(int numero1, int numero2) {
    return (numero1 * numero2);
}

/**
 * @brief Programa que aplica operações matemáticas sobre os elementos de um vetor;
 * 
 * @return int Programa principal;
 */
int main() {
    Vetor vetor;

    LeVetor(&vetor);

    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, soma));
    printf("Produto: %d\n", AplicarOperacaoVetor(&vetor, multiplicacao));
    
    return 0;
}