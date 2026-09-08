#ifndef _VETOR_H_
#define _VETOR_H_

/**
 * @brief Le os dados (elementos) do vetor/lista/'array';
 * 
 * @param vet Ponteiro para o vetor/lista/'array';
 * @param tam Tamanho do vetor/lista/'array';
 */
void LeDadosParaVetor(int *vet, int tam);

/**
 * @brief Troca dois valores de lugar;
 * 
 * @param vet Ponteiro para o vetor/lista/'array';
 * @param tam Tamanho do vetor/lista/'array';
 * @param paraTrocar Ponteiro para o indice do menor valor encontrado vetor/lista/'array';
 */
void TrocaSeAchaMenor(int *vet, int tam, int *paraTrocar);

/**
 * @brief Ordena o vetor/lista/'array' em ordem crescente;
 * 
 * @param vet Ponteiro para vetor/lista/'array';
 * @param tam Tamanho do vetor/lista/'array';
 */
void OrdeneCrescente(int *vet, int tam);

/**
 * @brief Imprime os dados do vetor/lista/'array' na tela;
 * 
 * @param n Ponteiro para o vetor/lista/'array';
 * @param tam Tamanho do vetor/lsita/'array';
 */
void ImprimeDadosDoVetor(int *n, int tam);

#endif