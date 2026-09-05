#include <stdio.h>
#include <stdlib.h>

#include "biblioteca.h"

/**
 * @brief Compara duas 'strings' (listas/vetores/'arrays' de caracteres) e verifica se as duas são iguais;
 * 
 * @param origem Primeira 'string' (lista/vetor/'array' de caracteres que será usada na comparação;
 * @param comparado Segunda 'string' (lista/vetor/'array' de caracteres que será usada na comparação; 
 * @return int 1 (verdadeiro) caso as 'strings' (lista/vetor/'array') sejam iguais ou 0 (falso), caso contrário;
 */
static int stringsIguais(char origem[], char comparado[]) {
    unsigned short int iguais = 1; // Variável lógica para representar resultado final de busca/comparação;
    unsigned short int indice = 0;

    while(1) {
        if (origem[indice] != comparado[indice]) {
            iguais = 0;
            break;
        }

        if ((origem[indice] == '\0') || (comparado[indice] == '\0'))
            break;
        
    }
    return iguais;
}

/**
 * @brief Troca a posição de dois livros de uma lista (um com o outro);
 * 
 * @param livros Lista/vetor/'array' de Tipos Abstratos de Dados (T.A.D.s) que representa as estruturas que contém informações (atualizadas) dos livros de uma biblioteca;
 * @param indice1 Índice (na lista/vetor/'array') do primeiro livro ;
 * @param indice2 Índice (na lista/vetor/'array') do segundo livro ;
 */
static void trocaPosicoes(tLivros livros[], int indice1, int indice2) {
    tLivros auxiliar;

    auxiliar = livros[indice1];
    livros[indice1] = livros[indice2];
    livros[indice2] = auxiliar;
}

/**
 * @brief Reordena uma lista de livros baseado na posição de um livro, onde este, é deslocado para a última posição da lista/vetor/'array' de livros da biblioteca;
 * 
 * @param biblioteca Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma biblioteca (com os dados atualizados);
 * @param indiceLivro índice de uma posição de um livro em uma lista/vetor/'array' de livros, na bibloteca;
 * @return tBiblioteca Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma biblioteca (com os dados atualizados e reordenados); 
 */
static tBiblioteca ordenaLivrosBiblioteca(tBiblioteca biblioteca, int indiceLivro) {
    int l;
    
    for(l = indiceLivro; l < (biblioteca.tamanho - 1); l++) {
        trocaPosicoes(biblioteca.livros, l, (l + 1));
    }
    biblioteca.tamanho--;

    return biblioteca;
}


tBiblioteca inicializarBiblioteca() {
    tBiblioteca biblioteca;

    biblioteca.tamanho = 0;

    return biblioteca;
}

/**
 * @brief Adiciona um livro na lista (de livros) da biblioteca;
 * 
 * @param biblioteca Tipo Abstrato de Dados (T.A.D) que representa a estrutura que contém as informações de uma biblioteca (com dados atualizados);
 * @param livro Tipo Abstrato de Dados (T.A.D) que representa a estrutura que contém as informações de um livro (com dados atuaizados);
 * @return tBiblioteca Tipo Abstrato de Dados (T.A.D) que representa a estrutura que contém as informações de uma biblioteca, com o livro já adicionado a lista (de livros) da biblioteca;
 */
tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro) {
    unsigned short int l;

    if (biblioteca.tamanho < MAX_LIVROS){
        unsigned short int jaExiste = 0;

        for(l = 0; l < biblioteca.tamanho; l++) {
            if (verificaTituloDoLivroNaBiblioteca(biblioteca.livros[l], livro.titulo)){
                jaExiste = 1;
                break;
            }
        }

        if (!(jaExiste)) {
            biblioteca.livros[biblioteca.tamanho++] = livro;
            printf("Livro adicionado com sucesso!\n");
        }
    }else {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }

    return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char titulo[]) {
    unsigned short int l;
    unsigned short int achado = 0;

    for (l = 0; l < biblioteca.tamanho; l++) {
        if (verificaTituloDoLivroNaBiblioteca(biblioteca.livros[l], titulo)) {
            achado = 1;
            biblioteca = ordenaLivrosBiblioteca(biblioteca, l);
            biblioteca.tamanho--;
            
            printf("Livro removido com sucesso!\n");
            break;
        }
    }

    if (!(achado))
        printf("Livro nao encontrado na biblioteca.");

    return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char titulo[]){
    return (stringsIguais(livro.titulo, titulo));
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca) {
    unsigned short int l;

    for(l = 0; l < biblioteca.tamanho; l++) {
        imprimeLivro(biblioteca.livros[l]);
    }
}