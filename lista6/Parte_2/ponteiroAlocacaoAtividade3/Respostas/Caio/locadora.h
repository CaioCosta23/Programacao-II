#ifndef _LOCADORA_H
#define _LOCADORA_H

#include "filme.h"

typedef struct Locadora {
    tFilme **filme;
    int numFilmes, lucro;
}tLocadora;

/**
 * @brief Cria (aloca dinamicamente a memória de) um filme;
 * 
 * @return tLocadora* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados inicializados) de uma locadora;
 */
tLocadora *CriaLocadora();

/**
 * @brief Lê os dados de uma locadora para cadastrar um filme;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados a serem lidos) de uma locadora;
 */
void LerCadastroLocadora(tLocadora *locadora);

/**
 * @brief Cadastra um filme dentro de uma locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma locadora;
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma filme;
 */
void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme);

/**
 * @brief Verifica se um filme está cadastrado na locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma locadora;
 * @param coodigo Número do código que será procurado na lista de filmes da locadora;
 * @return int 1 (verdadeiro) se o código existir na lista de filmes da locadora ou 0, caso contrário;
 */
int VerificarFilmeCadastrato(tLocadora *locadora, int coodigo);

/**
 * @brief Lê os dados para o registro de um aluguel de filmes;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma locadora;
 */
void LerAluguelLocadora(tLocadora *locadora);

/**
 * @brief Realiza o registro de um aluguel de um ou mais filmes;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma locadora;
 * @param codigos (Ponteiro para) Vetor/Lista/'Array' de códigos de filmes da locadora;
 * @param quantidadeCodigos Quantidade de códigos de filmes que a locadora possui;
 */
void AlugarFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos);

/**
 * @brief Lê os dados para a devolução de filmes para a locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma locadora;
 */
void LerDevolucaoLocadora(tLocadora *locadora);

/**
 * @brief Realiza o registro da devolução de um ou mais filmes para a locadora
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma locadora;
 * @param codigos (Ponteiro) Vetor/Lista/'Array' de códigos de filmes da locadora;
 * @param quantidadeCodigos Quantidade de códigos de filmes que a locadora possui;
 */
void DevolverFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos);

/**
 * @brief Obtém a quantidade de filmes em estoque de uma locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma locadora;
 */
void ConsultarEstoqueLocadora(tLocadora *locadora);

/**
 * @brief Obtém o lucro obtido com o aluguel de filmes em uma locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma locadora;
 */
void ConsultarLucroLocadora(tLocadora *locadora);

/**
 * @brief Ordena os filmes de uma locadora em ordem alfabética;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma locadora;
 */
void OrdenarFilmesLocadora(tLocadora *locadora);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) uma locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma locadora;
 */
void DestruirLocadora(tLocadora *locadora);

#endif