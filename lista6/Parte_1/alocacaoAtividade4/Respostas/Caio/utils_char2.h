#ifndef _UTILS_CHAR_H_
#define _UTILS_CHAR_H_

#define TAM_PADRAO 10

/**
 * @brief Cria (Aloca dinamicamente as posições de) um vetor de caracteres;
 * 
 * @return char* Ponteiro para o vetor/lista/'array' criado com tamanho padrão (alocado dinâmicamente);
 */
char *CriaVetorTamPadrao();

/**
 * @brief Aumenta (Realoca dinamicamente - na memória) o tamanho do vetor;
 * 
 * @param vetor Ponteiro para o vetor/lista/'array' de caracteres;
 * @param tamanho Tamanho do vetor/lista/'array';
 * @return char* Ponteiro para o vetor/lista/'array' com o tamanho aumentado (realocado dinamicamente - na memória);
 * @OBS: Aumente a memória adicionando o valor de "TAM_PADRAO";
 */
char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo);

/**
 * @brief Lê os dados do vetor/lista/'array' de caracteres;
 * 
 * @param vetor Ponteiro para o vetor/lista/'array' de caracteres;
 * @param tamanho Ponteiro para o amanho do vetor/lista/'array' de caracteres;
 * @return char* Ponteiro para o vetor/lista/array de caracteres, com o mesmo preenchido com os dados lidos;
 */
char *LeVetor(char *vetor, int *tamanho);

/**
 * @brief Imprime o conteúdo de uma 'string' (vetor/lista/'array' de caracteres);
 * 
 * @param vetor Ponteiro para o vetor/lista/'array' de caracteres ('string');
 */
void ImprimeString(char *vetor);

/**
 * @brief Destrói/Libera (desaloca dinamicamente)a memória do vetor/lista/'array';
 * 
 * @param vetor Ponteiro para o vetor/lista/'array';
 */
void LiberaVetor(char *vetor);

#endif