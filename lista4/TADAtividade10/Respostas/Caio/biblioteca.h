#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "livro.h"

#define MAX_LIVROS 10

typedef struct {
    tLivros livros[MAX_LIVROS];
    int tamanho;
}tBiblioteca;

/**
 * @brief Cria/inicializa uma biblioteca;
 * 
 * @return tBiblioteca Tipo Abstrato de Dados (T.A.D) que representa a estrutura que contém os dados de uma biblioteca (inicializada);
 */
tBiblioteca inicializarBiblioteca();

/**
 * @brief Adiciona um livro na lista (de livros) da biblioteca;
 * 
 * @param biblioteca Tipo Abstrato de Dados (T.A.D) que representa a estrutura que contém as informações de uma biblioteca (com dados atualizados);
 * @param livro Tipo Abstrato de Dados (T.A.D) que representa a estrutura que contém as informações de um livro (com dados atuaizados);
 * @return tBiblioteca Tipo Abstrato de Dados (T.A.D) que representa a estrutura que contém as informações de uma biblioteca, com o livro já adicionado a lista (de livros) da biblioteca;
 */
tBiblioteca adicionarLivrosNaBiblioteca(tBiblioteca biblioteca, tLivros livro);

/**
 * @brief  Remove um livro (caso o mesmo exista) da lista (de livros) da biblioteca;
 * 
 * @param biblioteca Tipo Abstrato de Dados (T.A.D) que representa a estrutura que contém as informações de uma biblioteca (com os dados atualizados);
 * @param titulo Título do livro que será removido da biblioteca;
 * @return tBiblioteca Tipo Abstrato de Dados (T.A.D) que representa a estrutura que contém as informações de uma biblioteca com o livro que contém o título citado (caso exista na biblioteca) remoido da lista (de livros);
 */
tBiblioteca removerLivroNaBiblioteca(tBiblioteca biblioteca, char titulo[]);

/**
 * @brief Verifica se um livroé o mesmo que o citado pelo título;
 * 
 * @param livro Tipo Abstrato de Dados (T.A.D) que representa a estrutura que contém as informações de um livro (com os dados atualizados);
 * @param titulo Título do livro que será comparado com o título do outro;
 * @return int 1 (verdadeiro) se o título do livro for igual ao do citado ou 0 (falso) caso contrário;
 */
int verificaTituloDoLivroNaBiblioteca(tLivros livro, char titulo[]);

/**
 * @brief Lista os dados de uma biblioteca;
 * 
 * @param biblioteca Tipo Abstrato de Dados (T.A.D) que representa a estrutura que contém as informações de uma biblioteca (com os dados atualizados);
 */
void listarLivrosDaBiblioteca(tBiblioteca biblioteca);

#endif