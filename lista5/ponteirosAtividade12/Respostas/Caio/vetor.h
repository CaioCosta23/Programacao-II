#ifndef _VETOR_H_
#define _VETOR_H_

typedef int (*Operation)(int, int); // Renomeação de ponteiro para função ('callback');

#define TAMANHO_MAXIMO 10

typedef struct vetor {
    int elementos[TAMANHO_MAXIMO];
    int tamanhoUtilizado;
}Vetor;

/**
 * @brief Lê os dados de um vetor;
 * 
 * @param vetor Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (a serem lidos) do vetor;
 */
void LeVetor(Vetor *vetor);

/**
 * @brief Aplica uma operação sobre o vetor;
 * 
 * @param vetor Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) do vetor;
 * @param op Ponteiro para a função ('callback') que realizará a operação sobre o vetor;
 * @return int Resultado da operação aplicada ao vetor;
 */
int AplicarOperacaoVetor(Vetor *vetor, Operation op);

#endif;