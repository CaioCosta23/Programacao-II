#ifndef _LOCADORA_H
#define _LOCADORA_H

#include "filme.h"

typedef struct Locadora tLocadora;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma locadora;
 * 
 * @return tLocadora* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma locadora (inicializada);
 */
tLocadora *CriarLocadora();

/**
 * @brief Cadastra um filme na locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma locadora (atualizada);
 * @param filme Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de um filme (atualizado);
 */
void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme);

/**
 * @brief Lê os dados para cadastro de um filme e o cadastra na locadora;
 * 
 * @param Locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (a serem lidos) de uma locadora;
 */
void LerCadastroLocadora(tLocadora *Locadora);

/**
 * @brief Aluga o(s) filme(s) de uma locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma locadora (atualizada);
 * @param codigos Lista/vetor/'array' de códigos que identificam cada filme a ser alugado;
 * @param quantidadeCodigos Quantidade de códigos de filmes que serão alugados;
 */
void AlugarFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos);

/**
 * @brief Lê os dados necessarios para alugar um (ou mais) filme(s) de uma locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma locadora (atualizada);
 */
void LerAluguelLocadora(tLocadora *locadora);

/**
 * @brief Devolve filmes à locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma locadora (atualizada);
 * @param codigos Lista/vetor/'array' de códigos que identificam cada filme a ser devolvido;
 * @param quantidadeCodigos Quantidade de códigos de filmes que serão devolvidos;
 */
void DevolverFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos);

/**
 * @brief Lê os dados referentes à devolução de um filme a locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma locadora (atualizada);
 */
void LerDevolucaoLocadora(tLocadora *locadora);

/**
 * @brief Consulta o estoque de filmes de uma locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma locadora (atualizada);
 */
void ConsultarEstoqueLocadora(tLocadora *locadora);

/**
 * @brief Consulta/verifia o lucro obtido por uma locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma locadora (atualizada);
 */
void ConsultarLucroLocadora(tLocadora *locadora);

/**
 * @brief Verifica se um filme está cadastrado na locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma locadora (atualizada);
 * @param codigo Código do filme que será verificado se está cadastrado ou não na locadora;
 * @return int 1 (verdadeiro) se o código for iguaal ao de um dos filmes cadastrados na locadora ou 0 (falso), caso contrário;
 */
int VerificarFilmeCadastrado(tLocadora *locadora, int codigo);

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma locadora (atualizada);
 */
void OrdenarFilmesLocadora(tLocadora *locadora);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) uma locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados de uma locadora (atualizada);
 */
void DestruirLocadora(tLocadora *locadora);

#endif