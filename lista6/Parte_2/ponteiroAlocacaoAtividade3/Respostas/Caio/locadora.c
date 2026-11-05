#include <stdio.h>
#include <stdlib.h>

#include "locadora.h"

#define QUANTIDADE_INICIAL_FILMES 10

tLocadora *CriarLocadora() {
    tLocadora *locadora = NULL;

    locadora = (tLocadora*)malloc(sizeof(tLocadora));

    if (locadora == NULL) {
        printf("Erro! Alocacao de memoria de locadora mal-sucedida.\n");
        exit(1);
    }

    locadora->filme = NULL;

    locadora->filme = (tFilme**)malloc(QUANTIDADE_INICIAL_FILMES * sizeof(tFilme*));

    if ((*locadora).filme == NULL) {
        printf("Erro! Alocacao de memoria da lista/vetor/'array' de filmes da locadora mal-sucedida.\n");
        DestruirLocadora(locadora);
        exit(1);
    }

    locadora->numFilmes = 0;
    locadora->lucro = 0;

    return locadora;
}

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

int VerificarFilmeCadastrato(tLocadora *locadora, int codigo) {
    unsigned int f;

    for(f = 0; f < (*locadora).filme[f]; f++)
        if (ObterCodigoFilme((*locadora).filme[f]) == codigo)
            return 1;

    return 0;
}

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

void ConsultarEstoqueLocadora(tLocadora *locadora) {
    unsigned int f;

    for(f = 0; f < (*locadora).numFilmes; f++) {
        printf("%d - ", ObterCodigoFilme((*locadora).filme[f]));
        ImprimirNomeFilme((*locadora).filme[f]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme((*locadora).filme[f]));
    }
}

void ConsultarLucroLocadora(tLocadora *locadora) {
    printf("Lucro total R$%d\n", (*locadora).lucro);
}

/**
 * @brief Ordena os filmes de uma locadora em ordem alfabética (crescente);
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) de uma locadora;
 */
void OrdenarFilmesLocadora(tLocadora *locadora);

void DestruirLocadora(tLocadora *locadora) {
    if (locadora != NULL) {
        if ((*locadora).filme != NULL) {
            unsigned int f;

            for(f = 0; f < (*locadora).numFilmes; f++)
                DestruirFilme((*locadora).filme[f]);

            free((*locadora).filme);
        }
        free(locadora);
    }
}