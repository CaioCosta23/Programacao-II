#include <stdio.h>
#include <stdlib.h>

#include "calculadora.h"

#define ADICAO 'a'
#define SUBTRACAO 's'
#define MULTIPLICACAO 'm'
#define DIVISAO 'd'

#define FINALIZAR 'f'

/**
 * @brief Soma dois números;
 * 
 * @param numero1 Primeiro número, que será somado com o segundo;
 * @param numero2 Segundo número, que será somado com o primeiro;
 * @return float Resultado da soma entre os dois números;
 */
static float soma(float numero1, float numero2) {
    return (numero1 + numero2);
}

/**
 * @brief Subtrai dois números;
 * 
 * @param numero1 Primeiro número, que será subtraído pelo segundo;
 * @param numero2 Segundo número, que irá subtraír o primeiro;
 * @return float Resultado da subtração entre os dois números;
 */
static float subtraao(float numero1, float numero2) {
    return (numero1 - numero2);
}

/**
 * @brief Multiplica dois números;
 * 
 * @param numero1 Primeiro número, que será multiplicado pelo segundo;
 * @param numero2 Segundo número, que será multiplicado com o primeiro;
 * @return float Resultado da multiplicação entre os dois números;
 */
static float multiplicacao(float numero1, float numero2) {
    return (numero1 * numero2);
}

/**
 * @brief Divide dois números;
 * 
 * @param numero1 Primeiro número, que será dividido pelo segundo;
 * @param numero2 Segundo número, que será divisor do primeiro;
 * @return float Resultado da divisão entre os dois números;
 */
static float divisao(float numero1, float numero2) {
    return (numero1 / numero2);
}

/**
 * @brief Programa que realiza operações matemáticas através de ponteiro para funções ('callbacks');
 * 
 * @return int Programa principal;
 */
int main() {
    char opcaoOperacao;
    float numero1, numero2;

    while(1) {
        scanf("%c\n", &opcaoOperacao);

        if (opcaoOperacao == FINALIZAR)
            break;

        scanf("%f %f\n", &numero1, &numero2);

        switch(opcaoOperacao) {
            case ADICAO:
                printf("%.2f + %.2f = %.2f\n", numero1, numero2, Calcular(numero1, numero2, soma));
                break;
            case SUBTRACAO:
                printf("%.2f - %.2f = %.2f\n", numero1, numero2, Calcular(numero1, numero2, subtraao));
                break;
            case MULTIPLICACAO:
                printf("%.2f x %.2f = %.2f\n", numero1, numero2, Calcular(numero1, numero2, multiplicacao));
                break;
            case DIVISAO:
                printf("%.2f / %.2f = %.2f\n", numero1, numero2, Calcular(numero1, numero2, divisao));
                break;
            default:
                break;
        }
    }

    return 0;
}