#ifndef _FILME_H
#define _FILME_H

#define MAX_CARACTERES 20

typedef struct Filme tFilme;

/**
 * @brief Cria (aloca a memória dinâmicamente) um filme;
 * 
 * @return tFilme* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um filme (com seus dados inicializados);
 */
tFilme *CriaFilme();

/**
 * @brief Lê os dados de um filme;
 * 
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um filme (com seus dados atualizados);
 * @param codigo Código do filme;
 */
void LeFilme(tFilme *filme, int codigo);

/**
 * @brief Obtém o código de um filme;
 * 
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um filme (com seus dados atualizados);
 * @return int Código do filme;
 */
int ObterCodigoFilme(tFilme *filme);

/**
 * @brief Obtém o valor do filme;
 * 
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um filme (com seus dados atualizados);
 * @return int Valor do filme;
 */
int ObterValorFilme(tFilme *filme);

/**
 * @brief Obtém a quantidade de um filme em estoque;
 * 
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um filme (com seus dados atualizados);
 * @return int Quantidade em estoque de um filme;
 */
int ObterQtdEstoqueFilme(tFilme *filme);

/**
 * @brief Obtém a quantidade de cópias de um filme que está alugada;
 * 
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um filme (com seus dados atualizados);
 * @return int Quantidade de cópias do filme que está alugada;
 */
int ObtemQtdAlugadaFilme(tFilme *filme);

/**
 * @brief Compara um código ccom o código do filme e verifica se são iguais;
 * 
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um filme (com seus dados atualizados);
 * @param codigo Código a ser comparado com o do filme;
 * @return int 1 (verdadeiro) se o código obtido é o mesmo que o do filme e 0 (falso), caso contrário;
 */
int EhMesmoCodigoFilme(tFilme *filme, int codigo);

/**
 * @brief Aluga um filme;
 * 
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um filme (com seus dados atualizados);
 * @OBS: Consequentemente, o registro de quantidade de cópias do filme que estão alugadas é incrementada e a quuantidade de cópias do filme que existe em estoque é decrementada;
 */
void AlugaFilme(tFilme *filme);

/**
 * @brief Devolve um filme ao estoque;
 * 
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um filme (com seus dados atualizados);
 * @OBS: Consequentemente, o registro de quantidade de cópias do filme que estão alugadas é decrementada e a quuantidade de cópias do filme que existe em estoque é incrementada;
 */
void DevolveFilme(tFilme *filme);

/**
 * @brief 
 * 
 * @param filme1 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações do primeiro filme (com seus dados atualizados);
 * @param filme2 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações do segundo filme (com seus dados atualizados);
 * @return int 1 se o nome do primeiro filme é maior que o segundo (ou vem depois, em ordem alfabética), -1 se o nome do segundo filme for maior (vem depois em ordem alfabética) ou 0, caso os nomes sejam iguais;
 */
int CompararNomesFilmes(tFilme *filme1, tFilme *filme2);

/**
 * @brief Imprime o nome de um filme;
 * 
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um filme (com seus dados atualizados);
 */
void ImprimeNomeFilme(tFilme *filme);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) um filme;
 * 
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um filme (com seus dados atualizados);
 */
void DestruirFilme(tFilme *filme);

#endif