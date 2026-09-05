#ifndef LIVRO_H
#define LIVRO_H

typedef struct {
    char titulo[50], autor[50];
    int anoPublicacao;
}tLivros;

/**
 * @brief Lê os dados de um livro;
 * 
 * @return tLivros Tipo Abstrato de Dados (T.A.D.) que representa uma estrutura que contém os dados de um livro (inicializado, com inforações lidas da entrada);
 */
tLivros lerLivro();

/**
 * @brief Imprime os dados de um livro;
 * 
 * @param livro Tipo Abstrato de Dados (T.A.D.) que representa uma estrutura que contém as informações de um livro (com os dados atualizados);
 */
void imprimeLivro(tLivros livro);

#endif