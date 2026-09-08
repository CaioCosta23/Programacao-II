#ifndef _UTILLS_H_
#define _UTILS_H_

/**
 * @brief Lê um intervalo de números inteiros;
 * 
 * @param m Ponteiro para o número do ínicio do intervalo;
 * @param n Ponteiro para o número do fim do intervalo;
 */
void LeIntervalo(int *m, int *n);

/**
 * @brief Verifica se um número é primo;
 * 
 * @param n Número a ser verificado;
 * @return int 1 (verdadeiro) se o número é primo ou 0 (falso), caso contrário;
 */
int EhPrimo(int n);

/**
 * @brief Obtém o maior e o menor número primo do intervalo;
 * 
 * @param m Número que representa o início do intervalo;
 * @param n Número que representa o fim do intervalo;
 * @param menor Ponteiro para a variável que armazenará o menor valor primo do intervalo;
 * @param maior Ponteiro para a variável que armazenará o maior valor primo do intervalo;
 */
void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior);

#endif
