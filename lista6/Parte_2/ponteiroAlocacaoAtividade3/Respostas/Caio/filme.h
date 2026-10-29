#ifndef _FILME_H
#define _FILME_H

#define MAX_CARACTERES 20

typedef struct Filme {
    int codigo, qtdEstoque, qtdAlugada, valor;
    char nome[MAX_CARACTERES];
}tFilme;

/**
 * @brief Cria (aloca a memória dinamicamente de) um filme;
 * 
 * @return tFilme* Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados inicializados) de um filme;
 */
tFilme *CriaFilme();

/**
 * @brief Lê as informações (dados) de um filme;
 * 
 * @param filme Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados a serem lidos) de um filme;
 */
void LeFilme(tFilme *filme);

/**
 * @brief Obtém o código de um filme;
 * 
 * @param filme Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um filme;
 * @return int Código do filme;
 */
int ObterCodigoFilme(tFilme *filme);

/**
 * @brief Obtém a quantidade em estoque de um filme em específico;
 * 
 * @param filmePonteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um filme; 
 * @return int Quantidade em estoque de um filme específico;
 */
int ObterQtdEstoqueFilme(tFilme *filme);

/**
 * @brief Obtém a quantidade de unidade alugadas de um filme em específico;
 * 
 * @param filme Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um filme;
 * @return int Quantidade de unidades alugadas de um filme em específico;
 */
int ObterQtdAlugada(tFilme *filme);

/**
 * @brief Obtém o valor de um filme;
 * 
 * @param filme Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um filme;
 * @return int Valor de um filme;
 */
int ObterValorFilme(tFilme *filme);

/**
 * @brief Verifica se o número (que representa um código) é igual ao número do código do filme;
 * 
 * @param filme Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um filme;
 * @param codigo Código que será comparado com o número do código do filme;
 * @return int 1 (verdadeiro) caso o número que representa um código de filme seja igual ao número do código do filme ou 0 (falso), caso contrário;
 */
int EhMesmoCodigoFilme(tFilme *filme, int codigo);

/**
 * @brief Compara o nome de dois filmes;
 * 
 * @param filme1 Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do primeiro filme que terá seu nome comparado com o nome do segundo filme;
 * @param filme2 Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do segundo filme que terá seu nome comparado com o nome do primeiro filme;
 * @return int 1 caso o nome do primeiro filme seja maior (venha depois em ordem alfabética) que o segundo, -1 caso o nome do segundo filme seja maior (venha depois em ordem alfabética) que o do primeiro ou 0 caso os nomes sejam iguais;
 */
int ComparaNomesFilmes(tFilme *filme1, tFilme *filme2);

/**
 * @brief Aluga uma unidade de um filme;
 * 
 * @param filme Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um filme;
 */
void AlugarFilme(tFilme *filme);

/**
 * @brief Devolve uma unidade de um filme que estava alugado;
 * 
 * @param filme Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um filme;
 */
void DevolverFilme(tFilme *filme);

/**
 * @brief Imprime o nome do filme;
 * 
 * @param filme Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um filme;
 */
void ImprimirNomeFilme(tFilme *filme);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) um filme;
 * 
 * @param filme Ponteiro para o tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de um filme;
 */
void DestruirFilme(tFilme *filme);

#endif